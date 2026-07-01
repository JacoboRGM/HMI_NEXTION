/*
 * hmi.cpp
 *
 *  Created on: Sep 23, 2023
 *      Author: Jacobo Gonzalez
 */
#include <Nextion/HMI_CLASS/hmi.hpp>

//static varible for class HMI
uint8_t HMI::hmi_number=0;
//varibles for FIFO Buffer
FIFO_BUFFER fifoRX;
uint8_t HMI::dataRx;
std::vector<uint8_t> readBuff;

//constructor
HMI::HMI(UART * _hmi_huart) :
		hmi_uart_instance(_hmi_huart){

	hmi_init();
	hmi_number++;

}
//destroyer
HMI::~HMI() {
	// TODO Auto-generated destructor stub
	hmi_number--;
}

void HMI::startRX(void){
	//setup UART IT RX
	//redirect the UART::callbacks for HMI::callbacks
	hmi_uart_instance->set_callbackRX(HMI::RxCpltCallback);
	hmi_uart_instance->set_callbackTX(HMI::TxCpltCallback);
	hmi_uart_instance->start_RX_IT(&dataRx, 1);
}

std::string HMI::change_page(uint8_t page){
	std::string command="page "+std::to_string(page);
	return command;
}

std::string HMI::dims_value(uint8_t value){
	std::string command="dims "+std::to_string(value);
	return command;
}

uint8_t HMI::add_touch_event(uint8_t page, uint8_t id, void (*callback)(uint8_t*)) {
	uint8_t error=0;
	//first check if the page exist on map
	// Create the inner map with the callback
	if (callback != nullptr) {
		std::map<uint8_t, void (*)(uint8_t*)> innerMap = { { id, callback } };
		//create a type iterator for re-search
		std::map<uint8_t, std::map<uint8_t, void (*)(uint8_t*)>>::iterator pageIter =
				callbacksTouchEvent.find(readBuff[1]);
		//if key readBuff[1] is found on the map
		if (pageIter != callbacksTouchEvent.end()) {
			//add the sub map key-pari value
			callbacksTouchEvent[page][id] = callback;
			error=1;
		}
		else {
			//if not, build the map for all instance
			// Create the outer pair with the page and the inner map
			std::pair<uint8_t, std::map<uint8_t, void (*)(uint8_t*)>> pagePair(
					page, std::move(innerMap));
			// Insert the pair using emplace
			callbacksTouchEvent.emplace_hint(callbacksTouchEvent.end(),
					std::move(pagePair));
		}

	}
	else{
		error=2;
	}
	return error;
}

uint8_t HMI::delete_touch_event(uint8_t page, uint8_t id){
	uint8_t error=0;
	//check if the page is inside of the map
	std::map<uint8_t , std::map<uint8_t , void(*)(uint8_t *)>>::iterator pageIter
			= callbacksTouchEvent.find(page);
	//if key readBuff[1] is found on the map
	if(pageIter != callbacksTouchEvent.end()){
		std::map<uint8_t, void (*)(uint8_t*)>::iterator idIter =
				pageIter->second.find(id);
		if (idIter != pageIter->second.end()) {
			callbacksTouchEvent[page].erase(idIter);
		}
		else{
			error=2;
		}
	}
	else{
		//manda error
		error=1;
	}
	return error;
}

void HMI::read_FIFO_input(void){

	uint8_t ptr=1;
	uint8_t read_array[16];
	uint8_t buff[5]={0,1,2,3,4};

	if(!fifoRX.isEmpty()){
		readBuff = fifoRX.pop();
		//here check what comand is recived and process
		switch(readBuff[0])
		{
		//orders from HMI
		case START_UP:
			if(readBuff[1]==0xFF){
				//invalid instruccion
				hmi->flags.instruccion_error = true;
			}
			else{
				hmi->flags.startup=true;
			}
			break;
		case SUCCES_I:
			hmi->flags.instruccion_succes=true;
			break;
		case INVALID_C:
			hmi->flags.invalid_comp_ID=true;
			break;
		case INVALID_P:
			hmi->flags.invalid_page=true;
			break;
		case INVALID_V:
			hmi->flags.invalid_variable=true;
			break;
		case OVERFlOW_S:
			hmi->flags.serialBufferOverflow=true;
			break;
		case TOUCH_E:
		// Explicitly specify iterator types
		{
			std::map<uint8_t, std::map<uint8_t, void (*)(uint8_t *)>>::iterator pageIter = callbacksTouchEvent.find(readBuff[1]);
			if (pageIter != callbacksTouchEvent.end()) {
				std::map<uint8_t, void (*)(uint8_t *)>::iterator idIter = pageIter->second.find(readBuff[2]);
				if (idIter != pageIter->second.end()) {
					idIter->second(buff);
				}
			}
		}
			break;
		case CURRENT_PAGE:
			hmi->page=readBuff[1];
			break;
		case TOUCH_COORD_A:
			hmi->touch_awake.xpos=(readBuff[1]*256 + readBuff[2]);
			hmi->touch_awake.ypos=(readBuff[3]*256 + readBuff[4]);
			hmi->touch_awake.status=readBuff[5];
			break;
		case TOUCH_COORD_S:
			hmi->touch_sleep.xpos=(readBuff[1]*256 + readBuff[2]);
			hmi->touch_sleep.ypos=(readBuff[3]*256 + readBuff[4]);
			hmi->touch_sleep.status=readBuff[5];
			break;
		case RETURN_STRING:

			while(readBuff[ptr] != 0xFF)
				hmi->rx_string+= static_cast<char>(readBuff[ptr++]);
			break;
		case RETURN_NUMBER:

			hmi->read_num_data = (readBuff[4]<<24) +  (readBuff[3]<<16) + (readBuff[2]<<8) + readBuff[1];

			break;
		case AUTO_SLEEP:
			hmi->flags.ae_sleep_mod=true;
			break;
		case AUTO_WAKE:
			hmi->flags.ae_sleep_mod=false;
			break;
		case NEXTION_READY:
			hmi->flags.ready=true;
			break;
		case UPGRADE_SD:
			hmi->flags.upgrade=true;
			break;
		case TRANS_DATA_F:
			hmi->flags.transparent_mod=false;
			break;
		case TRANS_DATA_R:
			hmi->flags.transparent_mod=true;
			break;
		}
	}
}

void HMI::send_command(std::string name, CommandEnum command, int value){
	std::string command_read = getCommand(command);
	std::string build_str = name+"."+command_read+"="+std::to_string(value)+"\xFF\xFF\xFF";
	hmi_uart_instance->write(build_str);
}

void HMI::send_command(std::string name, CommandEnum command, uint16_t value){
	std::string command_read = getCommand(command);
	std::string build_str = name+"."+command_read+"="+std::to_string(value)+"\xFF\xFF\xFF";
	hmi_uart_instance->write(build_str);
}

void HMI::send_command(std::string name, CommandEnum command, std::string value){
	std::string command_read = getCommand(command);
	std::string build_str = name+"."+command_read+"=\x22"+value+"\x22"+"\xFF\xFF\xFF";
	hmi_uart_instance->write(build_str);
}


//re-define interrupt UART::
void HMI::TxCpltCallback(UART_HandleTypeDef *huart){
	/*
	 *
	 * your code for this aplication here
	 */
}

void HMI::RxCpltCallback(UART_HandleTypeDef *huart){

	static volatile uint8_t rxIndex=0, endTransfer=0;
	static volatile bool	init_buffer=false;
	static volatile uint8_t arrayPtr[16];

	if(init_buffer){
		arrayPtr[rxIndex]=dataRx;
		rxIndex++;
		//check for the end of transmision
		if(dataRx==0xFF)
			endTransfer++;
		//if end of transmision is complete
		if((endTransfer==3)||(rxIndex==SIZE_BUFF_HMI_RX)){
			std::vector<uint8_t> rxVector(arrayPtr, arrayPtr+rxIndex);
			fifoRX.push(rxVector);
			endTransfer=0;
			init_buffer=false;
		}
	}
	else{
		if((dataRx==START_UP)  ||(dataRx==SUCCES_I)  ||	(dataRx==INVALID_C)   ||(dataRx==INVALID_P) ||
				(dataRx==INVALID_V) ||(dataRx==OVERFlOW_S)||	(dataRx==CURRENT_PAGE)||(dataRx==POWER_EVSE)||
				(dataRx==SIS_TIME)  ||(dataRx==SIS_DATE)  ||	(dataRx==TIME_LIMIT)  ||(dataRx==TOUCH_E)   ||
				(dataRx==CONFIG_ADV)||(dataRx==CH_PASSWORD)){
			arrayPtr[0]=dataRx;
			rxIndex=1;
			init_buffer=true;
		}
	}
	HAL_UART_Receive_IT(huart, &dataRx,1);

}

void HMI::hmi_init(void){
	//init hmi instance
	hmi->flags.on_rst=false;
	hmi->flags.startup=false;
	hmi->flags.serialBufferOverflow=false;
	hmi->flags.ae_sleep_mod=false;
	hmi->flags.ready=false;
	hmi->flags.upgrade=false;
	hmi->flags.transparent_mod=false;
	hmi->flags.instruccion_error=false;
	hmi->flags.instruccion_succes=false;
	hmi->flags.invalid_comp_ID=false;
	hmi->flags.invalid_page=false;
	hmi->flags.invalid_variable=false;
	//init page
	hmi->page=0;
	hmi->brigth=0;
	hmi->status=0;
	//init touch awake
	hmi->touch_awake.xpos=0;
	hmi->touch_awake.ypos=0;
	hmi->touch_awake.status=0;
	//init touch sleep
	hmi->touch_sleep.xpos=0;
	hmi->touch_sleep.ypos=0;
	hmi->touch_sleep.status=0;
	hmi->rx_string="\0";
	hmi->read_num_data=0;
}





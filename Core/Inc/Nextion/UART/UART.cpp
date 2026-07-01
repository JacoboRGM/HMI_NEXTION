/*
 * UART.cpp
 *
 *  Created on: Sep 23, 2023
 *      Author: Jacobo Gonzalez
 */
#include <Nextion/UART/UART.hpp>
#include "usart.h"

//variable for check the init for instance uart
bool UART::check_init = false;

UART::UART(USART_TypeDef *Instance, UART_HandleTypeDef  * huart):
	_Instance(Instance), _huart(huart){

	check_init=true;
#if USE_HAL_UART_REGISTER_CALLBACKS != 1
#error "USE_HAL_UART_REGISTER_CALLBACKS must be set to 1 in stm32f4xx_hal_config.h"
#endif

}

UART::~UART() {
	// TODO Auto-generated destructor stub
	HAL_UART_DeInit(_huart);
	check_init=false;
}

void UART::setup(void){
	MX_USART1_UART_Init();
	_huart->TxCpltCallback = UART::TxCpltCallback;
	_huart->RxCpltCallback = UART::RxCpltCallback;
}

void UART::write(std::string buff){

	const char * c_str= buff.c_str();
	HAL_UART_Transmit(_huart, (uint8_t*)c_str, buff.length(), 1000);
}

HAL_StatusTypeDef UART::read(uint8_t * read_buff, uint16_t size){

	/*if(!bufferHMI.isEmpty()){
		readBuff= bufferHMI.pop();
		(*ptrRCcallBack)['e']((uint8_t *)readBuff.data());
	}
	*/
	return HAL_UART_Receive(_huart, read_buff, size, 1000);
}

//realloc the default callback RX
void UART::set_callbackRX(void(*rxCallback)(UART_HandleTypeDef *huart)){
	_huart->RxCpltCallback = rxCallback;
}

//realloc the default callback TX
void UART::set_callbackTX(void(*txCallback)(UART_HandleTypeDef *huart)){
	_huart->TxCpltCallback = txCallback;
}

HAL_StatusTypeDef UART::start_RX_IT(uint8_t * rxBuff, uint16_t numberChars){

	return HAL_UART_Receive_IT(_huart, rxBuff, numberChars);
}

//enable TX interrupt
HAL_StatusTypeDef UART::start_TX_IT(uint8_t * rxData, uint16_t size){

	return HAL_UART_Transmit_IT(_huart, rxData, size);
}

void UART::TxCpltCallback(UART_HandleTypeDef *huart){


}


void UART::RxCpltCallback(UART_HandleTypeDef *huart){
	uint8_t data;
	HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
}








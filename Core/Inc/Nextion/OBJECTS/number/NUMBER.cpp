/*
 * NUMBER.cpp
 *
 *  Created on: Nov 24, 2023
 *      Author: jacobo.gonzalez
 */
#include <Nextion/OBJECTS/number/NUMBER.hpp>

uint16_t NUMBER::objectNumber=0;

NUMBER::NUMBER(std::string _name, uint8_t _page, uint8_t _id,
		bool _touch_event, void(*function_callback)(uint8_t * buff) ,
		HMI * _hmi) : COMMON(_name, _hmi){
	// TODO Auto-generated constructor stub

	number.name=_name;
	number.page=_page;
	number.id=_id;
	number.touch_event=_touch_event;
	hmi_instance=_hmi;
	objectNumber++;
	//add the touch even if is active
	if((number.touch_event == true) & (function_callback !=nullptr)){
		//add the event
		hmi_instance->add_touch_event(_page, _id, function_callback);
	}
}

NUMBER::~NUMBER(){
	// TODO Auto-generated destructor stub
	objectNumber--;
	//delete the touch event if exist
	if(number.touch_event){

	}
}

void NUMBER::setFont(uint8_t font){
	number.font=font;
	hmi_instance->send_command(number.name, CommandEnum::font, (uint16_t)font);
}

void NUMBER::setColorNumber(uint16_t value){
	number.color=value;
	hmi_instance->send_command(number.name, CommandEnum::pco, (uint16_t)value);
}

void NUMBER::setColorBackground(uint16_t value){
	number.colorBackground=value;
	hmi_instance->send_command(number.name, CommandEnum::bco, value);
}

void NUMBER::setValue(int value){
	number.value=value;
	hmi_instance->send_command(number.name, CommandEnum::val, value);
}
void NUMBER::setLenth(uint8_t value){
	number.lenth=value;
	hmi_instance->send_command(number.name, CommandEnum::lenth, (uint16_t)value);
}
void NUMBER::setFormat(uint8_t value){
	number.format=value;
	hmi_instance->send_command(number.name, CommandEnum::format, (uint16_t)value);
}
void NUMBER::setIsbr(bool value){
	number.isbr=value;
	hmi_instance->send_command(number.name, CommandEnum::isbr, (uint16_t)value);
}
void NUMBER::set_spax(uint8_t value){
	number.spax=value;
	hmi_instance->send_command(number.name, CommandEnum::spax, (uint16_t)value);
}
void NUMBER::set_spay(uint8_t value){
	number.spay=value;
	hmi_instance->send_command(number.name, CommandEnum::spay, (uint16_t)value);
}



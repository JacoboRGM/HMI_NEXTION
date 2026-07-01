/*
 * toggleButton.cpp
 *
 *  Created on: Nov 26, 2023
 *      Author: jacobo.gonzalez
 */

#include <Nextion/OBJECTS/toggleButton/toggleButton.h>

uint16_t TOGGLE_BUTTON::objectsNumber=0;

TOGGLE_BUTTON::TOGGLE_BUTTON(std::string _name, uint8_t _page, uint8_t _id,
		bool _touch_event, void(*function_callback)(uint8_t * buff) ,
		HMI * _hmi) : BUTTON(_name, _page, _id, _touch_event, function_callback, _hmi){
	// TODO Auto-generated constructor stub
	objectsNumber++;
	name=_name;
	hmi_instance=_hmi;

}

TOGGLE_BUTTON::~TOGGLE_BUTTON() {
	// TODO Auto-generated destructor stub
	objectsNumber--;
}

void TOGGLE_BUTTON::setVal(bool val){
	value=val;
	hmi_instance->send_command(name, CommandEnum::val, (uint16_t)val);

}
bool TOGGLE_BUTTON::getVal(void){
	return value;
}


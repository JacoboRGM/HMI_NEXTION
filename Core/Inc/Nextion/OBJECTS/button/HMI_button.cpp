/*
 * HMI_button.cpp
 *
 *  Created on: Aug 4, 2023
 *      Author: jacobo.gonzalez
 */
#include <string>
#include "HMI_button.hpp"

uint16_t BUTTON::button_numbers=0;

BUTTON::BUTTON(std::string _name, uint8_t _page, uint8_t _id,
		bool _touch_event, void(*function_callback)(uint8_t * buff),
		HMI * _hmi) : COMMON(_name, _hmi){

	button.name=_name;
	button.page=_page;
	button.id=_id;
	touch_event=_touch_event;
	button_numbers++;
	hmi_instance=_hmi;
	//if touch event is active
	if((touch_event == true) & (function_callback != nullptr)){
		//add a function for callback
		hmi_instance->add_touch_event(_page, _id, function_callback);
	}
};

BUTTON::~BUTTON(){
	button_numbers--;
	//delete the callback for map
}

void BUTTON::setText(std::string value){
	button.name=value;
	hmi_instance->send_command(button.name, CommandEnum::txt, value);
}

void BUTTON::setColorText(uint16_t n){
	button.colorText=n;
	hmi_instance->send_command(button.name, CommandEnum::pco, n);
}

void BUTTON::setColorTextPress(uint16_t n){
	button.colorTextPress=n;
	hmi_instance->send_command(button.name, CommandEnum::pco2, n);
}

void BUTTON::setColorBackground(uint16_t n){
	button.colorBackground=n;
	hmi_instance->send_command(button.name, CommandEnum::bco, n);
}

void BUTTON::setColorBackgroundPress(uint16_t n){
	button.colorBackgroundPress=n;
	hmi_instance->send_command(button.name, CommandEnum::bco2, n);
}

void BUTTON::setXcen(uint8_t value){
	hmi_instance->send_command(button.name, CommandEnum::xcen, value);
}

void BUTTON::setYcen(uint8_t value){
	hmi_instance->send_command(button.name, CommandEnum::ycen, value);
}

void BUTTON::setIsbr(bool value){
	hmi_instance->send_command(button.name, CommandEnum::isbr, (uint16_t)value);
}

void BUTTON::setSpax(uint8_t value){
	hmi_instance->send_command(button.name, CommandEnum::spax, value);
}

void BUTTON::setSpay(uint8_t value){
	hmi_instance->send_command(button.name, CommandEnum::spay, value);
}





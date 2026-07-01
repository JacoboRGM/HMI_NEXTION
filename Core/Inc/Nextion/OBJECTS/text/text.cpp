/*
 * text.cpp
 *
 *  Created on: Nov 13, 2023
 *      Author: jacobo.gonzalez
 */
#include <Nextion/OBJECTS/text/text.h>

uint16_t TEXT::textNumbers =0;

TEXT::TEXT(std::string _name, uint8_t _page, uint8_t _id,
		bool _touch_event, void(*function_callback)(uint8_t * buff),
		HMI * _hmi):COMMON(_name, _hmi){
	text.name=_name;
	text.id=_id;
	text.page=_page;
	touchEvent=_touch_event; //check if is necesary put inside of struct
	textNumbers++;
	hmi_instance=_hmi;
	if((touchEvent == true) & (function_callback != nullptr)){
		//add the touch event
		hmi_instance->add_touch_event(_page, _id, function_callback);
	}
	else{
		touchEvent=false;
	}
}

TEXT::TEXT(std::string _name, uint8_t _page, uint8_t _id, HMI * _hmi): COMMON(_name, _hmi){
	text.name = _name;
	text.id = _id;
	text.page = _page;
	touchEvent=false;
	hmi_instance = _hmi;
	textNumbers++;
}

TEXT::~TEXT() {
	uint8_t error;
	textNumbers--;
	//delete callback function on the map
	if(touchEvent){
		error = hmi_instance->delete_touch_event(this->text.page, this->text.id);
	}

}
void TEXT::setText(std::string texto){
	text.text=texto;
	hmi_instance->send_command(text.name, CommandEnum::txt, texto);
}

void TEXT::setColorText(uint16_t color){
	text.color= color;
	hmi_instance->send_command(text.name, CommandEnum::pco, color);
}

void TEXT::setColorBackground(uint16_t colorBackground){
	text.colorBackground=colorBackground;
	hmi_instance->send_command(text.name, CommandEnum::bco, colorBackground);
}

void TEXT::setFont(uint8_t font){
	text.font=font;
	hmi_instance->send_command(text.name, CommandEnum::font, font);
}

void TEXT::setXcen(uint8_t value){
	hmi_instance->send_command(text.name, CommandEnum::xcen, value);
}
void TEXT::setYcen(uint8_t value){
	hmi_instance->send_command(text.name, CommandEnum::ycen, value);
}
void TEXT::setTypePW(bool val){
	hmi_instance->send_command(text.name, CommandEnum::pw, (uint16_t)val);
}
void TEXT::setIsbr(bool val){
	hmi_instance->send_command(text.name, CommandEnum::isbr, (uint16_t)val);
}
void TEXT::setSpax(uint8_t val){
	hmi_instance->send_command(text.name, CommandEnum::spax, val);
}
void TEXT::setSpay(uint8_t val){
	hmi_instance->send_command(text.name, CommandEnum::spay, val);
}


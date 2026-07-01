/*
 * scrolingText.cpp
 *
 *  Created on: Dec 28, 2023
 *      Author: Jacobo Gonzalez
 */

#include <Nextion/OBJECTS/scrollingText/scrollingText.hpp>

uint16_t scrollingText::objectNumber=0;

scrollingText::scrollingText(std::string _name, uint8_t _page, uint8_t _id,
		bool _touch_event, void(*function_callback)(uint8_t * buff),
		HMI * _hmi): TEXT(_name, _page, _id, _touch_event, function_callback, _hmi){
	// TODO Auto-generated constructor stub
	name=_name;
	hmi=_hmi;
	objectNumber++;
}

scrollingText::scrollingText(std::string _name, uint8_t _page, uint8_t _id, HMI * _hmi)
		:TEXT(_name, _page, _id, _hmi){
	name=_name;
	hmi = _hmi;
}

scrollingText::~scrollingText() {
	// TODO Auto-generated destructor stub
	objectNumber--;
}

void scrollingText::enable(bool value){
	this->value=value;
	hmi_instance->send_command(name, CommandEnum::en,value);
}

void scrollingText::setDir(DirType  dir){
	this->currentDir=dir;
	hmi_instance->send_command(name, CommandEnum::dir, (uint16_t)dir);
}

void scrollingText::setDis(uint8_t dis){
	this->dis=dis;
	hmi_instance->send_command(name, CommandEnum::dis, (uint16_t)dis);
}

void scrollingText::setTime(uint8_t time){
	this->time=time;
	hmi_instance->send_command(name, CommandEnum::tim, (uint16_t)time);
}


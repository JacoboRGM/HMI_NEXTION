/*
 * gauge.cpp
 *
 *  Created on: Jan 8, 2024
 *      Author: Jacobo Gonzalez
 */

#include <Nextion/OBJECTS/gauge/gauge.hpp>

uint16_t gauge::objectNumber=0;

gauge::gauge(std::string _name, uint8_t _page, uint8_t _id,
	      bool _touch_event, void(*function_callback)(uint8_t * buff),
		  HMI * _hmi): COMMON(_name, _hmi){

	this->name=_name;
	this->id=_id;
	this->page=_page;
	this->touch_event=_touch_event;
	this->hmi_instance=_hmi;

	if((touch_event == true) & (function_callback != nullptr)){
		hmi_instance->add_touch_event(page, id, function_callback);
	}
	else{
		this->touch_event=false;
	}
	objectNumber++;
}

gauge::gauge(std::string _name, uint8_t _page, uint8_t _id)
			:COMMON(_name, _hmi){
	this->name=_name;
	this->id=_id;
	this->page=_page;
	this->touch_event=false;
	objectNumber++;
}

gauge::~gauge() {
	// TODO Auto-generated destructor stub
	//this block delete the touch event if exist
	if(touch_event){
		error = hmi_instance->delete_touch_event(this->page, this->id);
	}
	objectNumber--;
}


void gauge::setVal(uint8_t val){
	this->val = val;
	hmi_instance->send_command(this->name, CommandEnum::val, val);

}
void gauge::setFormat(uint8_t format){
	this->format = format;

	hmi_instance->send_command(this->name, CommandEnum::format, format);

}
void gauge::setUp(uint16_t up){
	this->up = up;
	hmi_instance->send_command(this->name, CommandEnum::up, up);

}
void gauge::setDown(uint16_t down){
	this->down = down;
	hmi_instance->send_command(this->name, CommandEnum::down, down);

}
void gauge::setLeft(uint16_t left){
	this->left = left;
	hmi_instance->send_command(this->name, CommandEnum::left, left);

}
void gauge::setPco(uint16_t pco){
	this->pco = pco;
	hmi_instance->send_command(this->name, CommandEnum::pco, pco);
}
void gauge::setPco2(uint16_t pco2){
	this->pco2 = pco2;
	hmi_instance->send_command(this->name, CommandEnum::pco2, pco2);

}
void gauge::setHig(uint8_t hig){
	this->hig = hig;
	hmi_instance->send_command(this->name, CommandEnum::hig, hig);

}
void gauge::setVvs0(uint8_t vvs0){
	this->vvs0 = vvs0;
	hmi_instance->send_command(this->vvs0, CommandEnum::vvs0, vvs0);

}
void gauge::setVvs1(uint8_t vvs1){
	this->vvs1 = vvs1;
	hmi_instance->send_command(this->vvs1, CommandEnum::vvs1, vvs1);

}
void gauge::setVvs2(uint8_t vvs2){
	this->vvs2 = vvs2;
	hmi_instance->send_command(this->vvs2, CommandEnum::vvs2,vvs2);
}



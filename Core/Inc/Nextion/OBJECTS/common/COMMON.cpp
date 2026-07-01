/*
 * COMMON.cpp
 *
 *  Created on: Nov 25, 2023
 *      Author: jacobo.gonzalez
 */

#include <Nextion/OBJECTS/common/COMMON.hpp>

uint8_t COMMON::numberObjects=0;

COMMON::COMMON(std::string _name, HMI * _hmi) {
	// TODO Auto-generated constructor stub
	name=_name;
	hmi_instance=_hmi;
	numberObjects++;
}

COMMON::~COMMON() {
	// TODO Auto-generated destructor stub
	numberObjects--;

}

void COMMON::setDrag(bool value){
	hmi_instance->send_command(name, CommandEnum::drag, value);
}
void COMMON::setAph(uint8_t aph){
	hmi_instance->send_command(name, CommandEnum::aph, aph);
}
void COMMON::setEffect(uint8_t effect){
	hmi_instance->send_command(name, CommandEnum::effect, effect);
}

void COMMON::set_xcen(uint16_t value){
	hmi_instance->send_command(name, CommandEnum::x, value);
}
void COMMON::set_ycen(uint16_t value){
	hmi_instance->send_command(name, CommandEnum::y, value);
}

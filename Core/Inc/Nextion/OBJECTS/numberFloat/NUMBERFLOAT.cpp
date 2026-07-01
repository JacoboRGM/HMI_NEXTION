/*
 * NUMBERFLOAT.cpp
 *
 *  Created on: Nov 25, 2023
 *      Author: jacobo.gonzalez
 */

#include <Nextion/OBJECTS/numberFloat/NUMBERFLOAT.hpp>

uint16_t NUMBER_FLOAT::objectsNumber=0;

NUMBER_FLOAT::NUMBER_FLOAT(std::string _name, uint8_t _page, uint8_t _id,
		bool _touch_event, void(*function_callback)(uint8_t * buff) ,
		HMI * _hmi) : NUMBER(_name, _page, _id,
				_touch_event, function_callback,
				_hmi){
	// TODO Auto-generated constructor stub
	objectsNumber++;
	value=0.0;
	decimalpoints=2;
	integerpoints=2;
	name=_name;
}

NUMBER_FLOAT::~NUMBER_FLOAT() {
	// TODO Auto-generated destructor stub
	objectsNumber--;
}

void NUMBER_FLOAT::setValue(float value){
	int multiplicador = std::pow(10, decimalpoints + integerpoints);
	int resultado = std::round(value * multiplicador);
	hmi_instance->send_command(name, CommandEnum::val, (uint16_t)resultado);
}

void NUMBER_FLOAT::setPointRigth(uint8_t value){
	decimalpoints=value;
	hmi_instance->send_command(name, CommandEnum::vvs0, (uint16_t)value);
}

void NUMBER_FLOAT::setPointLeft(uint8_t value){
	integerpoints=value;
	hmi_instance->send_command(name, CommandEnum::vvs1, (uint16_t)value);
}

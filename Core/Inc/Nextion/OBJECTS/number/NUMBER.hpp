/*
 * NUMBER.hpp
 *
 *  Created on: Nov 24, 2023
 *      Author: jacobo.gonzalez
 */

#ifndef INC_NEXTION_OBJECTS_NUMBER_NUMBER_HPP_
#define INC_NEXTION_OBJECTS_NUMBER_NUMBER_HPP_

#include "Nextion/UART/UART.hpp"
#include "Nextion/HMI_CLASS/HMI.hpp"
#include "Nextion/HMI_CLASS/hmi_typedefs.hpp"
#include "Nextion/OBJECTS/common/COMMON.hpp"
#include <stdint.h>
#include <string.h>

class NUMBER: public COMMON {

public:
	NUMBER(std::string _name, uint8_t _page, uint8_t _id,
			bool _touch_event, void(*function_callback)(uint8_t * buff) ,
			HMI * _hmi);
	~NUMBER();

	void setFont(uint8_t font);
	void setColorNumber(uint16_t value);
	void setColorBackground(uint16_t value);

	void setValue(int value);
	void setLenth(uint8_t value);
	void setFormat(uint8_t value);
	void setIsbr(bool value);
	void set_spax(uint8_t value);
	void set_spay(uint8_t value);

private:
	HMI_NUMBER number;
	static uint16_t objectNumber;

protected:
	HMI * hmi_instance;

};

#endif /* INC_NEXTION_OBJECTS_NUMBER_NUMBER_HPP_ */

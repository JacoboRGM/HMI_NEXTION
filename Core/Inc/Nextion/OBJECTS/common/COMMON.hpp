/*
 * COMMON.hpp
 *
 *  Created on: Nov 25, 2023
 *      Author: jacobo.gonzalez
 */

#ifndef INC_NEXTION_OBJECTS_COMMON_COMMON_HPP_
#define INC_NEXTION_OBJECTS_COMMON_COMMON_HPP_

#include <string.h>
#include <stdint.h>
#include "Nextion/HMI_CLASS/hmi_typedefs.hpp"
#include "Nextion/HMI_CLASS/HMI.hpp"

class COMMON {

public:
	COMMON(std::string _name, HMI * _hmi);
	~COMMON();

	//add the common or most common functions for reduce code
	void setDrag(bool value);
	void setAph(uint8_t aph);
	void setEffect(uint8_t effect);

	void set_xcen(uint16_t value);
	void set_ycen(uint16_t value);

private:

	std::string name;
	HMI * hmi_instance;

protected:

	static uint8_t numberObjects;

};

#endif /* INC_NEXTION_OBJECTS_COMMON_COMMON_HPP_ */

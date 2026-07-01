/*
 * NUMBERFLOAT.hpp
 *
 *  Created on: Nov 25, 2023
 *      Author: jacobo.gonzalez
 */

#ifndef INC_NEXTION_OBJECTS_NUMBERFLOAT_NUMBERFLOAT_HPP_
#define INC_NEXTION_OBJECTS_NUMBERFLOAT_NUMBERFLOAT_HPP_

#include <Nextion/OBJECTS/number/NUMBER.hpp>
#include <cmath>


class NUMBER_FLOAT : public NUMBER {

public:

	NUMBER_FLOAT(std::string _name, uint8_t _page, uint8_t _id,
			bool _touch_event, void(*function_callback)(uint8_t * buff),
			HMI * _hmi);
	~NUMBER_FLOAT();

	void setValue(float value);
	void setPointRigth(uint8_t value);
	void setPointLeft(uint8_t value);

private:
	std::string name;
	float value;
	uint8_t decimalpoints;
	uint8_t integerpoints;

protected:

	static uint16_t objectsNumber;
};
#endif /* INC_NEXTION_OBJECTS_NUMBERFLOAT_NUMBERFLOAT_HPP_ */

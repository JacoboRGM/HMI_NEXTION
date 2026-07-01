/*
 * text.h
 *
 *  Created on: Nov 13, 2023
 *      Author: jacobo.gonzalez
 */

#ifndef INC_NEXTION_OBJECTS_TEXT_TEXT_H_
#define INC_NEXTION_OBJECTS_TEXT_TEXT_H_

#include <string>
#include "Nextion/HMI_CLASS/hmi_typedefs.hpp"
#include "Nextion/HMI_CLASS/HMI.hpp"
#include "Nextion/OBJECTS/common/COMMON.hpp"

class TEXT:public COMMON {
public:
	TEXT(std::string _name, uint8_t _page, uint8_t _id,
		bool _touch_event, void(*function_callback)(uint8_t * buff),
		HMI * _hmi);
	TEXT(std::string _name, uint8_t _page, uint8_t _id, HMI * _hmi);
	~TEXT();

	void setText(std::string text);
	void setColorText(uint16_t color);
	void setColorBackground(uint16_t colorBackground);
	void setFont(uint8_t font);
	void setXcen(uint8_t value);
	void setYcen(uint8_t value);
	void setTypePW(bool val);
	void setIsbr(bool val);
	void setSpax(uint8_t val);
	void setSpay(uint8_t val);

private:
	static uint16_t textNumbers;
	bool touchEvent;

protected:
	HMI_TEXT text;
	HMI * hmi_instance;

};

#endif /* INC_NEXTION_OBJECTS_TEXT_TEXT_H_ */

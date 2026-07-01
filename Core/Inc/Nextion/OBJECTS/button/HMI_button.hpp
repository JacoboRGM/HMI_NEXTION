/*
 *
 * Author: JRGM
 * date: 28-12-2023
 * description: functions for object button hmi nextion
 */

#ifndef __HMI_BUTTON__HPP
#define __HMI_BUTTON__HPP

#include <stdint.h>
#include <string.h>
#include "HMI_button.hpp"
#include "Nextion/UART/UART.hpp"
#include "Nextion/HMI_CLASS/HMI.hpp"
#include "Nextion/HMI_CLASS/hmi_typedefs.hpp"
#include "Nextion/OBJECTS/common/COMMON.hpp"

class BUTTON : public COMMON {

public:
	BUTTON(std::string _name, uint8_t _page, uint8_t _id,
			bool _touch_event, void(*function_callback)(uint8_t * buff) ,
			HMI * _hmi);
	~BUTTON();

	void setText(std::string value);
	void setColorText(uint16_t n);
	void setColorTextPress(uint16_t n);
	void setColorBackground(uint16_t n);
	void setColorBackgroundPress(uint16_t n);

	void setXcen(uint8_t value);
	void setYcen(uint8_t value);

	void setIsbr(bool value);
	void setSpax(uint8_t value);
	void setSpay(uint8_t value);

private:
	static uint16_t button_numbers;
	bool touch_event;
	HMI_BUTTON button;

protected:
	HMI * hmi_instance;

};

#endif /*__HMI_BUTTON__HPP */

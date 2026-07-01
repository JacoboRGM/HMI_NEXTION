/*
 * toggleButton.h
 *
 *  Created on: Nov 26, 2023
 *      Author: jacobo.gonzalez
 */

#ifndef INC_NEXTION_OBJECTS_TOGGLEBUTTON_TOGGLEBUTTON_H_
#define INC_NEXTION_OBJECTS_TOGGLEBUTTON_TOGGLEBUTTON_H_

#include "Nextion/HMI_CLASS/HMI.hpp"
#include "Nextion/OBJECTS/button/HMI_button.hpp"

class TOGGLE_BUTTON : public BUTTON{
public:
	TOGGLE_BUTTON(std::string _name, uint8_t _page, uint8_t _id,
			bool _touch_event, void(*function_callback)(uint8_t * buff) ,
			HMI * _hmi);
	~TOGGLE_BUTTON();

	void setVal(bool val);
	bool getVal(void);

private:
	HMI * hmi_instance;
	std::string name;
	bool value;
protected:
	static uint16_t objectsNumber;

};

#endif /* INC_NEXTION_OBJECTS_TOGGLEBUTTON_TOGGLEBUTTON_H_ */

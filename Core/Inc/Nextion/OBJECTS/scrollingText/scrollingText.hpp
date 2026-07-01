/*
 * scrolingText.hpp
 *
 *  Created on: Dec 28, 2023
 *      Author: Jacobo Gonzalez
 */

#ifndef INC_NEXTION_OBJECTS_SCROLLINGTEXT_SCROLLINGTEXT_HPP_
#define INC_NEXTION_OBJECTS_SCROLLINGTEXT_SCROLLINGTEXT_HPP_
#include "Nextion/OBJECTS/text/text.h"

class scrollingText: public TEXT {
public:

	scrollingText(std::string _name, uint8_t _page, uint8_t _id,
			bool _touch_event, void(*function_callback)(uint8_t * buff),
			HMI * _hmi);
	scrollingText(std::string _name, uint8_t _page, uint8_t _id);
	~scrollingText();

	void enable(bool value);
	void setDir(DirType  dir);
	void setDis(uint8_t dis);
	void setTime(uint8_t time);

private:
	std::string name;
	std::string value;
	bool enable_object;
	DirType currentDir;
	uint8_t dis;
	uint8_t time;
	HMI * hmi;

protected:
	static uint16_t objectNumber;
};

#endif /* INC_NEXTION_OBJECTS_SCROLLINGTEXT_SCROLLINGTEXT_HPP_ */

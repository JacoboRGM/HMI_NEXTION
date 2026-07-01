/*
 * waveform.hpp
 *
 *  Created on: Feb 24, 2024
 *      Author: Jacobo Gonzalez
 */

#ifndef INC_NEXTION_OBJECTS_WAVEFORM_WAVEFORM_HPP_
#define INC_NEXTION_OBJECTS_WAVEFORM_WAVEFORM_HPP_

#include <string>
#include "Nextion/HMI_CLASS/hmi_typedefs.hpp"
#include "Nextion/HMI_CLASS/HMI.hpp"
#include "Nextion/OBJECTS/common/COMMON.hpp"


class waveform : public COMMON{
public:
	waveform(std::string _name, uint8_t _page, uint8_t _id,
			bool _touch_event, void(*function_callback)(uint8_t *), HMI * _hmi);

	waveform(std::string _name, uint8_t _page, uint8_t _id);
	~waveform();

	void setbackgroundColor(uint16_t bgColor);
	void setgridColor(uint16_t gColor);
	void setgridH(uint16_t heigth);
	void setgridW(uint16_t width);
	void setchannelColor(uint16_t color, uint8_t channel);
	void setdataScaling(uint16_t scalingData);
	void writeAdd(std::string _name, uint8_t channel, uint8_t value);



private:

	std::string name;
	uint8_t gdw, gdh;
	uint16_t bco, gdc, dis;
	uint16_t pco0, pco1, pco2, pco3;
	uint8_t control;
protected:
	HMI * hmi_instance;
	static uint16_t objectNumber;
};

#endif /* INC_NEXTION_OBJECTS_WAVEFORM_WAVEFORM_HPP_ */

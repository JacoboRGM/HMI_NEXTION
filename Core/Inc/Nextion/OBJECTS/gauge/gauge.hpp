/*
 * gauge.hpp
 *
 *  Created on: Jan 8, 2024
 *      Author: Jacobo Gonzalez
 */

#ifndef INC_NEXTION_OBJECTS_GAUGE_GAUGE_HPP_
#define INC_NEXTION_OBJECTS_GAUGE_GAUGE_HPP_
#include "Nextion/OBJECTS/common/COMMON.hpp"
#include "Nextion/HMI_CLASS/HMI.hpp"

class gauge : public COMMON{
public:
	gauge(std::string _name, uint8_t _page, uint8_t _id,
	      bool _touch_event, void(*function_callback)(uint8_t * buff),
		  HMI * _hmi);
	~gauge();

	void setVal(uint8_t val);
	void setFormat(uint8_t format);
	void setUp(uint16_t up);
	void setDown(uint16_t down);
	void setLeft(uint16_t left);
	void setPco(uint16_t pco);
	void setPco2(uint16_t pco2);
	void setHig(uint8_t hig);
	void setVvs0(uint8_t vvs0);
	void setVvs1(uint8_t vvs1);
	void setVvs2(uint8_t vvs2);

private:
	std::string name;
	uint8_t id, page, val, format, hig, vvs0, vvs1, vvs2;
	uint16_t up, down, left,pco, pco2;
	bool touch_event;

protected:
	HMI * hmi_instance;
	static uint16_t objectNumber;

};

#endif /* INC_NEXTION_OBJECTS_GAUGE_GAUGE_HPP_ */

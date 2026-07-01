/*
 * ADCBase.h
 *
 *  Created on: Oct 11, 2023
 *      Author: Jacobo Gonzalez
 */

#ifndef INC_ADC_ADCBASE_H_
#define INC_ADC_ADCBASE_H_
#include <vector>
#include "main.h"
#include "adc.h"


class ADCBase {
public:
	ADCBase(ADC_TypeDef * Instance, ADC_HandleTypeDef * hadc);
	~ADCBase();

	HAL_StatusTypeDef read_adc(uint8_t channel, uint16_t * ptrADC_Result, uint16_t timeout=1000);

	HAL_StatusTypeDef config_channel(std::vector<ADC_ChannelConfTypeDef> channelVector);

private:
	ADC_TypeDef * _Instance;
	ADC_HandleTypeDef * _hadc;
	std::vector<ADC_ChannelConfTypeDef> channelVector;
	static uint8_t numChannels;
};

#endif /* INC_ADC_ADCBASE_H_ */

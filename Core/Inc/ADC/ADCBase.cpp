/*
 * ADCBase.cpp
 *
 *  Created on: Oct 11, 2023
 *      Author: Jacobo Gonzalez
 */

#include <ADC/ADCBase.h>
uint8_t ADCBase::numChannels = 2;

ADCBase::ADCBase(ADC_TypeDef * Instance, ADC_HandleTypeDef * hadc) :
	_Instance(Instance), _hadc(hadc)
{

	MX_ADC1_Init();
}

ADCBase::~ADCBase(){

	HAL_ADC_DeInit(_hadc);
}


HAL_StatusTypeDef ADCBase::read_adc(uint8_t channel, uint16_t * ptrADC_Result, uint16_t timeout){
	//read the number of times ADC for obtain the sequencer buffer
	HAL_StatusTypeDef status;
	ADC_ChannelConfTypeDef sconfig;
	sconfig.Channel=channel;
	sconfig.Rank=1;
	sconfig.SamplingTime=ADC_SAMPLETIME_480CYCLES;

	HAL_ADC_ConfigChannel(_hadc, &sconfig);

	status = HAL_ADC_Start(_hadc);
	if(status == HAL_ERROR)
		return status;

	status = HAL_ADC_PollForConversion(_hadc, timeout);
	if(status == HAL_ERROR)
			return status;

	//for(uint8_t ch =0; ch < numChannels; ch++){
	ptrADC_Result[0] =(uint16_t) HAL_ADC_GetValue(_hadc);
	//}
	HAL_ADC_Stop(_hadc);
	return status;
}

HAL_StatusTypeDef ADCBase::config_channel(std::vector<ADC_ChannelConfTypeDef> channelVector){

	//read the size of vector and configure each channel
	HAL_StatusTypeDef status;
	size_t numCH = channelVector.size();
	numChannels=numCH;	//for static member and read buff
	if(channelVector.size() > 0){
		//read each configure and write
		for(uint8_t index=0; index < numCH; index++){
			status = HAL_ADC_ConfigChannel(_hadc, &channelVector[index]);
		}
		return status;
	}
	else{
		status=HAL_ERROR;
		return status;
	}
}



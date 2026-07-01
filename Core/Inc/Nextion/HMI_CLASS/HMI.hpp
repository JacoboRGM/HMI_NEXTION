/*
 * HMI.hpp
 *
 *  Created on: Sep 23, 2023
 *      Author: Jacobo Gonzalez
 */

#ifndef INC_NEXTION_HMI_CLASS_HMI_HPP_
#define INC_NEXTION_HMI_CLASS_HMI_HPP_

#include "Nextion/HMI_CLASS/hmi_typedefs.hpp"
#include "Nextion/UART/FIFO/FIFO.hpp"
#include "Nextion/UART/UART.hpp"
#include <string>
#include <map>
#include <functional>
#include <stdint.h>

//orders from HMI
const uint8_t START_UP 			= 0x00;
const uint8_t SUCCES_I 			= 0x01;
const uint8_t INVALID_C 		= 0x02;
const uint8_t INVALID_P			= 0x03;
const uint8_t INVALID_V			= 0x1A;
const uint8_t OVERFlOW_S 		= 0x24;
const uint8_t TOUCH_E 			= 0X65;
const uint8_t CURRENT_PAGE 		= 0x66;
const uint8_t TOUCH_COORD_A 	= 0x67;
const uint8_t TOUCH_COORD_S 	= 0x68;
const uint8_t RETURN_STRING 	= 0x70;
const uint8_t RETURN_NUMBER	 	= 0x71;
const uint8_t AUTO_SLEEP 		= 0x86;
const uint8_t AUTO_WAKE 		= 0x87;
const uint8_t NEXTION_READY 	= 0x88;
const uint8_t UPGRADE_SD 		= 0x89;
const uint8_t TRANS_DATA_F 		= 0xFD;
const uint8_t TRANS_DATA_R 		= 0xFE;
//custom orders
#define POWER_EVSE		0x90
#define SIS_TIME		0x91
#define SIS_DATE		0x92
#define TIME_LIMIT		0x93
#define CONFIG_ADV		0x94
#define CH_PASSWORD		0x95

class HMI {

public:
	HMI(UART * _hmi_huart);
	~HMI();
	//comands for HMI
	void startRX(void);
	std::string change_page(uint8_t page);
	std::string dims_value(uint8_t value);
	void read_FIFO_input(void);
	uint8_t add_touch_event(uint8_t page, uint8_t id, void(*callback)(uint8_t*));
	uint8_t delete_touch_event(uint8_t page, uint8_t id);

	//overload function for build command
	void send_command(std::string name, CommandEnum command, int value);
	void send_command(std::string name, CommandEnum command, uint16_t value);
	void send_command(std::string name, CommandEnum command, std::string value);


private:
	//HMI struct
	HMI_STRUCT * hmi;
	//uart port config
	UART * hmi_uart_instance;
	//container for touch event
	//		page				id		event
	std::map<uint8_t, std::map<uint8_t,void(*)(uint8_t*)>> callbacksTouchEvent;
	//internal functions
	void hmi_init(void);

protected:
	static uint8_t hmi_number;
	static uint8_t dataRx;
	//interrupts for UART atends for HMI
	static void TxCpltCallback(UART_HandleTypeDef *huart);
	static void RxCpltCallback(UART_HandleTypeDef *huart);

};

#endif /* INC_NEXTION_HMI_CLASS_HMI_HPP_ */

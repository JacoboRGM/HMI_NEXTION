/*
 * UART.hpp
 *
 *  Created on: Sep 23, 2023
 *      Author: Jacobo Gonzalez
 */

#ifndef INC_NEXTION_UART_HPP_
#define INC_NEXTION_UART_HPP_
#include <string>
#include "usart.h"

class UART {

public:
	UART(USART_TypeDef *Instance, UART_HandleTypeDef * huart);
	~UART();
	void setup(void);
	void write(std::string buff);
	HAL_StatusTypeDef read(uint8_t * read_buff, uint16_t size);
	void set_callbackRX(void(*rxCallback)(UART_HandleTypeDef *huart));
	void set_callbackTX(void(*txCallback)(UART_HandleTypeDef *huart));
	HAL_StatusTypeDef start_RX_IT(uint8_t * rxBuff, uint16_t numberChars);
	HAL_StatusTypeDef start_TX_IT(uint8_t * rxData, uint16_t size);

private:
	USART_TypeDef * _Instance;
	UART_HandleTypeDef * _huart;

protected:
	static bool check_init;
	//default callbacks for UART::callbacks
	static void TxCpltCallback(UART_HandleTypeDef *huart);
	static void RxCpltCallback(UART_HandleTypeDef *huart);

};

#endif /* INC_NEXTION_UART_HPP_ */

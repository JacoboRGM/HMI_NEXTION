/*
 * UARTBase.h
 *
 *  Created on: Oct 7, 2023
 *      Author: Jacobo Gonzalez
 */

#ifndef UARTCLASS_V1_UARTBASE_H_
#define UARTCLASS_V1_UARTBASE_H_

#include "stm32f4xx_hal_uart.h"
#include "stm32f411xe.h"
#include "stm32f4xx_hal_def.h"

class UARTBase {
public:
	UARTBase();
	~UARTBase();

	void write();
	void read();

protected:
	USART_TypeDef * _Instace;
	UART_HandleTypeDef *_huart;


};

#endif /* UARTCLASS_V1_UARTBASE_H_ */

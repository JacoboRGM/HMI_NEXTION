/*
 * FIFO.hpp
 *
 *  Created on: Sep 25, 2023
 *      Author: Jacobo Gonzalez
 */

#ifndef INC_NEXTION_UART_FIFO_FIFO_HPP_
#define INC_NEXTION_UART_FIFO_FIFO_HPP_

#include <queue>
#include <vector>
#include <string>

const uint8_t SIZE_BUFF_HMI_RX = 16;


class FIFO_BUFFER{

public:
	FIFO_BUFFER();
	~FIFO_BUFFER();

	bool push(const std::vector<uint8_t>& data);

	std::vector<uint8_t> pop();

	size_t size() const;

	bool isEmpty() const;

	void clear();

private:
	std::queue<std::vector<uint8_t>> _buffer;
	size_t _capacity;

};

#endif /* INC_NEXTION_UART_FIFO_FIFO_HPP_ */

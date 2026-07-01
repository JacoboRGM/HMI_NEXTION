/*
 * FIFO.cpp
 *
 *  Created on: Sep 25, 2023
 *      Author: Jacobo Gonzalez
 */

#include <Nextion/UART/FIFO/FIFO.hpp>

FIFO_BUFFER::FIFO_BUFFER(){

	_capacity=(size_t)SIZE_BUFF_HMI_RX;

}


FIFO_BUFFER::~FIFO_BUFFER(){

}


bool FIFO_BUFFER::push(const std::vector<uint8_t>& data){

	if (_buffer.size() == _capacity) {

		return false;
	}
	_buffer.push(data);
	return true;
}


std::vector<uint8_t> FIFO_BUFFER::pop(){

	if (_buffer.empty()) {

		return {}; // Return an empty array if the buffer is empty or throw an exception if preferred.
	}
	std::vector<uint8_t> frontElement = _buffer.front();
	_buffer.pop();
	return frontElement;
}


size_t FIFO_BUFFER::size() const{
	return _buffer.size();
}


bool FIFO_BUFFER::isEmpty() const{
	return _buffer.empty();
}

void FIFO_BUFFER::clear(){
	while (!_buffer.empty()) {
		_buffer.pop();
	}
}

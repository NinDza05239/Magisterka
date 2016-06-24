/*
 * Transmitter.h
 *
 *  Created on: 23 kwi 2016
 *      Author: NinDza
 */

#ifndef TRANSMITTER_H_
#define TRANSMITTER_H_

#include "hardware.h"
#include "core.h"
#include "can.h"
#include "uart.h"

class Transmitter : public hardware{
private:
	can* _can_port;
	core* _core_processor;
	uart* _uart_port;

public:
	Transmitter();
	~Transmitter();
	void selftest();

	void uart_send(const char* data);
	const char* uart_recieve();

	void can_send(int ID, unsigned char data);
	const char* can_recieve();
};



#endif /* TRANSMITTER_H_ */

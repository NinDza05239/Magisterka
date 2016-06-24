/*
 * uart.h
 *
 *  Created on: 23 kwi 2016
 *      Author: NinDza
 */

#ifndef UART_H_
#define UART_H_

class uart{
public:
	uart(){};
	virtual ~uart(){};
	virtual void transmission_config() = 0;
	virtual void send(const char* data, size_t size) = 0;
	virtual const char* recieve() = 0;
};



#endif /* UART_H_ */

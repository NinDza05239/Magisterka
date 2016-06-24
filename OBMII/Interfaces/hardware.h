/*
 * hardware.h
 *
 *  Created on: 23 kwi 2016
 *      Author: NinDza
 */

#ifndef HARDWARE_H_
#define HARDWARE_H_

class hardware{
public:
	hardware(){};
	virtual ~hardware(){};

	virtual void selftest() = 0;

	virtual void uart_send(const char* data) = 0;
    virtual const char* uart_recieve() = 0;

	virtual void can_send(int ID, unsigned char data) = 0;
	virtual const char* can_recieve() = 0;
};




#endif /* HARDWARE_H_ */

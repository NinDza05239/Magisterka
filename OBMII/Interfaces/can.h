/*
 * can.h
 *
 *  Created on: 23 kwi 2016
 *      Author: NinDza
 */

#ifndef CAN_H_
#define CAN_H_

class can{
public:
	can(){};
	virtual ~can(){};
	virtual void transmission_config() = 0;
	virtual void can_send(int ID, unsigned char data)=0;
	virtual const char* can_recieve() = 0;
};



#endif /* CAN_H_ */

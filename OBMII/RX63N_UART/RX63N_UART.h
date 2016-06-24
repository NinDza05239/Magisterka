/*
 * RX63N_UART.h
 *
 *  Created on: 23 kwi 2016
 *      Author: NinDza
 */

#ifndef RX63N_UART_H_
#define RX63N_UART_H_

#include "uart.h"
#include "iodefine.h"
#include <string>

#pragma interrupt (Excep_SCI2_RXI2(vect=220))
void Excep_SCI2_RXI2(void);

#pragma interrupt (Excep_SCI2_TXI2(vect=221))
void Excep_SCI2_TXI2(void);



class RX63N_UART : public uart{
public:
	volatile __evenaccess st_port5* port;
	volatile __evenaccess st_sci0 *SCIx;
	//string _recieved_data;
	char* _recieved_data;
	void pin_config();
public:

	RX63N_UART();
	~RX63N_UART();

	void transmission_config();
//	void send(string data);
	void send(const char* data, size_t size);

//	string recieve();
	const char* recieve();
};



#endif /* RX63N_UART_H_ */

/*
 * RX63N_CAN.h
 *
 *  Created on: 23 kwi 2016
 *      Author: NinDza
 */

#ifndef RX63N_CAN_H_
#define RX63N_CAN_H_

#include "can.h"
#include "iodefine.h"
#include <string>

#pragma interrupt (Excep_CAN0_RXM0(vect=50))
void Excep_CAN0_RXM0(void);

// CAN0 TXM0
#pragma interrupt (Excep_CAN0_TXM0(vect=51))
void Excep_CAN0_TXM0(void);

class RX63N_CAN : public can{
private:
	volatile __evenaccess st_port3* port;
	volatile __evenaccess st_can *CANx;

	void pin_config();
	void CAN_MODE_RESET();
	void CAN_MODE_HALT();
	void CAN_MODE_SLEEP(bool active);
	void CAN_MODE_OPERATION();
	void CAN_MODE_TEST(unsigned char test, bool active);
	void default_mailbox_config();
public:
	RX63N_CAN();
	~RX63N_CAN();
	void transmission_config();
	void can_send(int ID, unsigned char data);
	const char* can_recieve();
};



#endif /* RX63N_CAN_H_ */

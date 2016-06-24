/*
 * TestSuite.h
 *
 *  Created on: 23 kwi 2016
 *      Author: NinDza
 */

#ifndef TESTSUITEHARDWARE_H_
#define TESTSUITEHARDWARE_H_

#include "hardware.h"

#pragma interrupt (Excep_CMT0_CMI0(vect=28))
void Excep_CMT0_CMI0(void);

class TestSuite_hardware{
public:
	hardware* TestedDevice;

	TestSuite_hardware();
	~TestSuite_hardware();

	void set_up();
	void tear_down();


	bool UARTSendTest();
	bool UARTRecieveTest();
	bool CANTransmissionTest();
	bool InstructionComputingTest();
	bool FreeRTOS_TickTest();
	bool SerialTransmissionTest(int k);

};



#endif /* TESTSUITEHARDWARE_H_ */

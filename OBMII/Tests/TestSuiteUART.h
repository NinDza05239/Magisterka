/*
 * TestSuiteUART.h
 *
 *  Created on: 24 cze 2016
 *      Author: NinDza
 */

#ifndef TESTSUITEUART_H_
#define TESTSUITEUART_H_

#include "core.h"
#include "uart.h"

class TestSuiteUART{
public:
	core* cpu;
	uart* TestedDevice;

	TestSuiteUART();
	~TestSuiteUART();

	void setup();
	void teardown();

	void UARTSendTest();

};





#endif /* TESTSUITEUART_H_ */

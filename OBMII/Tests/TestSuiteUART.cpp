/*
 * TestSuiteUART.cpp
 *
 *  Created on: 24 cze 2016
 *      Author: NinDza
 */
#include "RX63N_CPU.h"
#include "RX63N_UART.h"
#include "TestSuiteUART.h"

TestSuiteUART::TestSuiteUART(){}

TestSuiteUART::~TestSuiteUART(){}

void TestSuiteUART::setup()
{
	cpu = new RX63N_CPU();
	cpu->~core();
	delete cpu;

	TestedDevice = new RX63N_UART();
}

void TestSuiteUART::teardown()
{
	TestedDevice->~uart();
	delete TestedDevice;

}

void TestSuiteUART::UARTSendTest()
{
	TestedDevice->send("Testing UART Interface, baudrate = 9600 1stop Bit",49);
}

void TestSuiteUART::UARTRecieveTest()
{
	const char* data_ptr;
	TestedDevice->send("Testing UART Interface, in [5] seconds",39);
	for(int i = 0; i<5000000;i++){}
	data_ptr = TestedDevice->recieve();
	TestedDevice->send(data_ptr + 1,(int)(*data_ptr));

}

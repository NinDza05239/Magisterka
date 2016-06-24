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
	TestedDevice->send("Testing UART Interface, baudrate = 9600 1stop Bit",48);

}


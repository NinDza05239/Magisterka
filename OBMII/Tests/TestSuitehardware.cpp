/*
 * TestSuite.cpp
 *
 *  Created on: 23 kwi 2016
 *      Author: NinDza
 */
#include "TestSuitehardware.h"
#include "hardware.h"
#include "Transmitter.h"
#include "obm.h"
#include "OnBoardMonitorApi.h"
#include "ActionFactory.h"
#include "iodefine.h"

#include "string.h"


TestSuite_hardware::TestSuite_hardware()
{
	TestedDevice = NULL;
};
TestSuite_hardware::~TestSuite_hardware(){};

void TestSuite_hardware::set_up()
{
	try
	{
		TestedDevice = new Transmitter();
	}
	catch(__EDG_STD_NAMESPACE::bad_alloc &er)
	{
		er.what();
	}
}

void TestSuite_hardware::tear_down()
{
	TestedDevice->~hardware();
	delete TestedDevice;

}


bool TestSuite_hardware::UARTSendTest(){
	this->set_up();

	const char* TestedString = "Test 1 Success";
    TestedDevice->uart_send(TestedString);

    this->tear_down();
	return true;
}

bool TestSuite_hardware::UARTRecieveTest(){
	this->set_up();

	while(TestedDevice->uart_recieve()!="Test2Success"){}
	this->tear_down();
	return true;
}

bool TestSuite_hardware::CANTransmissionTest(){
	this->set_up();

	TestedDevice->can_send(0,0x75);
	TestedDevice->can_send(0,0x76);
	TestedDevice->can_send(0,0x77);
	TestedDevice->can_send(0,0x78);
	TestedDevice->can_send(0,0x79);

	this->tear_down();
	return true;
}


bool TestSuite_hardware::InstructionComputingTest()
{
	bool instr1 = false;
	bool instr2 = false;
	bool instr3 = true;
	bool instr4 = false;

	this->set_up();

    PORTD.PDR.BIT.B4 = 0x1;
	PORTD.PMR.BIT.B4 = 0x0;
	PORTD.PDR.BIT.B5 = 0x1;
	PORTD.PMR.BIT.B5 = 0x0;

    PORTD.PDR.BIT.B6 = 0x1;
	PORTD.PMR.BIT.B6 = 0x0;
	PORTD.PDR.BIT.B7 = 0x1;
	PORTD.PMR.BIT.B7 = 0x0;

	PORTD.PODR.BIT.B4 = 0x1;
	PORTD.PODR.BIT.B5 = 0x1;
	PORTD.PODR.BIT.B6 = 0x1;
	PORTD.PODR.BIT.B7 = 0x1;

	while(instr1 == false && instr2 == false && instr3 == false)
	{
		if(TestedDevice->uart_recieve() == "on")
		{
			PORTD.PODR.BIT.B4 = 0x0;
			PORTD.PODR.BIT.B5 = 0x0;
			PORTD.PODR.BIT.B6 = 0x1;
			PORTD.PODR.BIT.B7 = 0x1;
			instr1 = true;
		}
		else if(TestedDevice->uart_recieve() == "off")
		{
			PORTD.PODR.BIT.B4 = 0x1;
			PORTD.PODR.BIT.B5 = 0x1;
			PORTD.PODR.BIT.B6 = 0x0;
			PORTD.PODR.BIT.B7 = 0x0;

			instr2 = true;
		}
	}
	this->tear_down();

	return true;
}

bool TestSuite_hardware::SerialTransmissionTest(int k)
{
	this->set_up();

	TestedDevice->uart_send("Andrzej");
	for(int i = 0;i<k;i++){}
	TestedDevice->uart_send("Beata");
	for(int i = 0;i<k;i++){}
	TestedDevice->uart_send("Cezary");
	for(int i = 0;i<k;i++){}


	this->tear_down();

	return true;
}


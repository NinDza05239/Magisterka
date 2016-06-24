/*
 * TestSuiteCPU.cpp
 *
 *  Created on: 24 cze 2016
 *      Author: NinDza
 */
#include "iodefine.h"
#include "TestSuiteCPU.h"
#include "RX63N_CPU.h"

TestSuiteCPU::TestSuiteCPU(){}

TestSuiteCPU::~TestSuiteCPU(){}

void TestSuiteCPU::setup()
{
	TestedDevice = new RX63N_CPU();
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
}

void TestSuiteCPU::teardown()
{
	TestedDevice->~core();
	delete TestedDevice;

}

void TestSuiteCPU::LedBlinkTest()
{
	for(int j = 0; j<20;j++)
	{
		 for(int i = 0; i<120000;i++){}
		 PORTD.PODR.BIT.B4 = 0x0;
		 PORTD.PODR.BIT.B5 = 0x1;
		 PORTD.PODR.BIT.B6 = 0x0;
		 PORTD.PODR.BIT.B7 = 0x1;
		 for(int i = 0; i<120000;i++){}
		 PORTD.PODR.BIT.B4 = 0x1;
		 PORTD.PODR.BIT.B5 = 0x0;
		 PORTD.PODR.BIT.B6 = 0x1;
		 PORTD.PODR.BIT.B7 = 0x0;
	}

}

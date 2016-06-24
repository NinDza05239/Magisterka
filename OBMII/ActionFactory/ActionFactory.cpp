/*
 * ActionFactory.cpp
 *
 *  Created on: 10 cze 2016
 *      Author: NinDza
 */

#ifndef ACTIONFACTORY_CPP_
#define ACTIONFACTORY_CPP_

#include "ActionFactory.h"
#include "hardware.h"
#include "iodefine.h"

void InitLed::ReturnAction(hardware &h)
{
	PORTD.PDR.BIT.B4 = 0x1;
	PORTD.PMR.BIT.B4 = 0x0;
	PORTD.PDR.BIT.B5 = 0x1;
	PORTD.PMR.BIT.B5 = 0x0;

	PORTD.PDR.BIT.B6 = 0x1;
	PORTD.PMR.BIT.B6 = 0x0;
	PORTD.PDR.BIT.B7 = 0x1;
	PORTD.PMR.BIT.B7 = 0x0;

	this->~InitLed();
}


void SwitchLedGreen::ReturnAction(hardware &h)
{
	PORTD.PODR.BIT.B4 = 0x0;
	PORTD.PODR.BIT.B5 = 0x0;
	PORTD.PODR.BIT.B6 = 0x1;
	PORTD.PODR.BIT.B7 = 0x1;

	this->~SwitchLedGreen();
}

void SwitchLedRed::ReturnAction(hardware &h)
{
	PORTD.PODR.BIT.B4 = 0x1;
	PORTD.PODR.BIT.B5 = 0x1;
	PORTD.PODR.BIT.B6 = 0x0;
	PORTD.PODR.BIT.B7 = 0x0;

	this->~SwitchLedRed();
}

void Echo::ReturnAction(hardware &h,  message mes)
{
//	h.uart_send(mes.data.substr(4,mes.length - 4));

	this->~Echo();
}



#endif /* ACTIONFACTORY_CPP_ */

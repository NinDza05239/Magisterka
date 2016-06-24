/*
 * Transmitter.cpp
 *
 *  Created on: 23 kwi 2016
 *      Author: NinDza
 */
#include "Transmitter.h"
#include "RX63N_CPU.h"
#include "RX63N_UART.h"
#include "RX63N_CAN.h"

Transmitter::Transmitter()
{

	try
	{
		_core_processor = new RX63N_CPU();
	}
	catch(__EDG_STD_NAMESPACE::bad_alloc &er)
	{
		er.what();
	}

	try
	{
		_uart_port = new RX63N_UART();
	}
	catch(__EDG_STD_NAMESPACE::bad_alloc &er)
	{
		er.what();
	}

	try
	{
		_can_port = new RX63N_CAN();
	}
	catch(__EDG_STD_NAMESPACE::bad_alloc &er)
	{
		er.what();
	}
};
Transmitter::~Transmitter()
{
	_core_processor->~core();
	_uart_port->~uart();
	_can_port->~can();
};
void Transmitter::selftest(){};

void Transmitter::uart_send(const char* data)
{
	_uart_port->send(data);
}

const char* Transmitter::uart_recieve()
{
	return _uart_port->recieve();
}

void Transmitter::can_send(int ID, unsigned char data)
{
	return _can_port->can_send(ID, data);
};
const char* Transmitter::can_recieve()
{
	return _can_port->can_recieve();
};

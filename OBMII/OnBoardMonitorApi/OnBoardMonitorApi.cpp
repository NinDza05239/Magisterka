/*
 * OnBoardMonitorApi.cpp
 *
 *  Created on: 2 maj 2016
 *      Author: NinDza
 */

#include "OnBoardMonitorApi.h"
#include "OnBoardMonitorMessages.h"
#include "Transmitter.h"
#include <string>
#include "iodefine.h"

OnBoardMonitorApi::OnBoardMonitorApi()
{
	try
	{
		this->transmitter = new Transmitter();
	}
	catch(__EDG_STD_NAMESPACE::bad_alloc &er)
	{
		er.what();
	}
	this->action_g0 = NULL;
	this->action_g1 = NULL;
}
OnBoardMonitorApi::~OnBoardMonitorApi(){}

void OnBoardMonitorApi::CommandExecute()
{
	_command = ParseMessage(transmitter->uart_recieve());
	if(_command.header == MESSAGE_GROUP_0)
	{
		if(_command.data == "init")
		{
			try
			{
				action_g0 = new InitLed();
			}
			catch(__EDG_STD_NAMESPACE::bad_alloc &er)
			{
				er.what();
			}
			action_g0 ->ReturnAction(*transmitter);
		}
		else if(_command.data == "red")
		{
			try
			{
				action_g0 = new SwitchLedRed();
			}
			catch(__EDG_STD_NAMESPACE::bad_alloc &er)
			{
				er.what();
			}
			action_g0 ->ReturnAction(*transmitter);
		}
		else if(_command.data == "green")
		{
			try
			{
				action_g0 = new SwitchLedGreen();
			}
			catch(__EDG_STD_NAMESPACE::bad_alloc &er)
			{
				er.what();
			}
			action_g0 ->ReturnAction(*transmitter);
		}
		else if(_command.data != "")
		{
			action_g0 = new Unknown();
			action_g0 ->ReturnAction(*transmitter);
		}
	}
	else if(_command.header == MESSAGE_GROUP_1)
	{
		if(_command.data.substr(0,4) == "echo")
		{
			try
			{
				action_g1 = new Echo();
			}
			catch(__EDG_STD_NAMESPACE::bad_alloc &er)
			{
				er.what();
			}
			action_g1 ->ReturnAction(*transmitter,_command);
		}
	}
	else if(_command.header == MESSAGE_GROUP_2)
	{

	}


}

message OnBoardMonitorApi::ParseMessage(string mes)
{

	message parsed_message;
	parsed_message.header = mes.substr(0,1);
	parsed_message.length = mes.length();
	parsed_message.data = mes.substr(2,parsed_message.length - 2);

	return parsed_message;
}


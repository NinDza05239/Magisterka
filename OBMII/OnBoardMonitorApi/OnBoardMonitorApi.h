/*
 * OnBoardMonitorApi.h
 *
 *  Created on: 2 maj 2016
 *      Author: NinDza
 */

#ifndef ONBOARDMONITORAPI_H_
#define ONBOARDMONITORAPI_H_

#include "obm.h"
#include "hardware.h"
#include "ActionFactory.h"
#include "OnBoardMonitorMessages.h"




class OnBoardMonitorApi : public obm{
public:
	hardware* transmitter;
	actionfactory_G0* action_g0;
	actionfactory_G1* action_g1;
	message _command;

	OnBoardMonitorApi();
	~OnBoardMonitorApi();


	void CommandExecute();
	message ParseMessage(string mes);
};



#endif /* ONBOARDMONITORAPI_H_ */

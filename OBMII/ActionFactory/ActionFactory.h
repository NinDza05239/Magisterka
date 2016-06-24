/*
 * ActionFactory.h
 *
 *  Created on: 10 cze 2016
 *      Author: NinDza
 */


#ifndef ACTIONFACTORY_H_
#define ACTIONFACTORY_H_

#include "OnBoardMonitorMessages.h"
#include "hardware.h"


class actionfactory_G0{
public:
	actionfactory_G0(){};
	virtual ~actionfactory_G0(){};

	virtual void ReturnAction(hardware &h) = 0;
};

class Unknown : public actionfactory_G0{
public:
	Unknown(){};
	~Unknown(){};
	void ReturnAction(hardware &h){};
};

class InitLed : public actionfactory_G0{
public:
	InitLed(){};
	~InitLed(){};
	void ReturnAction(hardware &h);
};

class SwitchLedGreen : public actionfactory_G0{
public:
	SwitchLedGreen(){};
	~SwitchLedGreen(){};
	void ReturnAction(hardware &h);
};

class SwitchLedRed : public actionfactory_G0{
public:
	SwitchLedRed(){};
	~SwitchLedRed(){};
	void ReturnAction(hardware &h);
};


class actionfactory_G1{
public:
	actionfactory_G1(){};
	virtual ~actionfactory_G1(){};

	virtual void ReturnAction(hardware &h, message mes) = 0;
};



class Echo : public actionfactory_G1{
public:
	Echo(){};
	~Echo(){};
	void ReturnAction(hardware &h, message mes);
};

#endif /* ACTIONFACTORY_H_ */

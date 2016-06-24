/*
 * TestsuiteOBM.cpp
 *
 *  Created on: 14 cze 2016
 *      Author: NinDza
 */

#include "TestSuiteOBM.h"
#include "OnBoardMonitorApi.h"


TestSuite_obm::TestSuite_obm()
{
	TestedDevice = NULL;
}

TestSuite_obm::~TestSuite_obm(){}

void TestSuite_obm::set_up()
{

	try
	{
		TestedDevice =  new OnBoardMonitorApi();
	}
	catch(__EDG_STD_NAMESPACE::bad_alloc &er)
	{
			er.what();
	}
};

void TestSuite_obm::tear_down()
{
	TestedDevice->~obm();
};

bool TestSuite_obm::Test1(){

	this->set_up();

	while(1)
		TestedDevice->CommandExecute();

	this->tear_down();

		return true;
};

bool TestSuite_obm::ActionFactoryTest(){

	while(1)
		TestedDevice->CommandExecute();

	this->tear_down();

		return true;
};




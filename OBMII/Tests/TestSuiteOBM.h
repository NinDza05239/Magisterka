/*
 * TestSuiteOBM.h
 *
 *  Created on: 14 cze 2016
 *      Author: NinDza
 */

#ifndef TESTSUITEOBM_H_
#define TESTSUITEOBM_H_

#include "obm.h"

class TestSuite_obm{
public:
	obm* TestedDevice;

	TestSuite_obm();
	~TestSuite_obm();

	void set_up();
	void tear_down();


	bool Test1();
	bool ActionFactoryTest();

};



#endif /* TESTSUITEOBM_H_ */

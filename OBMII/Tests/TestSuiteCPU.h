/*
 * TestSuiteCPU.h
 *
 *  Created on: 24 cze 2016
 *      Author: NinDza
 */

#ifndef TESTSUITECPU_H_
#define TESTSUITECPU_H_

#include "core.h"

class TestSuiteCPU{
public:
	core* TestedDevice;

	TestSuiteCPU();
	~TestSuiteCPU();

	void setup();
	void teardown();

	void LedBlinkTest();
};





#endif /* TESTSUITECPU_H_ */

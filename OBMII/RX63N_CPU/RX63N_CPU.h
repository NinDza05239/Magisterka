/*
 * RX63N_CPU.h
 *
 *  Created on: 23 kwi 2016
 *      Author: NinDza
 */

#ifndef RX63N_CPU_H_
#define RX63N_CPU_H_

#include "core.h"

#define RX63N_CONFIGURATION_LOCK 		   SYSTEM.PRCR.WORD
#define RX63N_ENABLE_CLOCK_CONFIG          0xA50B
#define RX63N_DISABLE_CLOCK_CONFIG         0xA500


class RX63N_CPU : public core{
private:
	void clock_config_lock(bool s);
	void clock_config();
	void interrupt_config();
public:
	RX63N_CPU();
	~RX63N_CPU();

};




#endif /* RX63N_CPU_H_ */

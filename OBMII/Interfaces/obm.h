/*
 * obm.h
 *
 *  Created on: 2 maj 2016
 *      Author: NinDza
 */

#ifndef OBM_H_
#define OBM_H_

class obm{
public:
	obm(){};
	virtual ~obm(){};

	virtual void CommandExecute() = 0;
};



#endif /* API_H_ */

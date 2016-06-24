/*
 * OnBoardMonitorMessages.h
 *
 *  Created on: 10 cze 2016
 *      Author: NinDza
 */

#ifndef ONBOARDMONITORMESSAGES_H_
#define ONBOARDMONITORMESSAGES_H_

#include <string>

struct message{
	string header;
	size_t length;
	string data;
};

#define MESSAGE_GROUP_0 "0"
#define MESSAGE_GROUP_1 "1"
#define MESSAGE_GROUP_2 "2"

#endif /* ONBOARDMONITORMESSAGES_H_ */

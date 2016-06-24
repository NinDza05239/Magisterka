/*
 * MailboxConfig.h
 *
 *  Created on: 27 kwi 2016
 *      Author: NinDza
 */

#ifndef MAILBOXCONFIG_H_
#define MAILBOXCONFIG_H_

#define ENABLE_ALL_MAILBOX_INTERRUPT 	0xFFFFFFFF;
#define ENABLE_ALL_MAILBOX_MASING 	    0x00000000;

#define MASK_ALL_SID_BITS 	    0x00000000;
#define MASK_ALL_EID_BITS 	    0x00000000;

#define ZEROIZE_REGISTER        0x00000000;

class MailboxConfig{
public:
	char ID_type;
	char remote_transmission;
	int standardID;
	int extendedID;
	char data_length;
	char data[8];

	MailboxConfig()
	{
		ID_type = 0;
		remote_transmission = 0;
		standardID = ZEROIZE_REGISTER;
		extendedID = ZEROIZE_REGISTER;
		data_length = 1;
	};

	~MailboxConfig(){};
};

class  MaskRegister{
public:
	int standardID;
	int extendedID;

	MaskRegister(){
	standardID = MASK_ALL_SID_BITS;
	extendedID = MASK_ALL_EID_BITS;
	}
	~MaskRegister(){};
};

unsigned long MailboxInterruptEnableRegister = ENABLE_ALL_MAILBOX_INTERRUPT;
unsigned long MaskInvalidRegister = ENABLE_ALL_MAILBOX_MASING;

#endif /* MAILBOXCONFIG_H_ */

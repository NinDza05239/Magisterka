/*
 * RX63N_CAN.cpp
 *
 *  Created on: 23 kwi 2016
 *      Author: NinDza
 */

#include "RX63N_CAN.h"
#include "iodefine.h"
#include "typedefine.h"
#include "MailboxConfig.h"



void Excep_CAN0_TXM0(void){

	IR(CAN0,TXM0) = 0;
}

void Excep_CAN0_RXM0(void){

    IR(CAN0,RXM0) = 0;

}

RX63N_CAN::RX63N_CAN()
{
	port = &PORT3;
	CANx = &CAN0;
	MSTP(CAN0) = 0;
	transmission_config();
	pin_config();

	CAN_MODE_HALT();
	default_mailbox_config();
	CAN_MODE_TEST(0x3, true);  /*Test Mode*/
	CAN_MODE_OPERATION();
};
RX63N_CAN::~RX63N_CAN(){};
void RX63N_CAN::transmission_config()
{
	while(CANx->STR.BIT.SLPST == 1){
			CANx->CTLR.BIT.SLPM		= 0x0;
		}

		CANx->CTLR.BIT.CANM 	= 0x1;
		CANx->CTLR.BIT.BOM 		= 0x0;
		CANx->CTLR.BIT.MBM 		= 0x0;
		CANx->CTLR.BIT.IDFM 	= 0x0;
		CANx->CTLR.BIT.MLM	 	= 0x0;//overwrite mode
		CANx->CTLR.BIT.TPM	    = 0x0;
		CANx->CTLR.BIT.TSRC	 	= 0x0;
		CANx->CTLR.BIT.TSPS 	= 0x0;
		CANx->CTLR.BIT.SLPM	 	= 0x0;
		CANx->CTLR.BIT.RBOC 	= 0x0;

		CANx->BCR.BIT.CCLKS		= 0x0;
		CANx->BCR.BIT.TSEG2		= 0x1;
		CANx->BCR.BIT.SJW	 	= 0x1;


		/*CANx->BCR.BIT.BRP	    = 0x1; 416 kHz
		 *CANx->BCR.BIT.BRP	    = 0x2; 280 kHz
		 *CANx->BCR.BIT.BRP	    = 0xf:  62 kHz
		 *
		 *
		 */

		CANx->BCR.BIT.BRP	    = 0xf; /////////////DOSTROIC CLOCK
		CANx->BCR.BIT.TSEG1	 	= 0x3;

		/*
		CANx->MKR->BIT.EID		= 0x0;
		CANx->MKR->BIT.SID		= 0x0;

		 */

		CANx->MKIVLR.WORD.L 		= 0xFFFF;   //writtable only in CAN reset or halt mode
		//MESSAGE MUST HAVE EXACTLY THE SAME ID AS ITS MAILBOX
		CANx->MIER.LONG 		= 0xFFFFFFFF;

		CANx->EIER.BYTE = 0xFF;

		CANx->CTLR.BIT.CANM 	= 0x2;
		/*mailbox 0*/
		/*
		 * IDE = 0 STANDARD ID
		 * RTR = 0 DATA FRAME
		 * SID[10:0] STANDARD ID 0x001
		 */
		for(int i = 0; i<=32; i++)
		{
			CANx->MB[i].ID.BIT.SID = 0x001;
			CANx->MB[i].ID.BIT.EID = 0x000;
			CANx->MB[i].ID.BIT.IDE = 0x0;
			CANx->MB[i].DLC = 0x8;             //ONE DATA BYTE SEND

			CANx->MCTL[i].BYTE = 0x00;
		}

		CANx->CTLR.BIT.CANM = 0x0;
};

void RX63N_CAN::pin_config()
{
	/*CLEARING PERIPHERIAL FUNCTION FOR DESIRED PINS*/
		port->PMR.BIT.B3 = 0;
		port->PMR.BIT.B2 = 0;

		port->PDR.BIT.B3 = 0;
		port->PDR.BIT.B2 = 0;

		/*SETTING DESIRED PIN FUNCTION*/
		port->PMR.BIT.B3 = 1;
		port->PMR.BIT.B2 = 1;

		/*SPECYFYING PINS AS INPUT/OUTPUT*/
		port->PDR.BIT.B3 = 0;	/*CRX0 INPUT */
		port->PDR.BIT.B2 = 1;	/*CTX0 OUTPUT*/

		/*DISABLING WRITE PROTECTION*/
		MPC.PWPR.BIT.B0WI  = 0;
		MPC.PWPR.BIT.PFSWE = 1;

		/*SPECIFY INPUT/OUPTUT FUNCTIONS*/
		MPC.P33PFS.BIT.PSEL = 0x10;
		MPC.P32PFS.BIT.PSEL = 0x10;


		/*ENABLING WRITE PROTECTION*/
		MPC.PWPR.BIT.PFSWE = 0;


		/*SETTING PERIPHERIAL FUNCTION FOR DESIRED PINS*/
		port->PMR.BIT.B3 = 1; /*P33 - CRX0*/
		port->PMR.BIT.B2 = 1; /*P32 - CTX0*/
};

void RX63N_CAN::CAN_MODE_RESET(){
}

/*CAN HALT MODE
 *    used for mailbox configuration
 *	  BCR register can be changed only if listen-only mode is activated for automatic baud rate detection
 */
void RX63N_CAN::CAN_MODE_HALT()
{
	CANx->CTLR.BIT.CANM = 0x2;
	while(CANx->STR.BIT.HLTST == 0){};
}

/*CAN SLEEP MODE
 *
 */
void RX63N_CAN::CAN_MODE_SLEEP( bool active)
{
	if (active)
		CANx->CTLR.BIT.SLPM = 0x1;
	else
		CANx->CTLR.BIT.SLPM = 0x0;
}

/*CAN OPERATION MODE
 *
 */
void RX63N_CAN::CAN_MODE_OPERATION()
{
	CANx->CTLR.BIT.CANM = 0x0;
}

/*CAN TEST MODE
 *	test == b00 other than can test mode
 *	test == b01	Listen_only mode
 *	test == b10	Self Test external loopback
 *	test == b11	Self_test internal loopback
 */
void RX63N_CAN::CAN_MODE_TEST( unsigned char test, bool active)
{
	if (active){
		CANx->TCR.BIT.TSTE = 1;
		CANx->TCR.BIT.TSTM = test;
	}
	else
		CANx->TCR.BIT.TSTE = 1;
}

void RX63N_CAN::default_mailbox_config()
{
	MailboxConfig MB;
	CANx->MB[0].ID.BIT.IDE = MB.ID_type;
	CANx->MB[0].ID.BIT.SID = MB.standardID;
	CANx->MB[0].ID.BIT.EID = MB.extendedID;
	CANx->MB[0].DLC = MB.data_length;

	MaskRegister MSK;
	CANx->MKR[0].BIT.SID = MSK.standardID;
	CANx->MKR[0].BIT.EID = MSK.extendedID;


	CANx->MB[1].ID.BIT.IDE = MB.ID_type;
	CANx->MB[1].ID.BIT.SID = MB.standardID;
	CANx->MB[1].ID.BIT.EID = MB.extendedID;
	CANx->MB[1].DLC = MB.data_length;

	CANx->MKR[1].BIT.SID = MSK.standardID;
	CANx->MKR[1].BIT.EID = MSK.extendedID;

	CANx->MCTL[1].BIT.RX.RECREQ = 1;

	CANx->MIER.LONG = ENABLE_ALL_MAILBOX_INTERRUPT;
	CANx->MKIVLR.LONG = ENABLE_ALL_MAILBOX_MASING;

	MB.~MailboxConfig();
	MSK.~MaskRegister();
}

void RX63N_CAN::can_send(int ID, unsigned char data)
{
	unsigned char txmailbox_DLC = CANx->MB[ID].DLC;

		while(CANx->MCTL[ID].BIT.TX.TRMACTIVE){};
		while(CANx->MCTL[ID].BIT.TX.TRMREQ || CANx->MCTL[ID].BIT.TX.SENTDATA){
			CANx->MCTL[ID].BIT.TX.TRMREQ = 0x0;
			CANx->MCTL[ID].BIT.TX.SENTDATA = 0x0;
		}
		for (_UBYTE i = 0; i < txmailbox_DLC; i++ ){
			CANx->MB[ID].DATA[i] = data;
		}
		CANx->MCTL[ID].BIT.TX.TRMREQ = 0x1;
		while(CANx->MCTL[ID].BIT.TX.TRMACTIVE){};
		CANx->MCTL[ID].BIT.TX.TRMREQ = 0x0;
		CANx->MCTL[ID].BIT.TX.SENTDATA = 0x0; ///czy tutaj go zerować?
};
const char* RX63N_CAN::can_recieve()
{
	return "";
};

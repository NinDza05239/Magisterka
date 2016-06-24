/*
 * RX63N_UART.cpp
 *
 *  Created on: 23 kwi 2016
 *      Author: NinDza
 */
#include "RX63N_UART.h"
#include "iodefine.h"
#include <string>
#include "vect.h"

char SCI2_recieved_data[32];
bool data_updated;

void Excep_SCI2_TXI2(void){

	IR(SCI2,TXI2) = 0;
}

void Excep_SCI2_RXI2(void){

    data_updated = false;
    if(SCI2.RDR=='Y'){}
 //   	SCI2_recieved_data.clear();
    else if(SCI2.RDR=='X')
        data_updated = true;
    else
    	SCI2_recieved_data[0] = SCI2.RDR;
    IR(SCI2,RXI2) = 0;

}

RX63N_UART::RX63N_UART()
{
	port = &PORT5;
	SCIx = &SCI2;
	MSTP(SCI2) = 0;
	transmission_config();
	pin_config();
}
RX63N_UART::~RX63N_UART(){}

void RX63N_UART::transmission_config()
{

	SCIx->SCR.BYTE = 0x00;       //Serial Conrtoll Register Initial Clear


/*SMR Serial Mode Register
 * Serial clock 		- PCLK          B 0/1
 * Multi Procesor mode  - Disabled      B 2
 * Stop Bit             - 1 stop Bit	B 3
 * Parity Mode          - 				B 4
 * Parity               - Disabled	 	B 5
 * Data Length          - 8Bit			B 6
 * Communication Mode   - Asynchronus	B 7
 *
 * writtable only when SCR.TE = 0b AND SCR.RE == 0b
 */

	SCIx->SMR.BIT.CKS 	= 0x0;
	SCIx->SMR.BIT.MP 	= 0x0;
	SCIx->SMR.BIT.STOP 	= 0x0;
	SCIx->SMR.BIT.PM 	= 0x0;
	SCIx->SMR.BIT.PE 	= 0x0;
	SCIx->SMR.BIT.CHR 	= 0x0;
	SCIx->SMR.BIT.CM 	= 0x0;

/*SCR Serial Control Register
 * Asynchronus mode Clock	    - Enabled       B 0/1
 * Transmit End Interrupt mode  - Enabled       B 2
 * Multi Procesor               - Disabled  	B 3
 * Receive Enable      		    - Disabled		B 4
 * Transmit Enabl      		    - Disabled	 	B 5
 * Receive Interr      		    - Enabled		B 6
 * Transmit Interrupt 		    - Enabled	    B 7
 */
	SCIx->SCR.BIT.CKE 	= 0x1;
	SCIx->SCR.BIT.TEIE 	= 0x1;
	SCIx->SCR.BIT.MPIE 	= 0x0;
	SCIx->SCR.BIT.RIE 	= 0x1;
	SCIx->SCR.BIT.TIE 	= 0x1;

/*SSR Serial Status Register
*ERROR in Serial status Register cLear
*Parity Error Flag	            - Clear       B 0
*Error Signal Status Flag       - Clear       B 2
*Overrun Error Flag             - Clear       B 3
*/
	SCIx->SSR.BIT.PER 	= 0x0;
	SCIx->SSR.BIT.FER 	= 0x0;
	SCIx->SSR.BIT.ORER  = 0x0;

/*SCMR Smart card Mode Register
 * configured for serial interface
 *Smart Card Interface Mode	            - Serial Interface       B 0
 *Trans/Reci message invert             - Not Inverted   	     B 2
 *Trans/Reci message endian             - LSB first      		 B 3
 */
	SCIx->SCMR.BYTE			= 0xf2;

/*BRR
 * Bit Rate Register
 */

	SCIx->BRR				= 0x26;		/*9600bps*/

/*SEMR Serial Ectended Mode Register
 *
 *Asynchr Clock Source Select	            - Serial Interface       B 0
 *Asynchr Mode Base Clock Select            - Not Inverted   	     B 2
 *Digital Noise Filter                      - LSB first      		 B 3
 */
	/*writtable only when SCR.TE == 0b and SCR.RE == 0b*/

	SCIx->SEMR.BIT.ACS0		= 0x0;
	SCIx->SEMR.BIT.ABCS		= 0x0;
	SCIx->SEMR.BIT.NFEN		= 0x1;

/*SNFR
 * Noise Filter setting
 */
	/*writtable only when SCR.TE == 0b and SCR.RE == 0b*/

	SCIx->SNFR.BIT.NFCS 	= 0x0;

/*SIMR1
* I2C Mode Select	    - Enabled       B 0/1
* Transmit Interrupt 	- Enabled	    B 7
*/
	SCIx->SIMR1.BIT.IICM 	= 0x0;
	SCIx->SIMR1.BIT.IICDL 	= 0x0;

/*SCR Serial Control Register
* Receive Enable      		    - Disabled		B 4
* Transmit Enabl      		    - Disabled	 	B 5
*/
	SCIx->SCR.BIT.RE 	= 0x1;
	SCIx->SCR.BIT.TE 	= 0x1;
}

void RX63N_UART::pin_config(){


	/*CLEARING PERIPHERIAL FUNCTION FOR DESIRED PINS*/
	port->PMR.BIT.B2 = 0; /*P52 - RXD2*/
	port->PMR.BIT.B0 = 0; /*P50 - TXD2*/
	port->PMR.BIT.B1 = 0; /*P51 - SCK*/

	/*SPECYFYING PINS AS INPUT/OUTPUT*/
	port->PDR.BIT.B2 = 0;	/*RXD2 INPUT */
	port->PDR.BIT.B0 = 1;	/*TXD2 OUTPUT*/
	port->PDR.BIT.B1 = 1;	/*SCK OUTPUT*/

	/*DISABLING WRITE PROTECTION*/
	MPC.PWPR.BIT.B0WI  = 0;
	MPC.PWPR.BIT.PFSWE = 1;

	/*SPECIFY INPUT/OUPTUT FUNCTIONS*/
	MPC.P52PFS.BIT.PSEL |= 0xA;
	MPC.P50PFS.BIT.PSEL |= 0xA;
	MPC.P51PFS.BIT.PSEL |= 0xA;

	/*ENABLING WRITE PROTECTION*/
	MPC.PWPR.BIT.PFSWE |= 0;


	/*SETTING PERIPHERIAL FUNCTION FOR DESIRED PINS*/
	port->PMR.BIT.B2 = 1; /*P52 - RXD2*/
	port->PMR.BIT.B0 = 1; /*P50 - TXD2*/
	port->PMR.BIT.B1 = 1; /*P50 - SCK*/
}

/*

void RX63N_UART::send(string data){

	for(int i=0;i<data.size();i++)
	{
		while(SCIx->SSR.BIT.TEND == 0){};
			SCIx->TDR = data.at(i);
	}
	while(SCIx->SSR.BIT.TEND == 0){};
		SCIx->TDR = '\n';
}
*/

void RX63N_UART::send(const char* data, size_t size){

	for(short i = 0; i<size;i++ )
	{
		while(SCIx->SSR.BIT.TEND == 0){};
			SCIx->TDR = *data;
			data++;
	}
	/*
	while(SCIx->SSR.BIT.TEND == 0){};
		SCIx->TDR = '\n';
		*/
}
/*
string RX63N_UART::recieve()
{

	if(data_updated == true)
	{
		_recieved_data = SCI2_recieved_data;
		data_updated = false;
		return _recieved_data;
	}
	else
		return "";
}
*/

const char* RX63N_UART::recieve()
{

	if(data_updated == true)
	{
		//_recieved_data = SCI2_recieved_data.c_str();
		data_updated = false;
		return _recieved_data;
	}
	else
		return NULL;
}



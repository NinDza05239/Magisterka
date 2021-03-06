/***************************************************************/
/*                                                             */
/*      PROJECT NAME :  OBMII                                  */
/*      FILE         :  OBMII.cpp                              */
/*      DESCRIPTION  :  Main Program                           */
/*      CPU SERIES   :  RX600                                  */
/*      CPU TYPE     :  RX63N                                  */
/*                                                             */
/*      This file is generated by e2 studio.                   */
/*                                                             */
/***************************************************************/                              
                                                                           
                                                                           
                                                                           
                                                                          
/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c or Main.cpp                                    */
/*  DATE        :Tue, Oct 31, 2006                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
//#include "typedefine.h"
#ifdef __cplusplus
//#include <ios>                        // Remove the comment when you use ios
//_SINT ios_base::Init::init_cnt;       // Remove the comment when you use ios
#endif

#include "TestSuiteCPU.h"
#include "TestSuiteUART.h"

void main(void);
#ifdef __cplusplus
extern "C" {
void abort(void);
}
#endif

void main(void)
{
	TestSuiteCPU* CPUTest = new TestSuiteCPU();
	CPUTest->setup();
	CPUTest->LedBlinkTest();
	CPUTest->teardown();
	delete CPUTest;

	TestSuiteUART* UARTTest = new TestSuiteUART();
	UARTTest->setup();
	UARTTest->UARTSendTest();
	UARTTest->UARTRecieveTest();
	UARTTest->teardown();
	delete UARTTest;

}

#ifdef __cplusplus
void abort(void)
{

}
#endif

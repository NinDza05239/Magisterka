/***************************************************************/
/*                                                             */
/*      PROJECT NAME :  OBMII                                  */
/*      FILE         :  vector_table.c                         */
/*      DESCRIPTION  :  Vector Table                           */
/*      CPU SERIES   :  RX600                                  */
/*      CPU TYPE     :  RX63N                                  */
/*                                                             */
/*      This file is generated by e2 studio.                   */
/*                                                             */
/***************************************************************/                                
                                                                           
                                                                           
                                                                           
                                                                          
#include "vect.h"

typedef void (*fp) (void);

#pragma section C FIXEDVECT

void (*const Fixed_Vectors[])(void) = {
//;0xffffff80  
#ifdef __BIG
    (fp)0xFFFFFFF8, // big
#else
    (fp)0xFFFFFFFF, // little
#endif
//;0xffffff84  Reserved
    Dummy,    
//;0xffffff88  OFS1
    (fp)0xFFFFFFFF,
//;0xffffff8C  OFS0
    (fp)0xFFFFFFFF,
//;0xffffff90  Reserved
    Dummy,    
//;0xffffff94  Reserved
    Dummy,    
//;0xffffff98  Reserved
    Dummy,   
//;0xffffff9C  Reserved
    Dummy,    
//;0xffffffA0  Reserved
// uint32_t id_code(Default)
   (fp)0xFFFFFFFF,
 //;0xffffffA4  Reserved
   (fp)0xFFFFFFFF,
//;0xffffffA8  Reserved
   (fp)0xFFFFFFFF,
//;0xffffffAC  Reserved
   (fp)0xFFFFFFFF,
//;0xffffffB0  Reserved
    Dummy,
//;0xffffffB4  Reserved
    Dummy,
//;0xffffffB8  Reserved
    Dummy,
//;0xffffffBC  Reserved
    Dummy,
//;0xffffffC0  Reserved
    Dummy,
//;0xffffffC4  Reserved
    Dummy,
//;0xffffffC8  Reserved
    Dummy,
//;0xffffffCC  Reserved
    Dummy,
//;0xffffffd0  Exception(Supervisor Instruction)
    Excep_SuperVisorInst,
//;0xffffffd4  Reserved
    Dummy,
//;0xffffffd8  Reserved
    Dummy,
//;0xffffffdc  Exception(Undefined Instruction)
    Excep_UndefinedInst,
//;0xffffffe0  Reserved
    Dummy,
//;0xffffffe4  Exception(Floating Point)
    Excep_FloatingPoint,
//;0xffffffe8  Reserved
    Dummy,
//;0xffffffec  Reserved
    Dummy,
//;0xfffffff0  Reserved
    Dummy,
//;0xfffffff4  Reserved
    Dummy,
//;0xfffffff8  NMI
    NonMaskableInterrupt,
//;0xfffffffc  RESET
//;<<VECTOR DATA START (POWER ON RESET)>>
//;Power On Reset PC
   PowerON_Reset_PC                                                                                                                 
//;<<VECTOR DATA END (POWER ON RESET)>>
};



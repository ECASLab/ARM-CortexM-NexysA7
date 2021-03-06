/***************************** Include Files *********************************/
#include <ARMCM1.h>
#include <core_cm1.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "xil_printf.h"
#include "xil_types.h"

int main(void)
{
    char    debugStr[256];
    float 	testFloat;
    // CPU ID register
    volatile u32 *pCPUId = (u32 *)0xE000ED00;
    volatile u32 CPUId;
    int          CPU_part;
    int          CPU_rev;
    int          CPU_var;
    char         CPU_name[20];
    CPUId    = *pCPUId;
    CPU_var  = ((CPUId & 0x00F00000) >> 20);
    CPU_part = ((CPUId & 0x0000FFF0) >> 4);
    CPU_rev  = CPUId & (0x0000000F);
    switch (CPU_part)
    {
        case 0xC21 : strcpy(  CPU_name, "Cortex-M1" ); break;
        case 0xC23 : strcpy(  CPU_name, "Cortex-M3" ); break;
        default    : sprintf( CPU_name, "Unknown %x", CPU_part );
    }
    sprintf (debugStr, "Arm %s Revision %i Variant %i\r\n\n", CPU_name, CPU_rev, CPU_var );
#ifndef SIM_BUILD    
    // Use Xilinx version print command
    print ("************************************\r\n");
    print ( debugStr );
    print ("Example design for Digilent Nexys-A7 board\r\n");
    print (" Version 1.1\r\n");
    print (" Project: HelloWorld_noInt\r\n");
    print ("************************************\r\n");
#else
    print ( debugStr );
#endif
    testFloat=1.23456;
    sprintf(debugStr, "debugStr: Testing floating point(f): %f\r\n",testFloat);
    print(debugStr);
    return 0;
}

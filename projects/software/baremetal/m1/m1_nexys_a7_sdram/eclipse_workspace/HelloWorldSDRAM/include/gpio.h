#include "xil_types.h"
#include <ARMCM1.h>
#include <core_cm1.h>

#define GPIO0_IRQn Interrupt1_IRQn
#define GPIO1_IRQn Interrupt2_IRQn

/* GPIO channel identifiers */
#define NEXYS_A7_LED_CHANNEL 1
#define NEXYS_A7_DIP_CHANNEL 2
#define NEXYS_A7_RGB_CHANNEL 1
#define NEXYS_A7_PB_CHANNEL  2
/***************** Macros (Inline Functions) Definitions *********************/
#ifdef PRE_2_00A_APPLICATION
/*
 * The following macros are provided to allow an application to compile that
 * uses an older version of the driver (pre 2.00a) which did not have a channel
 * parameter. Note that the channel parameter is fixed as channel 1.
 */
#define XGpio_SetDataDirection(InstancePtr, DirectionMask) \
        XGpio_SetDataDirection(InstancePtr, LED_CHANNEL, DirectionMask)
#define XGpio_DiscreteRead(InstancePtr) \
        XGpio_DiscreteRead(InstancePtr, LED_CHANNEL)
#define XGpio_DiscreteWrite(InstancePtr, Mask) \
        XGpio_DiscreteWrite(InstancePtr, LED_CHANNEL, Mask)
#define XGpio_DiscreteSet(InstancePtr, Mask) \
        XGpio_DiscreteSet(InstancePtr, LED_CHANNEL, Mask)
#endif

int InitialiseGPIO( void );
void EnableGPIOInterrupts( void );
void IncLeds( void );
void SweepLeds( void );

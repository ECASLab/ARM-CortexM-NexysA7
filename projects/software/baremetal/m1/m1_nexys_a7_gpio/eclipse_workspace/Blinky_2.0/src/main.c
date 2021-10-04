/***************************** Include Files *********************************/
#include "xparameters.h"
#include "xgpio.h"
#include "gpio.h"
/************************** Constant Definitions *****************************/
/*
 * The following constant is used to wait after an LED is turned on to make
 * sure that it is visible to the human eye.  This constant might need to be
 * tuned for faster or slower processor speeds.
 */
#define LED_DELAY     100000
/*****************************************************************************/
/**
*
* The purpose of this function is to illustrate how to use the GPIO
* driver to turn on and off an LED.
*
* @param	None
*
* @return	XST_FAILURE to indicate that the GPIO Initialization had
*		failed.
*
* @note		This function will not return if the test is running.
*
******************************************************************************/
int main(void)
{
	volatile int Delay;
	int status;
	/* Initialize the GPIO driver */
	status=InitialiseGPIO();
	if(status != XST_SUCCESS){
		//add print error message
		return XST_FAILURE;
	}
	while (1) {
		SweepLeds();
		/* Wait a small amount of time so the LED is visible */
		for (Delay = 0; Delay < LED_DELAY; Delay++);
	}
}

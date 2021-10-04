/*
 * --------Included Headers--------
 */
#include "gpio.h"
#include "xparameters.h"        // Project memory and device map
#include "xgpio.h"              // Xilinx GPIO routines
/************************** Variable Definitions **************************/

/*
 * The following are declared static to this module so they are zeroed and so they are
 * easily accessible from a debugger
 *
 * Also they are initialised in main, but accessed by the IRQ routines
 */
static XGpio Gpio_Led_DIPSw;   /* The driver instance for GPIO Device 0 */
static XGpio Gpio_RGBLed_PB;   /* The driver instance for GPIO Device 1 */
// Initialise the GPIO and zero the outputs
int InitialiseGPIO( void )
{
    // Define local variables
    int status;
    /*
     * Initialize the GPIO driver so that it's ready to use,
     * specify the device ID that is generated in xparameters.h
    */
    status = XGpio_Initialize(&Gpio_Led_DIPSw, XPAR_AXI_GPIO_0_DEVICE_ID);
    if (status != XST_SUCCESS)  {
        return XST_FAILURE;
    }
    status = XGpio_Initialize(&Gpio_RGBLed_PB, XPAR_AXI_GPIO_1_DEVICE_ID);
    if (status != XST_SUCCESS)  {
        return XST_FAILURE;
    }
    // GPIO0
    // Port0 drives led_16bits.  Set bottom 16 LEDs ports to be outputs.
    XGpio_SetDataDirection(&Gpio_Led_DIPSw, NEXYS_A7_LED_CHANNEL, 0xFFFF0000);
    // Port 1 inputs the dip switches. Set to be inputs
    XGpio_SetDataDirection(&Gpio_Led_DIPSw, NEXYS_A7_DIP_CHANNEL, 0xFFFFFFFF);
    // GPIO1
    // Port0 drives led_rgb.  Set 6 RGB ports to be outputs.
    XGpio_SetDataDirection(&Gpio_RGBLed_PB, NEXYS_A7_RGB_CHANNEL, 0xFFFFFFC0);
    // Port 1 inputs the push button switches. Set to be inputs
    XGpio_SetDataDirection(&Gpio_RGBLed_PB, NEXYS_A7_PB_CHANNEL, 0xFFFFFFFF);
    // Default value of LEDs RGB (Turn off all RGB LEDs)
    XGpio_DiscreteWrite(&Gpio_RGBLed_PB, NEXYS_A7_RGB_CHANNEL, 0x0);
    // Write 0xA to LEDs (Turn off all LEDs)
    XGpio_DiscreteWrite(&Gpio_Led_DIPSw, NEXYS_A7_LED_CHANNEL, 0x0);
    return XST_SUCCESS;
}

void IncLeds( void )
{
    // Routine to allow other blocks to indicate activity
    volatile uint32_t gpio_dip_switches;
    // Read dip switches, change LEDs to match
    gpio_dip_switches = XGpio_DiscreteRead(&Gpio_Led_DIPSw, NEXYS_A7_DIP_CHANNEL);   // Capture DIP status
    XGpio_DiscreteWrite(&Gpio_Led_DIPSw, NEXYS_A7_LED_CHANNEL, (gpio_dip_switches+1));   // Set LEDs
}
void SweepLeds( void )
{
	static uint32_t gpio_leds=0;
	XGpio_DiscreteWrite(&Gpio_Led_DIPSw, NEXYS_A7_LED_CHANNEL, gpio_leds);
	XGpio_DiscreteWrite(&Gpio_RGBLed_PB, NEXYS_A7_LED_CHANNEL, gpio_leds);
	gpio_leds++;
}

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

// Set GPIO interrupts
void EnableGPIOInterrupts( void )
{
    // Push buttons and DIP switches are on Channel 2
    XGpio_InterruptEnable(&Gpio_RGBLed_PB, XGPIO_IR_CH2_MASK);
    XGpio_InterruptEnable(&Gpio_Led_DIPSw, XGPIO_IR_CH1_MASK);
    // Having enabled the M1 to handle the interrupts, now enable the GPIO to send the interrupts
    XGpio_InterruptGlobalEnable(&Gpio_RGBLed_PB);
    XGpio_InterruptGlobalEnable(&Gpio_Led_DIPSw);
}
// Define the GPIO interrupt handlers
void GPIO0_Handler( void )
{
    volatile uint32_t gpio_dip_switches;
    // Read dip switches, change LEDs to match
    gpio_dip_switches = XGpio_DiscreteRead(&Gpio_Led_DIPSw, NEXYS_A7_DIP_CHANNEL);   // Capture DIP status
    XGpio_DiscreteWrite(&Gpio_Led_DIPSw, NEXYS_A7_LED_CHANNEL, gpio_dip_switches);   // Set LEDs
   
    // Clear interrupt from GPIO
    XGpio_InterruptClear(&Gpio_Led_DIPSw, XGPIO_IR_MASK);
    // Clear interrupt in NVIC
    NVIC_ClearPendingIRQ(GPIO0_IRQn);
}

void GPIO1_Handler ( void )
{
    int mask, led_val, incr;
    volatile uint32_t gpio_push_buttons;
    volatile uint32_t gpio_leds_rgb;
    // For LEDs, cycle around colour each time respective push button is pressed
    // Only change if a pushbutton is pressed.
    // This prevents a double change as the button is released.
    if( XGpio_DiscreteRead(&Gpio_RGBLed_PB, NEXYS_A7_PB_CHANNEL) != 0 )
    {
        // LEDs are on a 3 spacing.  So multiply button press by 2^3 to increment the correct LED
        gpio_push_buttons = XGpio_DiscreteRead(&Gpio_RGBLed_PB, NEXYS_A7_PB_CHANNEL);
        gpio_leds_rgb     = XGpio_DiscreteRead(&Gpio_RGBLed_PB, NEXYS_A7_RGB_CHANNEL);
        if ( gpio_push_buttons & 0x1 ) {
            mask = 0x7;
            incr = 0x1;
        } else if ( gpio_push_buttons & 0x2 ) {
            mask = (0x7 << 3);
            incr = (0x1 << 3);
        } else if ( gpio_push_buttons & 0x4 ) {
            mask = (0x7 << 6);
            incr = (0x1 << 6);
        } else if ( gpio_push_buttons & 0x8 ) {
            mask = (0x7 << 9);
            incr = (0x1 << 9);
        }
        led_val = gpio_leds_rgb & mask;
        led_val = (led_val+incr) & mask;
        gpio_leds_rgb = (gpio_leds_rgb & ~mask) | led_val;
        XGpio_DiscreteWrite(&Gpio_RGBLed_PB, NEXYS_A7_RGB_CHANNEL, gpio_leds_rgb);
    }
    // Clear interrupt from GPIO
    XGpio_InterruptClear(&Gpio_RGBLed_PB, XGPIO_IR_MASK);
    // Clear interrupt in NVIC
    NVIC_ClearPendingIRQ(GPIO1_IRQn);
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

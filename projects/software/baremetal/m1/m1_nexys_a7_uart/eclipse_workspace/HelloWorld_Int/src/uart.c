/*
 * Copyright:
 * ----------------------------------------------------------------
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 *   (C) COPYRIGHT 2014, 2018 ARM Limited
 *       ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 * ----------------------------------------------------------------
 * File:     uart.c
 * Release Information : Cortex-M1 DesignStart-r0p1-00rel0
 * ----------------------------------------------------------------
 *
 */

/*
 * --------Included Headers--------
 */
/**
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
**/

#
#include "uart.h"
#include "xparameters.h"
#include "xuartlite.h"
#include "xuartlite_i.h"
#include "xil_io.h"
#include "xil_printf.h"

// Instance of the UART, local to this module
static XUartLite UART0_instance;

/*
 * The following counters are used to determine when the entire buffer has
 * been sent and received.
 */
static volatile int TotalReceivedCount;
static volatile int TotalSentCount;

#define UART_BUFFER_SIZE        10

u8 UARTSendBuffer[UART_BUFFER_SIZE];
u8 UARTReceiveBuffer[UART_BUFFER_SIZE];

int InitialiseUART( void )
{
    int Status;
    /*
    * Initialize the UartLite driver so that it's ready to use.
    */
    Status = XUartLite_Initialize(&UART0_instance, XPAR_AXI_UARTLITE_0_DEVICE_ID);
    if (Status != XST_SUCCESS) {
        return XST_FAILURE;
    }
    /*
    * Setup the handlers for the UartLite that will be called from the
    * interrupt context when data has been sent and received, specify a
    * pointer to the UartLite driver instance as the callback reference so
    * that the handlers are able to access the instance data.
    */
    XUartLite_SetSendHandler(&UART0_instance, SendHandler, &UART0_instance);
    XUartLite_SetRecvHandler(&UART0_instance, RecvHandler, &UART0_instance);
    /*
    * Start receiving data before sending it since there is a loopback.
    */
    XUartLite_Recv(&UART0_instance, UARTReceiveBuffer, UART_BUFFER_SIZE);
    /*
	 * Send the buffer using the UartLite.
	 */
	XUartLite_Send(&UART0_instance, UARTSendBuffer, UART_BUFFER_SIZE);
    return XST_SUCCESS;
}

void SendHandler(void *CallBackRef, unsigned int EventData)
{
    TotalSentCount = EventData;
}

void RecvHandler(void *CallBackRef, unsigned int EventData)
{
    TotalReceivedCount = EventData;
}

int CheckUARTRxBytes( void )
{
    /**
    static int  BytesRx;
    int         Diff;
    Diff = TotalReceivedCount - BytesRx;
    if ( Diff )
        BytesRx = TotalReceivedCount;
    return Diff;
    **/
    while (TotalReceivedCount != UART_BUFFER_SIZE){}
    
    return TotalReceivedCount;
    /**/
}


void EnableUARTInterrupts( void )
{
    XUartLite_EnableInterrupt(&UART0_instance);
}

// Define the UART interrupt handler here
void UART0_Handler ( void )
{
    XUartLite_InterruptHandler(&UART0_instance);
    NVIC_ClearPendingIRQ(UART0_IRQn);
}

void printRecvBuffer(void)
{
    static unsigned int id=0;
    XUartLite_DisableInterrupt(&UART0_instance);
    xil_printf("\n\nvoid printRecvBuffer(void): %u\r\n",id);
    xil_printf("Pre memset: TotalReceivedCount = %i\r\n",TotalReceivedCount);
    xil_printf("UART0_instance.Stats.CharactersReceived = %i\r\n",UART0_instance.Stats.CharactersReceived);
    xil_printf("UART0_instance.Stats.ReceiveInterrupts = %i\r\n",UART0_instance.Stats.ReceiveInterrupts);
    print(&UARTReceiveBuffer);
    print("\r\n");
    TotalReceivedCount = 0;

    memset(&UARTReceiveBuffer,0x00,UART_BUFFER_SIZE);
    xil_printf("Post memset: TotalReceivedCount = %i\r\n",TotalReceivedCount);
    ResetRxFifo();
    //XUartLite_ClearStats(&UARTReceiveBuffer);
    XUartLite_EnableInterrupt(&UART0_instance);
    id++;
}
void ResetRxFifo(void)
{
    u32 Register;
    Xil_AssertVoid(&UART0_instance != NULL);
	Xil_AssertVoid(UART0_instance.IsReady == XIL_COMPONENT_IS_READY);
    
	/*
	 * Read the status register 1st such that the next write to the control
	 * register won't destroy the state of the interrupt enable bit
	 */
	Register = XUartLite_ReadReg(UART0_instance.RegBaseAddress,
					XUL_STATUS_REG_OFFSET);

	/*
	 * Mask off the interrupt enable bit to maintain it's state.
	 */
	Register &= XUL_SR_INTR_ENABLED;
	/*
	 * Write to the control register to reset both FIFOs, these bits are
	 * self-clearing such that there's no need to clear them
	 */
	XUartLite_WriteReg(UART0_instance.RegBaseAddress, XUL_CONTROL_REG_OFFSET,
			Register | /*XUL_CR_FIFO_TX_RESET |*/ XUL_CR_FIFO_RX_RESET);
}


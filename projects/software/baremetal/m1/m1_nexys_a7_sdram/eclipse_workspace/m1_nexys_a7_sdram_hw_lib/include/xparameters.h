#ifndef XPARAMETERS_H   /* prevent circular inclusions */
#define XPARAMETERS_H   /* by using protection macros */

/* Definition for CPU ID */
#define XPAR_CPU_ID 0U

/* Definitions for peripheral CORTEXM1_AXI_0 */
#define XPAR_CORTEXM1_AXI_0_CPU_CLK_FREQ_HZ 0


/******************************************************************/

/* Canonical definitions for peripheral CORTEXM1_AXI_0 */
#define XPAR_CPU_CORTEXM1_0_CPU_CLK_FREQ_HZ 0


/******************************************************************/

#define STDIN_BASEADDRESS 0x40600000
#define STDOUT_BASEADDRESS 0x40600000

/******************************************************************/

/* Platform specific definitions */
#define PLATFORM_ARM
 
/* Definitions for sleep timer configuration */
#define XSLEEP_TIMER_IS_DEFAULT_TIMER
 
 
/******************************************************************/
/* Definitions for driver BRAM */
#define XPAR_XBRAM_NUM_INSTANCES 1U

/* Definitions for peripheral AXI_BRAM_CTRL_0 */
#define XPAR_AXI_BRAM_CTRL_0_DEVICE_ID 0U
#define XPAR_AXI_BRAM_CTRL_0_DATA_WIDTH 32U
#define XPAR_AXI_BRAM_CTRL_0_ECC 0U
#define XPAR_AXI_BRAM_CTRL_0_FAULT_INJECT 0U
#define XPAR_AXI_BRAM_CTRL_0_CE_FAILING_REGISTERS 0U
#define XPAR_AXI_BRAM_CTRL_0_UE_FAILING_REGISTERS 0U
#define XPAR_AXI_BRAM_CTRL_0_ECC_STATUS_REGISTERS 0U
#define XPAR_AXI_BRAM_CTRL_0_CE_COUNTER_WIDTH 0U
#define XPAR_AXI_BRAM_CTRL_0_ECC_ONOFF_REGISTER 0U
#define XPAR_AXI_BRAM_CTRL_0_ECC_ONOFF_RESET_VALUE 0U
#define XPAR_AXI_BRAM_CTRL_0_WRITE_ACCESS 0U
#define XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR 0x00000000U
#define XPAR_AXI_BRAM_CTRL_0_S_AXI_HIGHADDR 0x0003FFFFU
#define XPAR_AXI_BRAM_CTRL_0_S_AXI_CTRL_BASEADDR 0xFFFFFFFFU  
#define XPAR_AXI_BRAM_CTRL_0_S_AXI_CTRL_HIGHADDR 0xFFFFFFFFU  


/******************************************************************/

/* Canonical definitions for peripheral AXI_BRAM_CTRL_0 */
#define XPAR_BRAM_0_DEVICE_ID XPAR_AXI_BRAM_CTRL_0_DEVICE_ID
#define XPAR_BRAM_0_DATA_WIDTH 32U
#define XPAR_BRAM_0_ECC 0U
#define XPAR_BRAM_0_FAULT_INJECT 0U
#define XPAR_BRAM_0_CE_FAILING_REGISTERS 0U
#define XPAR_BRAM_0_UE_FAILING_REGISTERS 0U
#define XPAR_BRAM_0_ECC_STATUS_REGISTERS 0U
#define XPAR_BRAM_0_CE_COUNTER_WIDTH 0U
#define XPAR_BRAM_0_ECC_ONOFF_REGISTER 0U
#define XPAR_BRAM_0_ECC_ONOFF_RESET_VALUE 0U
#define XPAR_BRAM_0_WRITE_ACCESS 0U
#define XPAR_BRAM_0_BASEADDR 0x00000000U
#define XPAR_BRAM_0_HIGHADDR 0x0003FFFFU
#define XPAR_BRAM_0_CTRL_BASEADDR 0xFFFFFFFFU  
#define XPAR_BRAM_0_CTRL_HIGHADDR 0xFFFFFFFEU  


/******************************************************************/

/* Definitions for driver GPIO */
#define XPAR_XGPIO_NUM_INSTANCES 2

/* Definitions for peripheral AXI_GPIO_0 */
#define XPAR_AXI_GPIO_0_BASEADDR 0x40000000
#define XPAR_AXI_GPIO_0_HIGHADDR 0x4000FFFF
#define XPAR_AXI_GPIO_0_DEVICE_ID 0
#define XPAR_AXI_GPIO_0_INTERRUPT_PRESENT 1
#define XPAR_AXI_GPIO_0_IS_DUAL 1


/* Definitions for peripheral AXI_GPIO_1 */
#define XPAR_AXI_GPIO_1_BASEADDR 0x40010000
#define XPAR_AXI_GPIO_1_HIGHADDR 0x4001FFFF
#define XPAR_AXI_GPIO_1_DEVICE_ID 1
#define XPAR_AXI_GPIO_1_INTERRUPT_PRESENT 1
#define XPAR_AXI_GPIO_1_IS_DUAL 1


/******************************************************************/

/* Canonical definitions for peripheral AXI_GPIO_0 */
#define XPAR_GPIO_0_BASEADDR 0x40000000
#define XPAR_GPIO_0_HIGHADDR 0x4000FFFF
#define XPAR_GPIO_0_DEVICE_ID XPAR_AXI_GPIO_0_DEVICE_ID
#define XPAR_GPIO_0_INTERRUPT_PRESENT 1
#define XPAR_GPIO_0_IS_DUAL 1

/* Canonical definitions for peripheral AXI_GPIO_1 */
#define XPAR_GPIO_1_BASEADDR 0x40010000
#define XPAR_GPIO_1_HIGHADDR 0x4001FFFF
#define XPAR_GPIO_1_DEVICE_ID XPAR_AXI_GPIO_1_DEVICE_ID
#define XPAR_GPIO_1_INTERRUPT_PRESENT 1
#define XPAR_GPIO_1_IS_DUAL 1


/******************************************************************/

/* Definitions for driver IIC */
#define XPAR_XIIC_NUM_INSTANCES 1

/* Definitions for peripheral AXI_IIC_0 */
#define XPAR_AXI_IIC_0_DEVICE_ID 0
#define XPAR_AXI_IIC_0_BASEADDR 0x40800000
#define XPAR_AXI_IIC_0_HIGHADDR 0x4080FFFF
#define XPAR_AXI_IIC_0_TEN_BIT_ADR 0
#define XPAR_AXI_IIC_0_GPO_WIDTH 1


/******************************************************************/

/* Canonical definitions for peripheral AXI_IIC_0 */
#define XPAR_IIC_0_DEVICE_ID XPAR_AXI_IIC_0_DEVICE_ID
#define XPAR_IIC_0_BASEADDR 0x40800000
#define XPAR_IIC_0_HIGHADDR 0x4080FFFF
#define XPAR_IIC_0_TEN_BIT_ADR 0
#define XPAR_IIC_0_GPO_WIDTH 1


/******************************************************************/

/* Definitions for driver MIG_7SERIES */
#define XPAR_XMIG7SERIES_NUM_INSTANCES 1U

/* Definitions for peripheral MIG_7SERIES_0 */
#define XPAR_MIG_7SERIES_0_DEVICE_ID 0U
#define XPAR_MIG_7SERIES_0_DDR2_ROW_WIDTH 13U
#define XPAR_MIG_7SERIES_0_DDR2_COL_WIDTH 0U
#define XPAR_MIG_7SERIES_0_DDR2_BANK_WIDTH 3U
#define XPAR_MIG_7SERIES_0_DDR2_DQ_WIDTH 16U


/******************************************************************/


/* Definitions for peripheral MIG_7SERIES_0 */
#define XPAR_MIG_7SERIES_0_BASEADDR 0x60000000
#define XPAR_MIG_7SERIES_0_HIGHADDR 0x67FFFFFF


/******************************************************************/

/* Canonical definitions for peripheral MIG_7SERIES_0 */
#define XPAR_MIG7SERIES_0_DEVICE_ID XPAR_MIG_7SERIES_0_DEVICE_ID
#define XPAR_MIG7SERIES_0_DDR_ROW_WIDTH 13U
#define XPAR_MIG7SERIES_0_DDR_COL_WIDTH 0U
#define XPAR_MIG7SERIES_0_DDR_BANK_WIDTH 3U
#define XPAR_MIG7SERIES_0_DDR_DQ_WIDTH 16U
#define XPAR_MIG7SERIES_0_BASEADDR 0x60000000U
#define XPAR_MIG7SERIES_0_HIGHADDR 0x67FFFFFFU


/******************************************************************/

/* Definitions for driver SPI */
#define XPAR_XSPI_NUM_INSTANCES 1U

/* Definitions for peripheral AXI_QUAD_SPI_0 */
#define XPAR_AXI_QUAD_SPI_0_DEVICE_ID 0U
#define XPAR_AXI_QUAD_SPI_0_BASEADDR 0x44A00000U
#define XPAR_AXI_QUAD_SPI_0_HIGHADDR 0x44A0FFFFU
#define XPAR_AXI_QUAD_SPI_0_FIFO_EXIST 1U
#define XPAR_AXI_QUAD_SPI_0_FIFO_DEPTH 16U
#define XPAR_AXI_QUAD_SPI_0_SPI_SLAVE_ONLY 0U
#define XPAR_AXI_QUAD_SPI_0_NUM_SS_BITS 1U
#define XPAR_AXI_QUAD_SPI_0_NUM_TRANSFER_BITS 8U
#define XPAR_AXI_QUAD_SPI_0_SPI_MODE 0U
#define XPAR_AXI_QUAD_SPI_0_TYPE_OF_AXI4_INTERFACE 0U
#define XPAR_AXI_QUAD_SPI_0_AXI4_BASEADDR 0U
#define XPAR_AXI_QUAD_SPI_0_AXI4_HIGHADDR 0U
#define XPAR_AXI_QUAD_SPI_0_XIP_MODE 0U

/* Canonical definitions for peripheral AXI_QUAD_SPI_0 */
#define XPAR_SPI_0_DEVICE_ID 0U
#define XPAR_SPI_0_BASEADDR 0x44A00000U
#define XPAR_SPI_0_HIGHADDR 0x44A0FFFFU
#define XPAR_SPI_0_FIFO_EXIST 1U
#define XPAR_SPI_0_FIFO_DEPTH 16U
#define XPAR_SPI_0_SPI_SLAVE_ONLY 0U
#define XPAR_SPI_0_NUM_SS_BITS 1U
#define XPAR_SPI_0_NUM_TRANSFER_BITS 8U
#define XPAR_SPI_0_SPI_MODE 0U
#define XPAR_SPI_0_TYPE_OF_AXI4_INTERFACE 0U
#define XPAR_SPI_0_AXI4_BASEADDR 0U
#define XPAR_SPI_0_AXI4_HIGHADDR 0U
#define XPAR_SPI_0_XIP_MODE 0U
#define XPAR_SPI_0_USE_STARTUP 0U



/******************************************************************/

/* Definitions for driver UARTLITE */
#define XPAR_XUARTLITE_NUM_INSTANCES 1U

/* Definitions for peripheral AXI_UARTLITE_0 */
#define XPAR_AXI_UARTLITE_0_DEVICE_ID 0U
#define XPAR_AXI_UARTLITE_0_BASEADDR 0x40600000U
#define XPAR_AXI_UARTLITE_0_HIGHADDR 0x4060FFFFU
#define XPAR_AXI_UARTLITE_0_BAUDRATE 230400U
#define XPAR_AXI_UARTLITE_0_USE_PARITY 0U
#define XPAR_AXI_UARTLITE_0_ODD_PARITY 0U
#define XPAR_AXI_UARTLITE_0_DATA_BITS 8U

/* Canonical definitions for peripheral AXI_UARTLITE_0 */
#define XPAR_UARTLITE_0_DEVICE_ID 0U
#define XPAR_UARTLITE_0_BASEADDR 0x40600000U
#define XPAR_UARTLITE_0_HIGHADDR 0x4060FFFFU
#define XPAR_UARTLITE_0_BAUDRATE 230400U
#define XPAR_UARTLITE_0_USE_PARITY 0U
#define XPAR_UARTLITE_0_ODD_PARITY 0U
#define XPAR_UARTLITE_0_DATA_BITS 8U


/******************************************************************/
#endif  /* end of protection macro */

//Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2020.2.2 (lin64) Build 3118627 Tue Feb  9 05:13:49 MST 2021
//Date        : Sun Oct  3 18:12:43 2021
//Host        : El-Shaddai running 64-bit Ubuntu 20.04.3 LTS
//Command     : generate_target m1_nexys_a7_wrapper.bd
//Design      : m1_nexys_a7_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module m1_nexys_a7_wrapper
   (acl_spi_io0_io,
    acl_spi_io1_io,
    acl_spi_sck_io,
    acl_spi_ss_io,
    ddr2_sdram_addr,
    ddr2_sdram_ba,
    ddr2_sdram_cas_n,
    ddr2_sdram_ck_n,
    ddr2_sdram_ck_p,
    ddr2_sdram_cke,
    ddr2_sdram_cs_n,
    ddr2_sdram_dm,
    ddr2_sdram_dq,
    ddr2_sdram_dqs_n,
    ddr2_sdram_dqs_p,
    ddr2_sdram_odt,
    ddr2_sdram_ras_n,
    ddr2_sdram_we_n,
    dip_switches_16bits_tri_i,
    dual_seven_seg_led_disp_tri_o,
    led_16bits_tri_o,
    push_buttons_5bits_tri_i,
    qspi_flash_io0_io,
    qspi_flash_io1_io,
    qspi_flash_io2_io,
    qspi_flash_io3_io,
    qspi_flash_ss_io,
    reset,
    rgb_led_tri_o,
    seven_seg_led_an_tri_o,
    sys_clock,
    temp_sensor_scl_io,
    temp_sensor_sda_io,
    usb_uart_rxd,
    usb_uart_txd);
  inout acl_spi_io0_io;
  inout acl_spi_io1_io;
  inout acl_spi_sck_io;
  inout acl_spi_ss_io;
  output [12:0]ddr2_sdram_addr;
  output [2:0]ddr2_sdram_ba;
  output ddr2_sdram_cas_n;
  output [0:0]ddr2_sdram_ck_n;
  output [0:0]ddr2_sdram_ck_p;
  output [0:0]ddr2_sdram_cke;
  output [0:0]ddr2_sdram_cs_n;
  output [1:0]ddr2_sdram_dm;
  inout [15:0]ddr2_sdram_dq;
  inout [1:0]ddr2_sdram_dqs_n;
  inout [1:0]ddr2_sdram_dqs_p;
  output [0:0]ddr2_sdram_odt;
  output ddr2_sdram_ras_n;
  output ddr2_sdram_we_n;
  input [15:0]dip_switches_16bits_tri_i;
  output [7:0]dual_seven_seg_led_disp_tri_o;
  output [15:0]led_16bits_tri_o;
  input [4:0]push_buttons_5bits_tri_i;
  inout qspi_flash_io0_io;
  inout qspi_flash_io1_io;
  inout qspi_flash_io2_io;
  inout qspi_flash_io3_io;
  inout qspi_flash_ss_io;
  input reset;
  output [5:0]rgb_led_tri_o;
  output [7:0]seven_seg_led_an_tri_o;
  input sys_clock;
  inout temp_sensor_scl_io;
  inout temp_sensor_sda_io;
  input usb_uart_rxd;
  output usb_uart_txd;

  wire acl_spi_io0_i;
  wire acl_spi_io0_io;
  wire acl_spi_io0_o;
  wire acl_spi_io0_t;
  wire acl_spi_io1_i;
  wire acl_spi_io1_io;
  wire acl_spi_io1_o;
  wire acl_spi_io1_t;
  wire acl_spi_sck_i;
  wire acl_spi_sck_io;
  wire acl_spi_sck_o;
  wire acl_spi_sck_t;
  wire acl_spi_ss_i;
  wire acl_spi_ss_io;
  wire acl_spi_ss_o;
  wire acl_spi_ss_t;
  wire [12:0]ddr2_sdram_addr;
  wire [2:0]ddr2_sdram_ba;
  wire ddr2_sdram_cas_n;
  wire [0:0]ddr2_sdram_ck_n;
  wire [0:0]ddr2_sdram_ck_p;
  wire [0:0]ddr2_sdram_cke;
  wire [0:0]ddr2_sdram_cs_n;
  wire [1:0]ddr2_sdram_dm;
  wire [15:0]ddr2_sdram_dq;
  wire [1:0]ddr2_sdram_dqs_n;
  wire [1:0]ddr2_sdram_dqs_p;
  wire [0:0]ddr2_sdram_odt;
  wire ddr2_sdram_ras_n;
  wire ddr2_sdram_we_n;
  wire [15:0]dip_switches_16bits_tri_i;
  wire [7:0]dual_seven_seg_led_disp_tri_o;
  wire [15:0]led_16bits_tri_o;
  wire [4:0]push_buttons_5bits_tri_i;
  wire qspi_flash_io0_i;
  wire qspi_flash_io0_io;
  wire qspi_flash_io0_o;
  wire qspi_flash_io0_t;
  wire qspi_flash_io1_i;
  wire qspi_flash_io1_io;
  wire qspi_flash_io1_o;
  wire qspi_flash_io1_t;
  wire qspi_flash_io2_i;
  wire qspi_flash_io2_io;
  wire qspi_flash_io2_o;
  wire qspi_flash_io2_t;
  wire qspi_flash_io3_i;
  wire qspi_flash_io3_io;
  wire qspi_flash_io3_o;
  wire qspi_flash_io3_t;
  wire qspi_flash_ss_i;
  wire qspi_flash_ss_io;
  wire qspi_flash_ss_o;
  wire qspi_flash_ss_t;
  wire reset;
  wire [5:0]rgb_led_tri_o;
  wire [7:0]seven_seg_led_an_tri_o;
  wire sys_clock;
  wire temp_sensor_scl_i;
  wire temp_sensor_scl_io;
  wire temp_sensor_scl_o;
  wire temp_sensor_scl_t;
  wire temp_sensor_sda_i;
  wire temp_sensor_sda_io;
  wire temp_sensor_sda_o;
  wire temp_sensor_sda_t;
  wire usb_uart_rxd;
  wire usb_uart_txd;

  IOBUF acl_spi_io0_iobuf
       (.I(acl_spi_io0_o),
        .IO(acl_spi_io0_io),
        .O(acl_spi_io0_i),
        .T(acl_spi_io0_t));
  IOBUF acl_spi_io1_iobuf
       (.I(acl_spi_io1_o),
        .IO(acl_spi_io1_io),
        .O(acl_spi_io1_i),
        .T(acl_spi_io1_t));
  IOBUF acl_spi_sck_iobuf
       (.I(acl_spi_sck_o),
        .IO(acl_spi_sck_io),
        .O(acl_spi_sck_i),
        .T(acl_spi_sck_t));
  IOBUF acl_spi_ss_iobuf
       (.I(acl_spi_ss_o),
        .IO(acl_spi_ss_io),
        .O(acl_spi_ss_i),
        .T(acl_spi_ss_t));
  m1_nexys_a7 m1_nexys_a7_i
       (.acl_spi_io0_i(acl_spi_io0_i),
        .acl_spi_io0_o(acl_spi_io0_o),
        .acl_spi_io0_t(acl_spi_io0_t),
        .acl_spi_io1_i(acl_spi_io1_i),
        .acl_spi_io1_o(acl_spi_io1_o),
        .acl_spi_io1_t(acl_spi_io1_t),
        .acl_spi_sck_i(acl_spi_sck_i),
        .acl_spi_sck_o(acl_spi_sck_o),
        .acl_spi_sck_t(acl_spi_sck_t),
        .acl_spi_ss_i(acl_spi_ss_i),
        .acl_spi_ss_o(acl_spi_ss_o),
        .acl_spi_ss_t(acl_spi_ss_t),
        .ddr2_sdram_addr(ddr2_sdram_addr),
        .ddr2_sdram_ba(ddr2_sdram_ba),
        .ddr2_sdram_cas_n(ddr2_sdram_cas_n),
        .ddr2_sdram_ck_n(ddr2_sdram_ck_n),
        .ddr2_sdram_ck_p(ddr2_sdram_ck_p),
        .ddr2_sdram_cke(ddr2_sdram_cke),
        .ddr2_sdram_cs_n(ddr2_sdram_cs_n),
        .ddr2_sdram_dm(ddr2_sdram_dm),
        .ddr2_sdram_dq(ddr2_sdram_dq),
        .ddr2_sdram_dqs_n(ddr2_sdram_dqs_n),
        .ddr2_sdram_dqs_p(ddr2_sdram_dqs_p),
        .ddr2_sdram_odt(ddr2_sdram_odt),
        .ddr2_sdram_ras_n(ddr2_sdram_ras_n),
        .ddr2_sdram_we_n(ddr2_sdram_we_n),
        .dip_switches_16bits_tri_i(dip_switches_16bits_tri_i),
        .dual_seven_seg_led_disp_tri_o(dual_seven_seg_led_disp_tri_o),
        .led_16bits_tri_o(led_16bits_tri_o),
        .push_buttons_5bits_tri_i(push_buttons_5bits_tri_i),
        .qspi_flash_io0_i(qspi_flash_io0_i),
        .qspi_flash_io0_o(qspi_flash_io0_o),
        .qspi_flash_io0_t(qspi_flash_io0_t),
        .qspi_flash_io1_i(qspi_flash_io1_i),
        .qspi_flash_io1_o(qspi_flash_io1_o),
        .qspi_flash_io1_t(qspi_flash_io1_t),
        .qspi_flash_io2_i(qspi_flash_io2_i),
        .qspi_flash_io2_o(qspi_flash_io2_o),
        .qspi_flash_io2_t(qspi_flash_io2_t),
        .qspi_flash_io3_i(qspi_flash_io3_i),
        .qspi_flash_io3_o(qspi_flash_io3_o),
        .qspi_flash_io3_t(qspi_flash_io3_t),
        .qspi_flash_ss_i(qspi_flash_ss_i),
        .qspi_flash_ss_o(qspi_flash_ss_o),
        .qspi_flash_ss_t(qspi_flash_ss_t),
        .reset(reset),
        .rgb_led_tri_o(rgb_led_tri_o),
        .seven_seg_led_an_tri_o(seven_seg_led_an_tri_o),
        .sys_clock(sys_clock),
        .temp_sensor_scl_i(temp_sensor_scl_i),
        .temp_sensor_scl_o(temp_sensor_scl_o),
        .temp_sensor_scl_t(temp_sensor_scl_t),
        .temp_sensor_sda_i(temp_sensor_sda_i),
        .temp_sensor_sda_o(temp_sensor_sda_o),
        .temp_sensor_sda_t(temp_sensor_sda_t),
        .usb_uart_rxd(usb_uart_rxd),
        .usb_uart_txd(usb_uart_txd));
  IOBUF qspi_flash_io0_iobuf
       (.I(qspi_flash_io0_o),
        .IO(qspi_flash_io0_io),
        .O(qspi_flash_io0_i),
        .T(qspi_flash_io0_t));
  IOBUF qspi_flash_io1_iobuf
       (.I(qspi_flash_io1_o),
        .IO(qspi_flash_io1_io),
        .O(qspi_flash_io1_i),
        .T(qspi_flash_io1_t));
  IOBUF qspi_flash_io2_iobuf
       (.I(qspi_flash_io2_o),
        .IO(qspi_flash_io2_io),
        .O(qspi_flash_io2_i),
        .T(qspi_flash_io2_t));
  IOBUF qspi_flash_io3_iobuf
       (.I(qspi_flash_io3_o),
        .IO(qspi_flash_io3_io),
        .O(qspi_flash_io3_i),
        .T(qspi_flash_io3_t));
  IOBUF qspi_flash_ss_iobuf
       (.I(qspi_flash_ss_o),
        .IO(qspi_flash_ss_io),
        .O(qspi_flash_ss_i),
        .T(qspi_flash_ss_t));
  IOBUF temp_sensor_scl_iobuf
       (.I(temp_sensor_scl_o),
        .IO(temp_sensor_scl_io),
        .O(temp_sensor_scl_i),
        .T(temp_sensor_scl_t));
  IOBUF temp_sensor_sda_iobuf
       (.I(temp_sensor_sda_o),
        .IO(temp_sensor_sda_io),
        .O(temp_sensor_sda_i),
        .T(temp_sensor_sda_t));
endmodule

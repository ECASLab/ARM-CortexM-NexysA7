//Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2020.2.2 (lin64) Build 3118627 Tue Feb  9 05:13:49 MST 2021
//Date        : Thu Sep 30 12:58:27 2021
//Host        : El-Shaddai running 64-bit Ubuntu 20.04.3 LTS
//Command     : generate_target m1_nexys_a7_io_wrapper.bd
//Design      : m1_nexys_a7_io_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module m1_nexys_a7_io_wrapper
   (acl_spi_io0_io,
    acl_spi_io1_io,
    acl_spi_sck_io,
    acl_spi_ss_io,
    dip_switches_16bits_tri_i,
    led_16bits_tri_o,
    push_buttons_5bits_tri_i,
    reset,
    rgb_led_tri_o,
    sys_clock,
    temp_sensor_scl_io,
    temp_sensor_sda_io,
    usb_uart_rxd,
    usb_uart_txd);
  inout acl_spi_io0_io;
  inout acl_spi_io1_io;
  inout acl_spi_sck_io;
  inout acl_spi_ss_io;
  input [15:0]dip_switches_16bits_tri_i;
  output [15:0]led_16bits_tri_o;
  input [4:0]push_buttons_5bits_tri_i;
  input reset;
  output [5:0]rgb_led_tri_o;
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
  wire [15:0]dip_switches_16bits_tri_i;
  wire [15:0]led_16bits_tri_o;
  wire [4:0]push_buttons_5bits_tri_i;
  wire reset;
  wire [5:0]rgb_led_tri_o;
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
  m1_nexys_a7_io m1_nexys_a7_io_i
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
        .dip_switches_16bits_tri_i(dip_switches_16bits_tri_i),
        .led_16bits_tri_o(led_16bits_tri_o),
        .push_buttons_5bits_tri_i(push_buttons_5bits_tri_i),
        .reset(reset),
        .rgb_led_tri_o(rgb_led_tri_o),
        .sys_clock(sys_clock),
        .temp_sensor_scl_i(temp_sensor_scl_i),
        .temp_sensor_scl_o(temp_sensor_scl_o),
        .temp_sensor_scl_t(temp_sensor_scl_t),
        .temp_sensor_sda_i(temp_sensor_sda_i),
        .temp_sensor_sda_o(temp_sensor_sda_o),
        .temp_sensor_sda_t(temp_sensor_sda_t),
        .usb_uart_rxd(usb_uart_rxd),
        .usb_uart_txd(usb_uart_txd));
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

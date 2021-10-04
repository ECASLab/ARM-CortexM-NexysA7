//Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2020.2.2 (lin64) Build 3118627 Tue Feb  9 05:13:49 MST 2021
//Date        : Wed Sep 29 23:15:32 2021
//Host        : El-Shaddai running 64-bit Ubuntu 20.04.3 LTS
//Command     : generate_target m1_uart_wrapper.bd
//Design      : m1_uart_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module m1_uart_wrapper
   (LOCKUP,
    reset,
    sys_clock,
    usb_uart_rxd,
    usb_uart_txd);
  output LOCKUP;
  input reset;
  input sys_clock;
  input usb_uart_rxd;
  output usb_uart_txd;

  wire LOCKUP;
  wire reset;
  wire sys_clock;
  wire usb_uart_rxd;
  wire usb_uart_txd;

  m1_uart m1_uart_i
       (.LOCKUP(LOCKUP),
        .reset(reset),
        .sys_clock(sys_clock),
        .usb_uart_rxd(usb_uart_rxd),
        .usb_uart_txd(usb_uart_txd));
endmodule

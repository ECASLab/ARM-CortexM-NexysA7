//Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2020.2.2 (lin64) Build 3118627 Tue Feb  9 05:13:49 MST 2021
//Date        : Tue Sep 28 19:44:38 2021
//Host        : El-Shaddai running 64-bit Ubuntu 20.04.3 LTS
//Command     : generate_target m1_gpio_wrapper.bd
//Design      : m1_gpio_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module m1_gpio_wrapper
   (dip_switches_16bits_tri_i,
    led_16bits_tri_o,
    push_buttons_5bits_tri_i,
    reset,
    rgb_led_tri_o,
    sys_clock);
  input [15:0]dip_switches_16bits_tri_i;
  output [15:0]led_16bits_tri_o;
  input [4:0]push_buttons_5bits_tri_i;
  input reset;
  output [5:0]rgb_led_tri_o;
  input sys_clock;

  wire [15:0]dip_switches_16bits_tri_i;
  wire [15:0]led_16bits_tri_o;
  wire [4:0]push_buttons_5bits_tri_i;
  wire reset;
  wire [5:0]rgb_led_tri_o;
  wire sys_clock;

  m1_gpio m1_gpio_i
       (.dip_switches_16bits_tri_i(dip_switches_16bits_tri_i),
        .led_16bits_tri_o(led_16bits_tri_o),
        .push_buttons_5bits_tri_i(push_buttons_5bits_tri_i),
        .reset(reset),
        .rgb_led_tri_o(rgb_led_tri_o),
        .sys_clock(sys_clock));
endmodule

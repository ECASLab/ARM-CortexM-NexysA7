# *****************************************************************************
# Timing
# *****************************************************************************
# --------------------------------------------------
# Clocks
# --------------------------------------------------

# Rename main clocks for clarity
create_generated_clock -name cpu_clk  [get_pins {m1_nexys_a7_io_i/clk_wiz_0/inst/mmcm_adv_inst/CLKOUT0} ]
create_generated_clock -name qspi_clk [get_pins {m1_nexys_a7_io_i/clk_wiz_0/inst/mmcm_adv_inst/CLKOUT1} ]

set_max_delay -from [get_clocks cpu_clk] -to [get_clocks -include_generated_clocks qspi_clk] -datapath_only 8.5
set_max_delay -from [get_clocks -include_generated_clocks qspi_clk] -to [get_clocks cpu_clk] -datapath_only 17.0
# --------------------------------------------------
# Virtual clocks
# --------------------------------------------------
create_clock -period 100.000 -name slow_out_clk

# --------------------------------------------------
# Untimed ports
# --------------------------------------------------
# Following ports have no timing requirement to any output or on-board clock.
# Set to small delays to give timing closure
set untimed_od 0.5
set untimed_id 0.5
# Switch inputs
set_input_delay -clock [get_clocks sys_clock] -add_delay $untimed_id [get_ports dip_switches*]
set_input_delay -clock [get_clocks sys_clock] -add_delay $untimed_id [get_ports push_buttons*]
# Output LEDs
set_output_delay -clock [get_clocks sys_clock] -add_delay $untimed_od [get_ports led_16bits*]
set_output_delay -clock [get_clocks sys_clock] -add_delay $untimed_od [get_ports rgb_led*]
# Reset
set_input_delay  -clock [get_clocks cpu_clk] -add_delay $untimed_id [get_ports reset*]
# Prevent reset from timing from cpu_clk to qspi_clk
set_false_path -from [get_ports reset*] -to [get_clocks qspi_clk]

# --------------------------------------------------
# Configuration pins
# --------------------------------------------------
set_property CFGBVS VCCO [current_design]
set_property CONFIG_VOLTAGE 3.3 [current_design]

# --------------------------------------------------
# Bitstream generation
# --------------------------------------------------
set_property BITSTREAM.CONFIG.SPI_BUSWIDTH 4 [current_design]
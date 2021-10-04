# *****************************************************************************
# Timing
# *****************************************************************************

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

# --------------------------------------------------
# Configuration pins
# --------------------------------------------------
set_property CFGBVS VCCO [current_design]
set_property CONFIG_VOLTAGE 3.3 [current_design]

# --------------------------------------------------
# Bitstream generation
# --------------------------------------------------
set_property BITSTREAM.CONFIG.SPI_BUSWIDTH 4 [current_design]

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
# Output LEDs
set_property -dict {PACKAGE_PIN N15 IOSTANDARD LVCMOS33} [get_ports LOCKUP]
set_output_delay -clock [get_clocks sys_clock] -add_delay $untimed_od [get_ports LOCKUP]

# --------------------------------------------------
# Configuration pins
# --------------------------------------------------
set_property CFGBVS VCCO [current_design]
set_property CONFIG_VOLTAGE 3.3 [current_design]

# --------------------------------------------------
# Bitstream generation
# --------------------------------------------------
set_property BITSTREAM.CONFIG.SPI_BUSWIDTH 4 [current_design]

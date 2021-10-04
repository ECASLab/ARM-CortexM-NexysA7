# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct /home/jose/Documents/git-ws/personal/local/M1_Nexys_SandBox/projects/m1/software/m1_nexys_a7_io/sdk_worspace/m1_nexys_a7_io_hw/platform.tcl
# 
# OR launch xsct and run below command.
# source /home/jose/Documents/git-ws/personal/local/M1_Nexys_SandBox/projects/m1/software/m1_nexys_a7_io/sdk_worspace/m1_nexys_a7_io_hw/platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {m1_nexys_a7_io_hw}\
-hw {/home/jose/Documents/git-ws/personal/local/M1_Nexys_SandBox/projects/m1/hardware/m1_nexys_a7_io/m1_nexys_a7_io_wrapper.xsa}\
-proc {CORTEXM1_AXI_0} -os {standalone} -fsbl-target {psu_cortexa53_0} -out {/home/jose/Documents/git-ws/personal/local/M1_Nexys_SandBox/projects/m1/software/m1_nexys_a7_io/sdk_worspace}

platform write
platform generate -domains 
platform generate
platform clean
platform clean

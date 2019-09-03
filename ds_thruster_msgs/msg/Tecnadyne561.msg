# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

###################
# Thruster Header #
###################

float32 dle
float32 stx
float32 stn
float32 cmd

#######################
# Extended Status MSG #
#######################

float32 speed_loop_enable_status
float32 minute_tag
float32 second_tag
float32 microsecond_tick_tag
float32 prop_dir
float32 prop_pwm
float32 tach_msb
float32 tach_lsb
float32 fault_status
float32 reset_status
float32 speed_loop_interval
float32 tach_err_count
float32 voltage_msb
float32 voltage_lsb
float32 current_msb
float32 current_lsb
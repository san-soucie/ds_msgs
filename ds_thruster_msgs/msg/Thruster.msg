# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

#######################
# Extended Status MSG #
#######################
float64 checksum
float64 speed_loop_enable_status
float64 minute_tag
float64 second_tag
float64 microsecond_tick_tag
float64 prop_dir
float64 prop_pwm
float64 tach_msb
float64 tach_lsb
float64 fault_status
float64 reset_status
float64 speed_loop_interval
float64 tach_err_count
float64 voltage_msb
float64 voltage_lsb
float64 current_msb
float64 current_lsb
# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

###################
# Thruster Header #
###################

uint32 dle
uint32 stx
uint32 stn
uint32 cmd

#######################
# Extended Status MSG #
#######################
uint32 checksum
uint32 speed_loop_enable_status
uint32 minute_tag
uint32 second_tag
uint32 microsecond_tick_tag
int32 prop_dir
uint32 prop_pwm
uint32 tach_msb
uint32 tach_lsb
uint32 fault_status
uint32 reset_status
uint32 speed_loop_interval
uint32 tach_err_count
uint32 voltage_msb
uint32 voltage_lsb
uint32 current_msb
uint32 current_lsb
uint32 footer_DLE

#######################
# ACK/NAK #
#######################
uint64 ack
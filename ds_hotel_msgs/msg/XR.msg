# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

float32 long_deadhour
uint8 short_deadsecs
float32 code_status
float32 release_status
float32 deadhour_status
# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

string source
float32 transmit_xfr_state
float32 to_send
float32 sent
float32 bytes_sent
float32 tot_bytes_send
float32 receive_xfr_state
float32 to_except
float32 received
float32 tot_bytes_expected
float32 tot_bytes_received
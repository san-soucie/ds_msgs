# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

string wraps_date
string wraps_time
float64 wraps_counter
float64 wraps_heading

# The actual string reported by the wrap sensor has more fields but I'm not yet able to determine what they all are, so they are unparsed for the moment. The full string looks like
# 2018/05/01 01:02:03 1.2 178.9 -391 1308 70 <CR>
# YYYY/MM/DD HH:MM:SS wrap_count heading pitch? roll? A2D(batt %)?
# The last three fields are unknown so unparsed for the moment. This is partially why the raw string gets rebroadcast back out on a UDP port. 

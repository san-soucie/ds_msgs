# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

# Timestamp for when the thruster command was issued?
time stamp

# Time-To-Live in seconds
# The thruster command only applies for this length of time
# TTL checking in most drivers is approximate; this is a
# minimum live time.  This flag should be checked at least every
# health check interval
float32 ttl_seconds

# Name of the thruster this command is intended for
string thruster_name

# Commanded value for the thruster (typically current)
float32 cmd_value

# Desired force produced by cmd_value
float32 cmd_newtons

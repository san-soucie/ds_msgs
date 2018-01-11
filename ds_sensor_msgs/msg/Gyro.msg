# Message for a Gyro

# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

# In degrees. Follows Fossen N-E-D notation
float64 roll               # + rolls to stbd
float64 pitch              # + pitch nose up
float64 heading            # + turns to stbd

float32 NO_VECTOR_MAGNETIC_FIELD_DATA=-9999.0

# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

# All magnetic field values are in nT
float32 x
float32 y
float32 z

# Temperature in C
float32 temperature

float32 OXYGEN_CONCENTRATION_NO_DATA=-9999.00

# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

# O2 concentration in uM
float32 concentration

# Saturation in %
float32 air_saturation

# Temperature in C
float32 temperature

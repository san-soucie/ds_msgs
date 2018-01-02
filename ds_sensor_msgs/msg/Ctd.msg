float32 CTD_NO_DATA=-9999.0

# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

# Conductivity in S/m
float32 conductivity

# Temperature in ITS-90 deg C
float32 temperature

# Pressure, in Decibars
float32 pressure

# Salinity, in psu
float32 salinity

# Speed of Sound
float32 sound_speed

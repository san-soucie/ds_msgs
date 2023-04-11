# Output of an Attitude Heading Reference System (AHRS).

# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

# In degrees.  For humans.
# Follows Fossen N-E-D notation
float64 roll
float64 pitch

# compass has human-interpretable heading in it.
ds_sensor_msgs/Compass compass

# Standard Imu message.
sensor_msgs/Imu imu

# Assuming this AHRS is of the MEMS type with magnetic compass.
ds_sensor_msgs/VectorMagneticField mag

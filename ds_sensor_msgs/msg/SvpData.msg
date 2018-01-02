# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

# Speed of Sound
float64 sound_speed
SoundVelocityTypeEnum sound_speed_method

# Covariance, -1 for unknown
float64 sound_speed_covar

# The Reson SVP-70 sensor also measures
# temperature and pressure-- HOWEVER,
# these are used to calibrate the 
# thermal / strain changes in the probe,
# NOTE for use as water property measurements.
# For that reason, they should go in 
# Sensor State, NOT data!

Header header
SensorId sensor

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

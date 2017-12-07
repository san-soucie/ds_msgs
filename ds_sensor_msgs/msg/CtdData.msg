Header header
SensorId sensor

# Conductivity in S/m
float64 conductivity

# Temperature in ITS-90 deg C
float64 temperature

# Pressure, in Decibars
float64 pressure_dbar

# Depth, in meters
float64 depth

# Depth measurement stuff (see DepthData)
float64 pressure_tare_dbar
float64 latitude

# Salinity, in psu
# (NOTE: practical measurements should ALWAYS be archived in PSU
# see: http://www.teos-10.org/pubs/TEOS-10_Primer.pdf 
# Convieniently, this is also what most CTDs natively report)
float64 salinity

# Speed of Sound
float64 sound_speed
SoundVelocityTypeEnum sound_speed_method

# Covariances (-1 for unknown, units match measurement values above)
float64 depth_covar
float64 temperature_covar
float64 conductivity_covar
float64 salinity_covar
float64 sound_speed_covar




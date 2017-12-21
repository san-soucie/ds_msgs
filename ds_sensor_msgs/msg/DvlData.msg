# ENUM: Velocity mode
uint8 DVL_MODE_BOTTOM=1
uint8 DVL_MODE_WATER=2

# ENUM: Coordinates system 
uint8 DVL_COORD_BEAM=0
uint8 DVL_COORD_INSTRUMENT=1
uint8 DVL_COORD_SHIP=2
uint8 DVL_COORD_EARTH=3

ds_core_msgs/DsDataHeader header
SensorId sensor


#####################################################################
# Velocities [m/s]
geometry_msgs/Vector3 velocity

# row-major, xyz axes.  Set to "-1" if not known.
float64[9] velocity_covar


uint8 num_good_beams

# Speed of sound (m/s) used by the DVL
float32 speed_sound

#####################################################################
# Raw data
geometry_msgs/Vector3[4] beam_unit_vec
float32[4] range
float32[4] range_covar

# Raw velocities [m/s].  Will be beam 1,2,3,4 velocity
# in beam coordinates; or x,y,z,error in other modes
float32[4] raw_velocity
# Covariance, as always, should be -1 if unknown
float32[4] raw_velocity_covar

# Velocity mode (see above)
uint8 velocity_mode

#####################################################################
# Debug data
uint32 unit_serial_number
uint64 unit_timestamp




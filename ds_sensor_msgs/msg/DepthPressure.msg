# Pressure unit constants

float32 DEPTH_PRESSURE_NO_DATA=-9999.0

# Pressure unit is user defined
uint8 UNIT_PRESSURE_USER=0
uint8 UNIT_PRESSURE_PSI=1
uint8 UNIT_PRESSURE_HPA=2
uint8 UNIT_PRESSURE_BAR=3
uint8 UNIT_PRESSURE_KPA=4
uint8 UNIT_PRESSURE_MPA=5
uint8 UNIT_PRESSURE_INHG=6
uint8 UNIT_PRESSURE_MMHG=7
uint8 UNIT_PRESSURE_MH20=8

float32 DEFAULT_LATITUDE=35.0

std_msgs/Header header

# Tared pressure value.
# If 'tare' != DEPTH_PESSURE_NO_DATA, then this value is equal to "raw_pressure - tare"
# If 'tare' == DPETH_PESSURE_NO_DATA, then 'tare' is effectively 0
float32 pressure

# Units for the pressure value
uint8   pressure_unit

# Tare value
float32 tare

# Latitude for Fofonoff calculation of depth.
float32 latitude

# Depth calculated from pressure and latitude.
# If latitude == DEPTH_PRESSURE_NO_DATA, then DEFAULT_LATITUDE is used
float32 depth

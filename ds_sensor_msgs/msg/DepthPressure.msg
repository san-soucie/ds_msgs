# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

# Pressure unit constants

float64 DEPTH_PRESSURE_NO_DATA=-9999.0

# Pressure unit for raw pressure value.
uint8 UNIT_PRESSURE_PSI=1
uint8 UNIT_PRESSURE_HPA=2
uint8 UNIT_PRESSURE_BAR=3
uint8 UNIT_PRESSURE_KPA=4
uint8 UNIT_PRESSURE_MPA=5
uint8 UNIT_PRESSURE_INHG=6
uint8 UNIT_PRESSURE_MMHG=7
uint8 UNIT_PRESSURE_MH20=8
# Pressure unit is user defined - need external knowledge of
# conversion factor to decibar.
uint8 UNIT_PRESSURE_USER_DEFINED=9

float64 DEFAULT_LATITUDE=35.0

# Tared pressure value. (in decibar)
# If 'tare' != DEPTH_PESSURE_NO_DATA, then this value is equal to "raw_pressure - tare"
# If 'tare' == DPETH_PESSURE_NO_DATA, then 'tare' is effectively 0
float64 pressure
float64 pressure_covar

# Raw sensor measurement.  Units, etc, totally depend
# on the sensor.
#
# Final depth is:
# pressure_dbar = raw_sensor_to_dbar(raw) - pressure_tare_dbar
# depth = foffonoff_dbar_to_m(pressure_dbar, latitude)
float64 pressure_raw

# Units for the pressure value
uint8   pressure_raw_unit

# Tare value (in decibar)
float64 tare

# Latitude for Fofonoff calculation of depth.
float64 latitude

# Depth calculated from pressure and latitude.
# If latitude == DEPTH_PRESSURE_NO_DATA, then DEFAULT_LATITUDE is used
float64 depth

# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

# Depth, in meters, based on our "best-guess" estimate
float64 depth

# Pressure, decibars.  Tare ALREADY applied
float64 pressure_dbar

# Pressure at 0m depth, as applied by the driver
float64 pressure_tare_dbar

# Raw sensor measurement.  Units, etc, totally depend
# on the sensor
float64 raw

# Latitude used in Foffonoff conversion
float64 latitude

# Final depth is:
# pressure_dbar = raw_sensor_to_dbar(raw) - pressure_tare_dbar
# depth = foffonoff_dbar_to_m(pressure_dbar, latitude)

# Depth uncertainty (-1 for unknown)
float64 depth_covar

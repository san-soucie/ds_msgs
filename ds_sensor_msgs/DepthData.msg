int8 SV_METHOD_UNKNOWN=0
int8 SV_METHOD_DIRECT=1  # Direct measurement

Header header
SensorId sensor

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

# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

FlaggedDouble northing
FlaggedDouble easting
FlaggedDouble down
FlaggedDouble roll
FlaggedDouble pitch
FlaggedDouble heading
FlaggedDouble depth
FlaggedDouble altitude

# Rates
FlaggedDouble surge_u
FlaggedDouble sway_v
FlaggedDouble heave_w
FlaggedDouble p
FlaggedDouble q
FlaggedDouble r
FlaggedDouble depth_rate
FlaggedDouble altitude_rate
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
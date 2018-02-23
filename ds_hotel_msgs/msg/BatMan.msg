# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

int32 num_bats

uint16 maxVolt
uint16 minVolt
uint16 maxTemp
uint16 minTemp

float64 capacityCoulombs
float64 capacityAh
float64 chargeCoulombs
float64 chargeAh
float64 percentFull
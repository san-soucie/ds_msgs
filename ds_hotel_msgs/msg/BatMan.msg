# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

int32 num_bats

uint16 maxModuleVolt
uint16 minModuleVolt
uint16 maxSwitchTemp
uint16 minSwitchTemp

uint16 maxCellVolt
uint16 minCellVolt
uint16 maxCellTemp
uint16 minCellTemp

float64 capacityCoulombs
float64 capacityAh
float64 chargeCoulombs
float64 chargeAh
float64 percentFull
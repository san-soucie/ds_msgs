# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

uint16 idnum

uint16 totalVoltage     # mV
uint16 switchTemp       # deg C
uint32 countFull
uint32 countCapacity
uint32 countFreerun     # Raw counts
bool balanceEnable
float64 balanceGain
float64 balanceOnsetVoltage
float64 balanceMaxCurrent
uint64 balanceCommandId

# Calculated status info
uint16 errorStatus
float64 capacityCoulombs  # Capacity of this battery, in Coulombs
float64 chargeCoulombs    # Charge currently in the battery, in Coulombs
float64 percentFull       # Battery capacity as a percentage

uint64 repeatingCommandId
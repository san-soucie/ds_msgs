# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

uint16 busAddress
uint16 version
uint16 date
uint16 startupCondition
uint16 uptime
uint16 overflowCount
uint16 timeoutCount
string powerswitchState
uint16 chargetimeRemaining
uint16 chargetimeMax

ClioBatteryPack[] packs
uint16 relativeSOC

## Calculated
float32[] voltages #V
uint16[] temperatures #deg C
uint16[] packCurrents
uint16[] packDates
uint16[] packSerNums
uint16[] packSOC
uint16 maxCellTemp
uint16 minCellTemp
uint16 minCellVoltage
uint16 maxCellVoltage
uint16 switchTemp
float32 moduleVoltage #V
float32 moduleTemperature
float32 moduleStatus
float32 moduleCountCycle
bool charging
bool discharging
uint16 countUsed
uint16 countAvailable
uint16 countCapacity
uint16 fullCapacity
uint16 capacityDesign
uint16 calcCapacity
float64 capacityCoulombs  # Capacity of this battery, in Amp*hours
float64 capacityAh
float64 chargeCoulombs    # Charge currently in the battery, in Amp*hours
float64 chargeAh
float64 percentFull       # Battery capacity as a percentage

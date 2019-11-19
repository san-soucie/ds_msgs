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

# Per-pack
uint16 temperature # deg C
uint16 voltage # V
uint16 current
uint16 avgCurrent
uint16 maxError
uint16 relativeSOC # percent
uint16 absoluteSOC # percent
uint16 countCapacity # Remaining capacity in Amp*hours
uint16 fullCapacity # Predicted capacity when fully charged in Amp*hours
uint16 status
uint16 countCycle
uint16 capacityDesign
uint16 dateManufacture
uint16 serialNumber
uint16 maxCellVoltage
uint16 mid1CellVoltage
uint16 mid2CellVoltage
uint16 minCellVoltage



## Calculated
float32[] voltages #V
uint16[] temperatures #deg C
uint16[] packCurrents
uint16[] packDates
uint16[] packSerNums
uint16 maxCellTemp
uint16 minCellTemp
uint16 switchTemp
float32 totalVoltage #V
bool charging
bool discharging
int32 countUsed
int32 countAvailable
int32 calcCapacity
float64 capacityCoulombs  # Capacity of this battery, in Amp*hours
float64 capacityAh
float64 chargeCoulombs    # Charge currently in the battery, in Amp*hours
float64 chargeAh
float64 percentFull       # Battery capacity as a percentage

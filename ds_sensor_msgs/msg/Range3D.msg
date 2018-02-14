# header contains the frame_id in which this range is expressed in.
# Typically this frame_id is the instrument frame of the sensor
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

uint8 RANGE_INDETERMINANT=0
uint8 RANGE_LOW=1
uint8 RANGE_HIGH=2

geometry_msgs/Vector3 range
uint8 validity
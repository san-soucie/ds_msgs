# Includes a variable sized vector of ranges, that a sensor could output
# if it can provide multiple ranges per message (i.e. dvl, multibeam, blueview, ...)
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

Range3D[] ranges
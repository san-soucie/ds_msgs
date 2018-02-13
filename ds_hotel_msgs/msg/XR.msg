# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

float64 deadhour
bool good

#############
# code_status

uint8 C

################
# release_status

# valve system control word
uint8 V

# motor release control word
uint8 M

# analog mux and nichrome word
uint8 A

# motors count down until stop driving
uint8 M1
uint8 M2

#nichrone burn wire statuses
uint16 N1
uint16 N2

#short deadman (reset by don't abort message)
uint8 TR

#short idle deadman (usually disabled)
uint8 TV

#long deadman
int32 Ds

#################
# deadhour_status
int32 Dd
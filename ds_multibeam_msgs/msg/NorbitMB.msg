# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

# The header time should be the time the ping was transmitted, not the time the message was received.
# Note that these two could potentially be several seconds apart, especially in deep water.

# Header
uint32 preamble
uint32 data_type
uint32 size
uint32 version
uint32 crc


float32 snd_velocity
float32 sample_rate
uint32 num_beams
uint32 ping_number
float64 time
float64 time_net
float32 ping_rate
uint16 type
uint8[] beam_dist_mode
uint8 sonar_mode
float32 tx_angle
float32 gain
float32 tx_freq
float32 tx_bw
float32 tx_len
float32 tx_voltage
float32 swath_dir
float32 swath_open
float32 gate_tilt

uint32 sample_num
float32 angle
uint16 upper_gate
uint16 lower_gate
float32 intensity
uint16 flags
uint8 quality_flag
uint8 quality_val



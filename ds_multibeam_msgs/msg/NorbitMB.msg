# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

uint32 preamble
uint32 type
uint32 size
uint32 version
uint32 reserved
uint32 crc

float32 snd_velocity
float32 sample_rate
uint32 num_beams
uint32 ping_number
float64 time
float64 time_net
float32 ping_rate
uint16 bathy_type
uint8 beam_dist_mode
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
uint32 sample_number_1beam
float32 angle_1beam
uint16 upper_gate_1beam
uint16 lower_gate_1beam
float32 intensity_1beam
uint16 flags_1beam
uint8 quality_flag_1beam
uint8 quality_val_1beam
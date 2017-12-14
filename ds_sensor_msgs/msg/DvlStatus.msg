# struct rdidvl_status_t from lcm/rdidvl/rdidvl_status_t.lcm

int64 utime
#the time of the last command

string last_command
#command sent to the device
string output
#not raw data, should be the result of the command

# Process-specific status
###dslprocess.process_status_t process_status

# Device-specific status and data
###dsldevice.raw_data_t raw
###dsldevice.device_status_t device_status

###rdidvl.rdidvl_ini_t ini
string channel_data
string channel_config
string channel_simstate
string channel_environment

int8 rdidvl_sensor_number
int8 pd_mode

boolean tx_udp
# True if the dvl driver also broadcasts hex ascii on UDP
string  tx_udp_address
int32 tx_udp_port

float64 position[6]

###dsldevice.device_conn_t connection

###dsldevice.enumer_t enumer

string host
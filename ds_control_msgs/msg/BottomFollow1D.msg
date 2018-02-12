# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

float64 depth_bot
float64[2] depth_env
float64 depth_goal
float64 ref_speed
float64 depth_rate_filtered
float64[5] past_altitude_values
float64 median_altitude
float64 env_padding_speed
float64 env_padding_accel
float64 step

duration time_inside_env
duration alt_bad_timer

time last_good_altitude_time
time last_good_altitude
time last_good_depth
time last_good_depth_bot
time time_low_depth_rate
time last_altitude_time

bool alarm
bool stuck

int8 pseudo_bot_code

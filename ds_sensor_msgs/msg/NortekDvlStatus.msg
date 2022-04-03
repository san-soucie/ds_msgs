# DVL status as reported by the Nortek DVL
# It is a uint32 bitmapped to the following flags
# Also see Table 9 in the Nortek DVL Integrators guide

ds_core_msgs/DsHeader ds_header

uint32 dvl_status

bool beam1_vel_valid
bool beam2_vel_valid
bool beam3_vel_valid
bool beam4_vel_valid
bool beam1_dist_valid
bool beam2_dist_valid
bool beam3_dist_valid
bool beam4_dist_valid
bool beam1_fom_valid
bool beam2_fom_valid
bool beam3_fom_valid
bool beam4_fom_valid
bool x_vel_valid
bool y_vel_valid
bool z1_vel_valid
bool z2_vel_valid
bool x_fom_valid
bool y_fom_valid
bool z1_fom_valid
bool z2_fom_valid
bool three_pct_cpu_left
bool six_pct_cpu_left
bool twelve_pct_cpu_left
string wakeup_state



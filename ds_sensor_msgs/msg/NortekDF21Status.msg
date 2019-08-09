# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

##############
# DVL Status #
##############

bool b1_vel_valid
bool b2_vel_valid
bool b3_vel_valid
bool b4_vel_valid

bool b1_dist_valid
bool b2_dist_valid
bool b3_dist_valid
bool b4_dist_valid

bool b1_fom_valid
bool b2_fom_valid
bool b3_fom_valid
bool b4_fom_valid

bool x_vel_valid
bool y_vel_valid
bool z1_vel_valid
bool z2_vel_valid

bool x_fom_valid
bool y_fom_valid
bool z1_fom_valid
bool z2_fom_valid

int8 proc_cap
string wakeup_state

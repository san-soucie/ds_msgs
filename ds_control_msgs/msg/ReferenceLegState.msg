# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

geometry_msgs/Vector3 line_start
geometry_msgs/Vector3 line_end

float64 angle_line_segment
float64 off_line_vect
float64 kappa
float64 sign_of_vect
float64 delta_hdg
float64 delta_hdg_wrapped
float64 new_goal
float64 new_goal_wrapped
float64 old_ref
float64 old_goal


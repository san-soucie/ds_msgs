time stamp

# XR Index
int idx

# Actual state of things, as of last report
bool[] dcams_actual
bool[] wires_actual

# Currently-commanded state
bool[] dcam_cmds
bool[] wire_cmds

# Countdown timers
uint8 XR_COUNTDOWN_DISABLE=0
uint8 XR_COUNTDOWN_EXPIRED=1
uint8[] dcam_countdown_sec
uint8[] wire_countdown_sec
uint8 deadman_hours


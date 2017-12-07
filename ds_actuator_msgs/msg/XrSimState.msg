XrState state

# Actual values stored internally--
# state is just what's reported
float32 dcam_countdown_sec
float32 wire_countdown_sec
float32 deadman_hours

# How open a dcam is (from 0% to 100%)
float32[] dcam_open_pct

# Values for burned a wire is.  From "100" for fully intact to "0" 
# for fully burned
float32[] wire_burn_pct

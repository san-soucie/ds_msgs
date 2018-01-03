# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

####################
# DVL fixed leader #
####################
uint8 fw_ver #TODO: IMPORTANT-->DVLDATA
uint8 fw_rev
uint32 config_khz
#75, 150, 300, or 600
bool config_convex
#1 for convex, 0 for concave
uint8 config_sensornum
#1, 2, or 3
bool config_xdcr
#1 for attached, 0 for unattached
bool config_up
#1 for up, 0 for down
uint16 config_beamangle
#15E, 20E, 30E, or 0 for other
uint8 config_janus
#4 for 4 beam, 5 for 5 beam demod, 15 for 5 beam 2 demod
uint8 real_sim
#0=real is default
uint8 lag
uint8 beams #TODO: IMPORTANT-->DVLDATA
uint8 cells
uint8 pings
uint8 cell_depth
uint16 blank
uint8 signal_proc
#Always =1
uint8 min_thresh
#WHAT IS THIS?
uint8 code_reps
uint8 min_good_pings
uint16 good_thresh

#
duration ping_interval
#Time between ping intervals
uint8 coord_mode
bool coord_tilts
bool coord_3beam
bool coord_binmapping
uint16 hdng_align
#ea-command
uint16 hdng_bias
#eb-command
uint8 sensor_src
#ez-command
uint8 sensor_avail
#same as sensor_src pattern
float32 bin1_dist
#-->m
uint16 xmit_pulse_len
uint8 avg_start
uint8 avg_end
uint8 avg_false_thresh
uint16 trans_lag_dist
uint64 serial_num_cpu #TODO: IMPORTANT-->DVLDATA
uint16 wb_cmd
#range 0 to 1
uint8 power
uint32 serial_num #TODO: IMPORTANT-->DVLDATA
uint8 beam_angle


#######################
# DVL variable leader #
#######################
uint32 ensemble_num

uint8 BIT

time rtc_time #Real-time clock for current data ensemble #TODO: IMPORTANT-->DVLDATA
bool error_demod1
#flags from bit result
bool error_demod0
bool error_timingcard
uint32 sound_vel #ec --> m/s #TODO: IMPORTANT-->DVLDATA
float64 depth
#ed --> m
float64 heading
#eh --> degrees
float64 pitch
#ep --> degrees
float64 roll
#er --> degrees
uint16 salinity
#es -->ppm?
float64 temperature
#et -->deg C or deg F

duration mpt_wait
#Minimum prep-ping waiting time
uint8 heading_std
#standard deviations
float64 pitch_std
float64 roll_std
uint64 adc
#analog-digital converter from dsp board

#    uint32 error_status_word
#Low lsb, msb :: High lsb, msb -->interpret
bool error_busexception
#error_status_word0
bool error_address
bool error_illegalinstruction
bool error_zerodivide
bool error_emulator
bool error_unassigned
bool error_watchdogrestart
bool error_batterysaver
bool error_pinging
#error_status_word1
bool error_coldwakeup
bool error_unknwakeup
bool error_clockread
#error_status_word2
bool error_unexpectedalarm
bool error_clockforward
bool error_clockbackward
bool error_powerfail
#error_status_word3
bool error_interrupt4dsp
bool error_interrupt5uart
bool error_interrupt6clock
bool error_interrupt7
float64 pressure
float64 pressure_variance

time y2k_time
#Y2K-compliant real-time clock for current data ensemble
#TODO: IMPORTANT-->DVLDATA


####################
# DVL bottom track #
####################
uint16 pings_per_ensemble
uint16 delay
uint8 corr_mag_min
uint8 eval_amp_min
uint8 percent_good_min
uint8 mode
#TODO: IMPORTANT-->DVLDATA
float64 err_vel_max
float64[4] range
#    +uint32 range_msb
#TODO: IMPORTANT-->DVLDATA
float64[4] velocity
#TODO: IMPORTANT-->DVLDATA
float64[4] correlation
#TODO: IMPORTANT-->DVLDATA
uint32 echo_ampl
uint32 percent_good
#TODO: IMPORTANT-->DVLDATA
uint16 ref_min
#minimum layer size, near boundary, and far boundary for BT water-reference layer
float32 ref_near
float32 ref_far
float64 ref_velocity
#TODO: IMPORTANT-->DVLDATA
float64 ref_correlation
#TODO: IMPORTANT-->DVLDATA
uint32 ref_intensity
uint32 ref_percent_good
#TODO: IMPORTANT-->DVLDATA
float64 depth_max
float32 rssi_amp
#Receiver Signal Strength indicator
uint8 gain
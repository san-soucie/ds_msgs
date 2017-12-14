##float32 NO_DOPPLER_VELOCITY_MSG

##std/Headers header

##int simulate
### ID of a DVL in a vehicle, to account for multiple DVLs.
##uint32 dvl_number

### ENUM: DVL input mode
##uint8 DVL_INPUT_MODE_CSERIAL=0
##uint8 DVL_INPUT_MODE_TCP=1

### ENUM: DVL model
##uint8 DVL_MODEL_WORKHORSE=0
##uint8 DVL_MODEL_EXPLORER=1

##uint32 pd_mode

##ds_sensor_msgs/AcousticCurrentProfile adcp
##uint64 rst_dvl_timestamp
##uint8 dvl_model
##uint8 input_mode
##uint8 lcm_channel
##uint32 config_dvl

# Device-specific status
ds_sensor_msgs/DvlStatus status

# struct rdidvl_t from lcm/rdidvl/rdidvl_t.lcm
uint64 utime

# 30 NOV 2003  LLW    Added support for PD3 Mode
int16 pd_mode
byte START_OF_DATA_CHAR
int16 MAX_VALID_DATA_LEN
float64 t
#seconds since start of day, good to .01

# these fields reflect the RAW values received from the DVL in PD5 mode
# these are parsed directly out of the PD5 data block
float64 heading
 #radians
float64 pitch
#radians
float64 roll
#radians
float64 sv
#in meter/sec
float64 salinity
 #in parts per thousand
float64 temp
#in deg C
float64 depth
#in meters
float64 range[4]
 #ranges from the 4 beams, not corrected for angles


# Note that in PD0 mode the range is reported in


# distinct fields for MSB and LSB
float64 altitude
 #altitude, set to 0.0 when bad
float64 bt[4]
#displacement, bottom referenced
float64 btv[4]
#velocity, bottom referenced
byte       bt_status
#status of bottom track
float64 wt[4]
#displacement, referenced to water mass
float64 wtv[4]
#velocity, referenced to water mass
byte         wt_status
#status of water mass track

# bottom track fields added 11 April 1998 LLW
# these fields reflect the RAW values received from the DVL in PD5 mode
float64 bt_last_good_vel_time
uint16 bt_count_012_beam
uint16 bt_count_3_beam
uint16 bt_count_4_beam
uint16 bt_beams_this_solution
 #is solution 3-beam or 4-beam?
#float64   bt_time_since_good_solution
float64 btv_err_mean
float64 btv_err_std
float64 btv_err_sum
float64 btv_err_sum_sq
float64 bt_cog
#course over ground in radians
float64 bt_sog
#speed over ground in m/s
uint16 new_good_bt
#this is set to 1 when a new valid DVL BT ping is received


# then set to zero when the WT data has been processed


# by higher level dvlnav code, to preclude multiple processing
# of the same ping
# water track fields added 11 April 1998 LLW
float64 wt_last_good_vel_time
uint16 wt_count_012_beam
uint16 wt_count_3_beam
uint16 wt_count_4_beam
uint16 wt_beams_this_solution
 #is solution 3-beam or 4-beam?
#float64     wt_time_since_good_solution
float64 wtv_err_mean
float64 wtv_err_std
float64 wtv_err_sum
float64 wtv_err_sum_sq
float64 wt_cow
#course over water layer in radians
float64 wt_sow
#speed over water layer in m/s
uint16 new_good_wt
#this is set to 1 when a new valid DVL WT ping is received


# then set to zero when the WT data has been processed


# by higher level dvlnav code, to preclude multiple processing
# of the same ping
# status fields
byte         config

#dvl config bitmap
byte       bIT

#dvl self-test bitmap
float64 wlm
float64 wln
#ref water layer near in meters
float64 wlf
#ref water layer far in meters

# fields appearing only in PD3
byte         DTF
byte         SOD
byte         DVLALT
#08-31-2007 JCK - this variable is named ALT in DVLNAV code remaned to eliminate conflcit with#define ALT in navest_talk.h

# serial I/O and logging fields added 11 April 1998 LLW
uint16 new_dvl_string
#this is set to 1 when a new dvl string is received, even if ping data is bad
uint16 nrecords
#number of records successfully parsed
uint16 nbadrecords
#number of records unsuccessfully parsed
byte         most_recent_checksum_computed# checksum computed from last string
byte         most_recent_checksum_received# checksum recieved varbatim in last string
float64 most_recent_string_time
#time of most rercent dvl string  - PC Unix Time
float64 most_recent_string_delta_time# time since most rercent dvl string  - from PC Unix Time Stamps
float64 wh_sec_since_midnight
#dvl clock time last ensemble - From Doppler DSP Clock
float64 wh_delta_t
#dvl delta clock time last ensemble - Computed From Doppler DSP Clock
#byte       most_recent_pd_string[10240]
#most recent binary string
#uint16    most_recent_dvl_fix_method
#0=none (bad fix), 1=bottom track, 2=water track

#pd0 add-ons
#variable header info
float64 zvect_trans[4]
# April XX 2004 SCM  Added PD0 entries to dvl_t data structure
# 04-28-2009 JCK - below added from dvlnav v211
byte header_id
byte source_id
uint16 num_of_bytes
#contains the number of bytes in this ensemble
# 04-28-2009 JCK - above added from dvlnav v211
uint16 num_types
#contains number of datatypes
#fixed header
uint16 fw_ver
#Version number of firmware
uint16 fw_rev
#Revision number of firmware
uint16 sys_config_msb
#defines work horse hardware config
uint16 sys_config_lsb
#defines work horse hardware config
uint16 number_of_cells
#number of depth cells for water column profiling
uint16 pings_per_ensemble
#number of pings averaged together during a data ensemble
float64 depth_cell_len
#contains phsyical length of one depth cell for water column profiling
uint16 profile_mode
#Signal Processing Mode = 1
uint16 low_corr
#Minimum Threshold of Correlation
uint16 code_reps
#Number of repititions in Transmit pulse
uint16 good_per_min
 #Minimum Percentage good
float64 vel_err_thre
#Threshold Error in Velocity
uint16 tp_min
#set by tp command
uint16 tp_sec
uint16 tp_hun
uint16 coor_trans
#Coordinate transformation
float64 head_align
#Contains Correctin factor for Physical Misalignment
float64 head_bias
#Contains Correction factor for Magnetic/Electrical misalignment
uint16 sensor_source
#Selected source of enviornment sensor data
uint16 sensor_avail
#Reflects whether speed of sound is available
float64 bin1_distance
#Distance to middle of first bin
float64 xmit_pulse_len
#Set by WT its the length of xmit pulse
uint16 wl_wp
#Contains starting depth cell and ending depth celll
uint16 wa_false_tgt
#Contains the threshold value used to reject data recieved from falxe target
float64 xmit_lag_dist
#wm set value
uint16 cpu_num
#serial number of cpu board
uint16 sys_band
#wb command setting
uint16 sys_pow
#cq command setting
uint16 vel_id
uint16 corr_id
uint16 ech_id
uint16 per_id
uint16 flag

#variable header
uint16 ensemble_number
#This field contains the sequential number of the field
uint16 ensemble_number_msb
#after first increment this keeps track of sequential number roll over
uint16 mpt_min
#contains Miniumum Pre-Ping Wait time
uint16 mpt_sec
uint16 mpt_hun
float64 std_hdg
#std deviation of heading and tilt sensors


#11-24-2007 16:59:29 JCK - changed this from an int to a float64
float64 std_pit
float64 std_rol
uint16 adchannel[8]
#output of ADC
uint16 err_stat[4]
#Contains long word containing the bit flags for the CY? command
float64 pressure
#pressure of water outside ducer relative to 1 atm
float64 pressure_var
#variance of pressure

#  2013-11-06 JCK - lcm structures can't handle rov_time_struct_t so
#  we hard define it here.  these fields are rarely used in navest
#  do there are minimal problems downstream

uint16 pd0_time_year
uint16 pd0_time_month
uint16 pd0_time_day
uint16 pd0_time_hour
uint16 pd0_time_min
uint16 pd0_time_sec_int
uint16 pd0_time_msec_int
uint16 number_of_beams

#bt data format
uint16 bt_bp
#stores number of pings to bt pings averaged
uint16 bt_bd
#stores number of ADCP ensembles to wait after losing the botom
uint16 bt_corr_min
#correlation min amplitude
uint16 bt_amp_min
#minimum evaluation amplitude value
uint16 bt_per_good_min
#minimum percent good value
uint16 bt_bm_mode
#bottom track mode
float64 bt_er_vel_max
#threshold max velocity error
uint16 bt_corr[4]
#bt correlation magnitude
uint16 bt_amp[4]
#bt evaluation amp value
uint16 bt_per_good[4]
#bt percent good value
uint16 wl_corr[4]
#water layer correlation magnitude
uint16 wl_echo_int[4]
#water layer echo intensity
uint16 wl_per_good[4]
#water layer percent good valuev
float64 bt_rssi_amp[4]
#Reciever Signal Strength Indicator
uint16 bt_range_lsbs[4]
#two most  signicant bytes of vertical range from ADCP, SS+JCK changed from byte to uint16
byte bt_range_msb[4]
#two least signicant bytes of vertical range from ADCP
float64 bx_max_depth
#Store max tracking depth
uint16 wj_gain
#Contains Gain level for shallow water
uint16 dvl_number

uint16 pd0_variable_data_type[128]
#data type codes for variable data
uint16 pd0_variable_data_offset[128]
# address of each variable data type
float64 pd0_velocity[128][16]
#data from pdo
float64 pd0_velocity_out[128][16]
#data from pdo
uint16 pd0_wcv_used_flag[128]
#04-28-2009 JCK - added
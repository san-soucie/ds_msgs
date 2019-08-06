# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

#################
# DVL processed #
#################

float64 altitude_sum
float64 speed_gnd
float64 course_gnd
uint8 good_beams
float64 dvl_time

################
# DF21/22 Mode #
################

#  All distances are in m, velocities in m/s, intensities in dB

uint8 version
uint8 offsetOfData
uint32 serialNumber
uint8 year
uint8 month
uint8 day
uint8 hour
uint8 minute
uint8 seconds
uint16 microSeconds
uint16 nBeams
uint32 error
uint32 status # MAY NOT BE VALID
float64 soundSpeed
float64 temperature
float64 pressure

#############
# Beam Data #
#############

float64[4] velBeam    #Velocities for each beam
float64[4] distBeam   #Distances for each beam
float64[4] fomBeam    #Figure of merit for each beam
float64[4] timeDiff1Beam  #DT1 for each beam
float64[4] timeDiff2Beam  #DT2 for each beam
float64[4] timeVelEstBeam #Duration of velocity estimate for each beam

#############
# XYZ Data #
#############
float64 velX  #Velocity X
float64 velY  #Velocity Y
float64 velZ1 #Velocity Z1
float64 velZ2 #Velocity Z2
float64 fomX  #Figure of Merit X
float64 fomY  #Figure of Merit Y
float64 fomZ1 #Figure of Merit Z1
float64 fomZ2 #Figure of Merit Z2
float64 timeDiff1X    #Time from trigger to center of bottom echo
float64 timeDiff1Y    #Same as above
float64 timeDiff1Z1   #Same as above
float64 timeDiff1Z2   #Same as above
float64 timeDiff2X    #Time from start of NMEA output msg to center of bottom echo
float64 timeDiff2Y    #Same as above
float64 timeDiff2Z1   #Same as above
float64 timeDiff2Z2   #Same as above
float64 timeVelEstX   #Duration of velocity estimate for each component
float64 timeVelEstY   #Same as above
float64 timeVelEstZ1  #Same as above
float64 timeVelEstZ2  #Same as above
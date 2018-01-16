#  Values of PHINS Sensor status LSB (see Table V-6)

uint32 DATA_READY_ERROR              = 1          # 0x00000001
uint32 SRC_POWER_ERROR               = 2          # 0x00000002
uint32 SRC_DIODE_ERROR               = 4          # 0x00000004
uint32 SRC_MODE_ERROR                = 8          # 0x00000008

uint32 FOG_X_OVER_DYN_LG             = 16         # 0x00000010
uint32 FOG_Y_OVER_DYN_LG             = 32         # 0x00000020
uint32 FOG_Z_OVER_DYN_LG             = 64         # 0x00000040
uint32 ACC_X_ACQ_ERROR               = 128        # 0x00000080

uint32 ACC_Y_ACQ_ERROR               = 256        # 0x00000100
uint32 ACC_Z_ACQ_ERROR               = 512        # 0x00000200
uint32 FOG_X_STAT_ERROR              = 1024       # 0x00000400
uint32 FOG_Y_STAT_ERROR              = 2048       # 0x00000800

uint32 FOG_Z_STAT_ERROR              = 4096       # 0x00001000
uint32 FOG_X_VPI_ERROR               = 8192       # 0x00002000
uint32 FOG_Y_VPI_ERROR               = 16384      # 0x00004000
uint32 FOG_Z_VPI_ERROR               = 32768      # 0x00008000

uint32 RESERVED                      = 65536      # 0x00010000
uint32 FOG_X_OVER_DYN                = 131072     # 0x00020000
uint32 FOG_Y_OVER_DYN                = 262144     # 0x00040000
uint32 FOG_Z_OVER_DYN                = 524288     # 0x00080000

uint32 FOG_X_RX_ERROR                = 1048576    # 0x00100000
uint32 FOG_Y_RX_ERROR                = 2097152    # 0x00200000
uint32 FOG_Z_RX_ERROR                = 4194304    # 0x00400000
uint32 FOG_X_CRC_ERROR               = 8388608    # 0x00800000

uint32 FOG_Y_CRC_ERROR               = 16777216   # 0x01000000
uint32 FOG_Z_CRC_ERROR               = 33554432   # 0x02000000
uint32 TEMP_ACQ_ERROR                = 67108864   # 0x04000000
uint32 TEMP_THRESHOLD_ERROR          = 134217728  # 0x08000000

uint32 DIODE_TEMP_THRESHOLD_ERROR    = 268435456  # 0x10000000
uint32 FIFO_FULL_WARNING             = 536870912  # 0x20000000
uint32 FIFO_FULL_ERROR               = 1073741824 # 0x40000000
uint32 SRC_POWER_ERROR2              = 2147483648 # 0x80000000

uint32 flags

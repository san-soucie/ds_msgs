#  Values of PHINS Algo status LSB (see Table V-3)

uint32 OPERATION_MODE_NAVIGATION     = 1          # 0x00000001
uint32 OPERATION_MODE_ALIGNMENT      = 2          # 0x00000002
uint32 OPERATION_MODE_FINE_ALIGNMENT = 4          # 0x00000004
uint32 OPERATION_MODE_DECK_RECKONING = 8          # 0x00000008

uint32 ALTITUDE_USING_GPS            = 16         # 0x00000010
uint32 ALTITUDE_USING_DEPTH          = 32         # 0x00000020
uint32 ALTITUDE_SABLILIZED           = 64         # 0x00000040
uint32 ALTITUDE_HYDRO                = 128        # 0x00000080

uint32 LOG_USED                      = 256        # 0x00000100
uint32 LOG_DATA_VALID                = 512        # 0x00000200
uint32 LOG_WAITING_FOR_DATA          = 1024       # 0x00000400
uint32 LOG_DATA_REJECTED             = 2048       # 0x00000800

uint32 GPS_USED                      = 4096       # 0x00001000
uint32 GPS_DATA_VALID                = 8192       # 0x00002000
uint32 GPS_WAITING_FOR_DATA          = 16384      # 0x00004000
uint32 GPS_DATA_REJECTED             = 32768      # 0x00008000

uint32 USBL_USED                     = 65536      # 0x00010000
uint32 USBL_DATA_VALID               = 131072     # 0x00020000
uint32 USBL_WAITING_FOR_DATA         = 262144     # 0x00040000
uint32 USBL_DATA_REJECTED            = 524288     # 0x00080000

uint32 DEPTH_USED                    = 1048576    # 0x00100000
uint32 DEPTH_DATA_VALID              = 2097152    # 0x00200000
uint32 DEPTH_WAITING_FOR_DATA        = 4194304    # 0x00400000
uint32 DEPTH_DATA_REJECTED           = 8388608    # 0x00800000

uint32 LBL_USED                      = 16777216   # 0x01000000
uint32 LBL_DATA_VALID                = 33554432   # 0x02000000
uint32 LBL_WAITING_FOR_DATA          = 67108864   # 0x04000000
uint32 LBL_DATA_REJECTED             = 134217728  # 0x08000000

uint32 ALTITUDE_SATURATED            = 268435456  # 0x10000000
uint32 SPEED_SATURATED               = 536870912  # 0x20000000
uint32 RESERVED_1                    = 1073741824 # 0x40000000
uint32 RESERVED_2                    = 2147483648 # 0x80000000

uint32 flags
#  Values of PHINS Algo status MSB (see Table V-4)

uint32 WATER_TRACK_USED              = 1          # 0x00000001
uint32 WATER_TRACK_DATA_VALID        = 2          # 0x00000002
uint32 WATER_TRACK_WAITING_FOR_DATA  = 4          # 0x00000004
uint32 WATER_TRACK_REJECTED          = 8          # 0x00000008

uint32 GPS2_USED                     = 16         # 0x00000010
uint32 GPS2_DATA_VALID               = 32         # 0x00000020
uint32 GPS2_WAITING_FOR_DATA         = 64         # 0x00000040
uint32 GPS2_DATA_REJECTED            = 128        # 0x00000080

uint32 METROLOGY_USED                = 256        # 0x00000100
uint32 METROLOGY_DATA_VALID          = 512        # 0x00000200
uint32 METROLOGY_WAITING_FOR_DATA    = 1024       # 0x00000400
uint32 METROLOGY_DATA_REJECTED       = 2048       # 0x00000800

uint32 ALTITUDE_USED                 = 4096       # 0x00001000
uint32 ALTITUDE_DATA_VALID           = 8192       # 0x00002000
uint32 ALTITUDE_WAITING_FOR_DATA     = 16384      # 0x00004000
uint32 ALTITUDE_DATA_REJECTED        = 32768      # 0x00008000

uint32 OPERATION_MODE_ZUP            = 65536      # 0x00010000
uint32 ZUP_VALID                     = 131072     # 0x00020000
uint32 OPERATION_MODE_ZUP_VALID      = 262144     # 0x00040000
uint32 ZUP_BENCH_VALID               = 524288     # 0x00080000

uint32 STATIC_ALIGNMENT              = 1048576    # 0x00100000
uint32 GO_TO_NAV                     = 2097152    # 0x00200000
uint32 RESERVED_1                    = 4194304    # 0x00400000
uint32 RESERVED_2                    = 8388608    # 0x00800000

uint32 EM_LOG_USED                   = 16777216   # 0x01000000
uint32 EM_LOG_DATA_VALID             = 33554432   # 0x02000000
uint32 EM_LOG_WAITING_FOR_DATA       = 67108864   # 0x04000000
uint32 EM_LOG_DATA_REJECTED          = 134217728  # 0x08000000

uint32 GPS_MANUAL_USED               = 268435456  # 0x10000000
uint32 GPS_MANUAL_DATA_VALID         = 536870912  # 0x20000000
uint32 GPS_MANUAL_WAITING_FOR_DATA   = 1073741824 # 0x40000000
uint32 GPS_MANUAL_DATA_REJECTED      = 2147483648 # 0x80000000

uint32 flags

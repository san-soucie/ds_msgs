#  Values of PHINS Sensor status MSB (see Table V-7)

uint32 FOG_X_ERROR                   = 1          # 0x00000001
uint32 FOG_Y_ERROR                   = 2          # 0x00000002
uint32 FOG_Z_ERROR                   = 4          # 0x00000004
uint32 SRC_ERROR                     = 8          # 0x00000008

uint32 ACC_X_ERROR                   = 16         # 0x00000010
uint32 ACC_Y_ERROR                   = 32         # 0x00000020
uint32 ACC_Z_ERROR                   = 64         # 0x00000040
uint32 TEMP_ERROR                    = 128        # 0x00000080

uint32 CSDP_OVERLOAD                 = 256        # 0x00000100
uint32 RESERVED01                    = 512        # 0x00000200
uint32 RESERVED02                    = 1024       # 0x00000400
uint32 RESERVED03                    = 2048       # 0x00000800

uint32 RESERVED04                    = 4096       # 0x00001000
uint32 RESERVED05                    = 8192       # 0x00002000
uint32 RESERVED06                    = 16384      # 0x00004000
uint32 RESERVED07                    = 32768      # 0x00008000

uint32 RESERVED08                    = 65536      # 0x00010000
uint32 RESERVED09                    = 131072     # 0x00020000
uint32 RESERVED10                    = 262144     # 0x00040000
uint32 RESERVED11                    = 524288     # 0x00080000

uint32 RESERVED12                    = 1048576    # 0x00100000
uint32 RESERVED13                    = 2097152    # 0x00200000
uint32 RESERVED14                    = 4194304    # 0x00400000
uint32 RESERVED15                    = 8388608    # 0x00800000

uint32 RESERVED16                    = 16777216   # 0x01000000
uint32 RESERVED17                    = 33554432   # 0x02000000
uint32 RESERVED18                    = 67108864   # 0x04000000
uint32 RESERVED19                    = 134217728  # 0x08000000

uint32 RESERVED20                    = 268435456  # 0x10000000
uint32 RESERVED21                    = 536870912  # 0x20000000
uint32 OPERATION_MODE_DEGRADED       = 1073741824 # 0x40000000
uint32 FAILURE                       = 2147483648 # 0x80000000

uint32 flags

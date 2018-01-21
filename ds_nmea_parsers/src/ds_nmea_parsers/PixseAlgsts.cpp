
#include "ds_nmea_msgs/PixseAlgsts.h"

#include <endian.h>

namespace ds_nmea_msgs
{

bool from_string(PixseAlgsts& output, const std::string &nmea_string)
{

  uint32_t lsb;
  uint32_t msb;

  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,ALGSTS,%x,%x*%02hhx\r\n",
      &lsb, &msb, &output.checksum);

  if (n < 2) {
    return false;
  }

  lsb = le32toh(lsb);
  msb = le32toh(msb);

  output.status = (static_cast<uint64_t>(msb) << 32) + lsb;

  return true;
}


}

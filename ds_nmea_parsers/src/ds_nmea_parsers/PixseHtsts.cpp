
#include "ds_nmea_parsers/PixseHtsts.h"

namespace ds_nmea_msgs
{

bool from_string(PixseHtsts& output, const std::string &nmea_string)
{
  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,HT_STS,%x*%02hhx\r\n",
      &output.status, &output.checksum);

  if (n < 1) {
    return false;
  }

  return true;
}

}

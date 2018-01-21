
#include "ds_nmea_parsers/PixseSpeed.h"

namespace ds_nmea_msgs
{

bool from_string(PixseSpeed& output, const std::string &nmea_string)
{
  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,SPEED_,%lf,%lf,%lf*%02hhx\r\n",
      &output.east, &output.north, &output.vertical, &output.checksum);

  if (n < 3) {
    return false;
  }

  return true;
}

}

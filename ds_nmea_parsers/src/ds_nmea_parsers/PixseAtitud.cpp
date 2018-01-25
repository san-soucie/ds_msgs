#include "ds_nmea_parsers/PixseAtitud.h"

namespace ds_nmea_msgs
{

bool from_string(PixseAtitud& output, const std::string &nmea_string)
{
  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,ATITUD,%lf,%lf*%02hhx\r\n", &output.roll, &output.pitch, &output.checksum);

  if (n < 2) {
    return false;
  }

  return true;
}

}

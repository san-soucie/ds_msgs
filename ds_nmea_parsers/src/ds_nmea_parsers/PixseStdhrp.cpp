
#include "ds_nmea_parsers/PixseStdhrp.h"

namespace ds_nmea_msgs
{
bool from_string(PixseStdhrp& output, const std::string &nmea_string)
{
  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,STDHRP,%lf,%lf,%lf*%02hhx\r\n",
      &output.heading, &output.roll, &output.pitch, &output.checksum);

  if (n < 3) {
    return false;
  }

  return true;
}

}

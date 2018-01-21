
#include "ds_nmea_parsers/PixsePositi.h"

namespace ds_nmea_msgs
{
bool from_string(PixsePositi& output, const std::string &nmea_string)
{
  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,POSITI,%lf,%lf,%lf*%02hhx\r\n",
      &output.latitude, &output.longitude, &output.altitude, &output.checksum);

  if (n < 3) {
    return false;
  }

  return true;
}

}


#include "ds_nmea_parsers/PixseHeave.h"

namespace ds_nmea_msgs
{

bool from_string(PixseHeave& output, const std::string &nmea_string)
{
  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,HEAVE_,%lf,%lf,%lf*%02hhx\r\n",
      &output.surge, &output.sway, &output.heave, &output.checksum);

  if (n < 3) {
    return false;
  }

  return true;
}

}

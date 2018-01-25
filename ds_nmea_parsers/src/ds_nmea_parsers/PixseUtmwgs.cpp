
#include "ds_nmea_parsers/PixseUtmwgs.h"

namespace ds_nmea_msgs
{

bool from_string(PixseUtmwgs& output, const std::string &nmea_string)
{
  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,UTMWGS,%1c,%hu,%lf,%lf,%lf*%02hhx\r\n",
      &output.latitude_utm_zone, &output.longitude_utm_zone, &output.eastings,
      &output.northings, &output.altitude, &output.checksum);

  if (n < 5) {
    return false;
  }

  return true;
}

}

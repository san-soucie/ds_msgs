
#include "ds_nmea_parsers/PixseHspos.h"
#include "ds_nmea_parsers/util.h"

namespace ds_nmea_msgs
{

bool from_string(PixseHspos& output, const std::string &nmea_string)
{

  auto hour = int{0};
  auto minute = int{0};
  auto second = 0.0;

  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,HSPOS_,%02d%02d%lf,%lf,%1c,%lf,%1c,%lf,%lf,%lf,%lf,%lf,%hd,%1c,%lf,%lf,%lf,%lf,%lf\r\n",
      &hour, &minute, &second, &output.latitude, &output.latitude_dir, &output.longitude, &output.longitude_dir,
      &output.depth, &output.altitude, &output.latitude_stdev, &output.longitude_stdev, &output.depth_stdev,
      &output.longitude_utm_zone, &output.latitude_utm_zone, &output.eastings, &output.northings,
      &output.heading_misalignment, &output.heading_misalignment_scale_factor, &output.sound_velocity);

  if (n < 19) {
    return false;
  }

  output.timestamp = from_nmea_utc(hour,  minute, second);

  return true;
}


}

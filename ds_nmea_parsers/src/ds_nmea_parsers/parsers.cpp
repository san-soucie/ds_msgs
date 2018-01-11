#include "ds_nmea_parsers/parsers.h"

namespace ds_nmea_msgs
{

bool from_string(Hdt& output, const std::string &nmea_string)
{
  auto true_flag = char{0};

  const auto n = sscanf(
      nmea_string.c_str(), "$%*2cHDT,%lf,%1c*%02hhx\r\n", &output.heading, &true_flag, &output.checksum);

  if (n < 1) {
    return false;
  }

  if (n >= 3)
  {
    output.is_true = static_cast<unsigned char>(true_flag == 'T');
  }
  return true;
}

bool from_string(PixseAtitud& output, const std::string &nmea_string)
{
  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,ATITUD,%lf,%lf*%02hhx\r\n", &output.roll, &output.pitch, &output.checksum);

  if (n < 2) {
    return false;
  }

  return true;
}

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

bool from_string(PixseUtmwgs& output, const std::string &nmea_string)
{
  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,UTMWGS,%1c,%hu,%lf,%lf,%lf,*%02hhx\r\n",
      &output.latitude_utm_zone, &output.longitude_utm_zone, &output.eastings,
      &output.northings, &output.altitude, &output.checksum);

  if (n < 5) {
    return false;
  }

  return true;
}

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

bool from_string(PixseStdhrp& output, const std::string &nmea_string)
{
  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,STDRPH,%lf,%lf,%lf*%02hhx\r\n",
      &output.heading, &output.roll, &output.pitch, &output.checksum);

  if (n < 3) {
    return false;
  }

  return true;
}

bool from_string(PixseStdpos& output, const std::string &nmea_string)
{
  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,STDPOS,%lf,%lf,%lf*%02hhx\r\n",
      &output.latitude, &output.longitude, &output.altitude, &output.checksum);

  if (n < 3) {
    return false;
  }

  return true;
}

bool from_string(PixseStdspd& output, const std::string &nmea_string)
{
  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,STDSPD,%lf,%lf,%lf*%02hhx\r\n",
      &output.east, &output.north, &output.vertical, &output.checksum);

  if (n < 3) {
    return false;
  }

  return true;
}

bool from_string(PixseAlgsts& output, const std::string &nmea_string)
{
  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,ALGSTS,%x,%x*%02hhx\r\n",
      &output.lsb, &output.msb, &output.checksum);

  if (n < 2) {
    return false;
  }

  return true;
}

bool from_string(PixseStatus& output, const std::string &nmea_string)
{
  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,STATUS,%x,%x*%02hhx\r\n",
      &output.lsb, &output.msb, &output.checksum);

  if (n < 2) {
    return false;
  }

  return true;
}

bool from_string(PixseHtsts& output, const std::string &nmea_string)
{
  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,HT_STS,%x*%02hhx\r\n",
      &output.lsb, &output.checksum);

  if (n < 1) {
    return false;
  }

  return true;
}

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

  // Convert the timestamp into a ros::Time  object.  There's got to be an easier way to do this
  // with std::chrono...

  auto now_seconds = static_cast<std::time_t>(ros::Time::now().toSec());
  auto tm_ = std::gmtime(&now_seconds);
  if(tm_ == nullptr) {
    return false;
  }

  // Make a copy immediately
  auto tm = *tm_;

  // Reset time
  tm.tm_hour = hour;
  tm.tm_min = minute;
  tm.tm_sec = 0; // leave 0, we'll add it by hand later.

  // recalculate seconds past epoch from tm
  auto timestamp = std::mktime(&tm);
  output.timestamp.fromSec(static_cast<int>(timestamp) + second);
  return true;
}

}

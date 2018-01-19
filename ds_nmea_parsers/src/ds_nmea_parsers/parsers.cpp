#include "ds_nmea_parsers/parsers.h"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/lexical_cast.hpp>

#include <endian.h>

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
      nmea_string.c_str(), "$PIXSE,UTMWGS,%1c,%hu,%lf,%lf,%lf*%02hhx\r\n",
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
      nmea_string.c_str(), "$PIXSE,STDHRP,%lf,%lf,%lf*%02hhx\r\n",
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

bool from_string(PixseStatus& output, const std::string &nmea_string)
{
  uint32_t lsb;
  uint32_t msb;
  const auto n = sscanf(
      nmea_string.c_str(), "$PIXSE,STATUS,%x,%x*%02hhx\r\n",
      &lsb, &msb, &output.checksum);

  if (n < 2) {
    return false;
  }

  lsb = le32toh(lsb);
  msb = le32toh(msb);

  output.status = (static_cast<uint64_t>(msb) << 32) + lsb;

  return true;
}

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

bool from_string(Gga& output, const std::string &nmea_string)
{
  auto fields = std::vector<std::string>{};
  boost::split(fields, nmea_string, boost::is_any_of(","));

#if 0
  if (fields.size() < 14) {
    return false;
  }
  //         1         2      3 4        5 6 7  8   9   10 |  12 13  14   15
  //         |         |      | |        | | |  |   |   |  |  |  |   |    |
  // $--GGA,hhmmss.ss,llll.ll,a,yyyyy.yy,a,x,xx,x.x,x.x,M,x.x,M,x.x,xxxx*hh
  //  1) Time (UTC)
  //  2) Latitude
  //  3) N or S (North or South)
  //  4) Longitude
  //  5) E or W (East or West)
  //  6) GPS Quality Indicator,
  //  0 - fix not available,
  //  1 - GPS fix,
  //  2 - Differential GPS fix
  //  7) Number of satellites in view, 00 - 12
  //  8) Horizontal Dilution of precision
  //  9) Antenna Altitude above/below mean-sea-level (geoid)
  // 10) Units of antenna altitude, meters
  // 11) Geoidal separation, the difference between the WGS-84 earth ellipsoid and mean-sea-level (geoid), "-" means mean-sea-level below ellipsoid
  // 12) Units of geoidal separation, meters
  // 13) Age of differential GPS data, time in seconds since last SC104 type 1 or 9 update, null field when DGPS is not used
  // 14) Differential reference station ID, 0000-1023
  // 15) Checksum

  auto msg = ds_nmea_msgs::Gga{};
  msg.timestamp = ros::Time::now();

  try {
    msg.latitude = boost::lexical_cast<double>(fields.at(1));
  }
  catch (boost::bad_lexical_cast&) {
    msg.latitude = Gga::GGA_NO_DATA;
  }

  try {
    msg.latitude_dir = boost::lexical_cast<uint8_t>(fields.at(2));
  }
  catch (boost::bad_lexical_cast&) {
    msg.latitude_dir = 'N';
  }

  try {
    msg.longitude = boost::lexical_cast<double>(fields.at(3));
  }
  catch (boost::bad_lexical_cast&) {
    msg.longitude = Gga::GGA_NO_DATA;
  }

  try {
    msg.longitude_dir = boost::lexical_cast
  }
#endif

  return {};
}

}

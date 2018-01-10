#include "ds_nmea_msgs/util.h"

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

}

#include "ds_nmea_parsers/Gll.h"
#include "ds_nmea_parsers/util.h"

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

namespace ds_nmea_msgs
{

bool from_string(Gll& output, const std::string &nmea_string)
{
  auto hour = int{0};
  auto minute = int{0};
  auto second = 0.0;

  // Set defaults
  output.talker.clear();
  output.latitude = Gll::GLL_NO_DATA;
  output.latitude_dir = 0;
  output.longitude = Gll::GLL_NO_DATA;
  output.longitude_dir = 0;
  output.status = Gll::GLL_DATA_INVALID;
  output.checksum = 0;

  // The GLL NMEA string can have lots of empty fields.  So we can't rely
  // on a standard sscanf with the whole message definition.
  //
  // Instead we'll split the message into substrings and use sscanf on each
  // part.  This is certainly not the most efficient way to do things BUT
  // we know that sscanf never generates exceptions (unlike boost::lexical_cast,
  // or some of the newer std::strtoX methods).  At worst we get bad data,
  // but at lest we don't have a lot of try/catch blocks.

  auto fields = std::vector<std::string>{};
  boost::split(fields, nmea_string, boost::is_any_of(",*"));

  // Expect at LEAST 14 fields.
  if (fields.size() < 7) {
    return false;
  }

  // .       1      2 3        4 5         6 7
  //         |      | |        | |         | |
  // $--GLL,llll.ll,a,yyyyy.yy,a,hhmmss.ss,A*hh
  // 1) Latitude
  // 2) N or S (North or South)
  // 3) Longitude
  // 4) E or W (East or West)
  // 5) Time (UTC)
  // 6) Status A - Data Valid, V - Data Invalid
  // 7) Checksum

  auto i = 0;
  char talker[2];
  if (!sscanf(fields.at(i++).c_str(), "$%2cGLL", talker)) {
    return false;
  }
  output.talker = std::string{std::begin(talker), std::end(talker)};

  sscanf(fields.at(i++).c_str(), "%lf", &output.latitude);
  output.latitude = nmea_dec_min_dec_degrees(output.latitude);
  sscanf(fields.at(i++).c_str(), "%1c", &output.latitude_dir);

  sscanf(fields.at(i++).c_str(), "%lf", &output.longitude);
  output.longitude = nmea_dec_min_dec_degrees(output.longitude);
  sscanf(fields.at(i++).c_str(), "%1c", &output.longitude_dir);

  // Break the first field into time components and create a ros::Time from it.
  if (sscanf(fields.at(i++).c_str(),"%02d%02d%lf", &hour, &minute, &second) != 3) {
    return false;
  }
  output.timestamp = from_nmea_utc(hour, minute, second);

  sscanf(fields.at(i++).c_str(), "%1c", &output.status);

  if (fields.size() > 7) {
    sscanf(fields.at(i++).c_str(), "%hhx", &output.checksum);
  }

  return true;
}

}

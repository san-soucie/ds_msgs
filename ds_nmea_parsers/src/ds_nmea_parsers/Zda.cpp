//
// Created by ivaughn on 3/25/18.
//


#include "ds_nmea_parsers/Zda.h"
#include "ds_nmea_parsers/util.h"

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <iostream>

namespace ds_nmea_msgs
{

bool from_string(Zda& output, const std::string &nmea_string)
{
  int year = 0;
  int month = 0;
  int day = 0;
  int hour = 0;
  int minute = 0;
  double second = 0.0;

  int zone_offset_hour = 0;
  int zone_offset_minute = 0;

  // Set defaults
  output.talker.clear();
  output.utc_time = ros::Time();
  output.zone_offset = ros::Duration();
  output.checksum = 0;

  // In keeping with the other NMEA messages, we'll split into substrings and convert them.
  //
  // Instead we'll split the message into substrings and use sscanf on each
  // part.  This is certainly not the most efficient way to do things BUT
  // we know that sscanf never generates exceptions (unlike boost::lexical_cast,
  // or some of the newer std::strtoX methods).  At worst we get bad data,
  // but at lest we don't have a lot of try/catch blocks.

  auto fields = std::vector<std::string>{};
  boost::split(fields, nmea_string, boost::is_any_of(",*"));

  // Expect at LEAST 6 fields.
  if (fields.size() < 6) {
    return false;
  }

  // ZDA Time of day
  //            1     2 3 4 5 6 7
  //            |     | | | | | |
  // $--ZDA,hhmmss.ss,x,x,x,x,x*hh
  // 1). UTC Time (hhmmss.ss format)
  // 2). Day (01-31)
  // 3). Month (01-12)
  // 4). Year (4-digit)
  // 5). Local zone description, 00 to +/- 13 hours
  // 6). Local zone minutes description (same sign as hours)
  // 7). Checksum

  auto i = 0;
  char talker[2];
  if (!sscanf(fields.at(i++).c_str(), "$%2cZDA", talker)) {
    return false;
  }

  output.talker = std::string{std::begin(talker), std::end(talker)};
  // Break the first field into time components and create a ros::Time from it.
  if (sscanf(fields.at(i++).c_str(),"%02d%02d%lf", &hour, &minute, &second) != 3) {
    return false;
  }
  if (sscanf(fields.at(i++).c_str(), "%d", &day) != 1) {
    return false;
  }
  if (sscanf(fields.at(i++).c_str(), "%d", &month) != 1) {
    return false;
  }
  if (sscanf(fields.at(i++).c_str(), "%d", &year) != 1) {
    return false;
  }
  output.utc_time = from_nmea_utc_date(year, month, day, hour, minute, second);

  // Convert the timezone offset
  if (sscanf(fields.at(i++).c_str(), "%d", &zone_offset_hour) != 1) {
    zone_offset_hour = 0;
  }
  if (sscanf(fields.at(i++).c_str(), "%d", &zone_offset_minute) != 1) {
    zone_offset_minute = 0;
  }
  if (zone_offset_hour < 0) {
    zone_offset_minute *= -1;
  }
  output.zone_offset = ros::Duration(3600 * zone_offset_hour + 60 * zone_offset_minute, 0);

  if (fields.size() > 6) {
    sscanf(fields.at(i++).c_str(), "%hhx", &output.checksum);
  }

  return true;
}

}
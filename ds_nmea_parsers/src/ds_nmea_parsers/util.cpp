#include "ds_nmea_parsers/util.h"

#include <algorithm>
#include <iterator>
#include <boost/date_time/posix_time/ptime.hpp>

namespace ds_nmea_msgs
{

uint8_t calculate_checksum(const std::string& nmea_msg)
{
  const auto start_it = std::find(std::begin(nmea_msg), std::end(nmea_msg), '$');

  if (start_it == std::end(nmea_msg)){
    return 0;
  }

  const auto end_it = std::find(start_it, std::end(nmea_msg), '*');

  if (end_it == std::end(nmea_msg)){
    return 0;
  }

  // Equivalent to
  //
  // checksum = 0;
  // for(s = "after $"; s != "*"; s++)
  //    checksum ^= s
  return std::accumulate(
      std::next(start_it), end_it,
      0, [] (uint8_t acc, uint8_t c) { return acc ^ c;}
  );
}

ros::Time from_nmea_utc(int hours, int minutes, double seconds)
{
  // Get the current time as a boost ptime object.
  auto time = ros::Time::now().toBoost();

  const auto second = static_cast<int>(seconds);
  const auto m_second = static_cast<int>((seconds - second) * 1e6);

  const auto frac_seconds = m_second * (boost::posix_time::time_duration::ticks_per_second() / 100000);
  auto adjusted = boost::posix_time::ptime(
      time.date(),
      boost::posix_time::time_duration(hours, minutes, second, m_second)
  );

  return ros::Time::fromBoost(adjusted);
}

double nmea_dec_min_dec_degrees(double nmea_decmin) noexcept
{
  const auto degrees = static_cast<int>(nmea_decmin / 100);
  return degrees + (nmea_decmin - degrees * 100) / 60;
}

}

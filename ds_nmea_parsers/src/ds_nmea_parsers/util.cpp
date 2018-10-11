/**
* Copyright 2018 Woods Hole Oceanographic Institution
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
* 3. Neither the name of the copyright holder nor the names of its contributors
*    may be used to endorse or promote products derived from this software
*    without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*/
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

ros::Time from_nmea_utc_date(int year, int month, int day, int hours, int minutes, double seconds)
{
  const auto second = static_cast<int>(seconds);
  const auto m_second = static_cast<int>((seconds - second) * 1e6);
  boost::posix_time::time_duration(hours, minutes, second, m_second);

  boost::posix_time::ptime constructed(
      boost::gregorian::date(year, month, day),
      boost::posix_time::time_duration(hours, minutes, second, m_second));

  return ros::Time::fromBoost(constructed);
}

}

//
// Created by zac on 1/21/18.
//

#ifndef DS_NMEA_PARSERS_UTIL_H
#define DS_NMEA_PARSERS_UTIL_H

#include <cstdint>
#include <string>

#include <ros/time.h>

namespace ds_nmea_msgs
{

uint8_t calculate_checksum(const std::string& nmea_msg);

/// \@brief Convert nmea-style latitude to decimal degrees
///
/// Latitudes in most NMEA messages are in decimal minutes packed
/// as a single number.  For example:
///
///    5423.453
///
/// is really 54deg 23.453min, which is 54.39088deg
///
/// \param nmea_decmin
/// \return
double nmea_dec_min_dec_degrees(double nmea_decmin) noexcept;

/// @brief Convert a clock time to a full UTC date
///
/// Many NMEA sentances provide timestamps in UTC that only contain
/// the time.  For example, GGA's have a timestamp that looks like:
///
///   HHMMSS.SSSS
///
/// This method provides the missing date information by using
/// ros::Time::now() and replacing the time information with the values
/// provided.
///
///
/// \param hours
/// \param minutes
/// \param seconds
/// \return
ros::Time from_nmea_utc(int hours, int minutes, double seconds);

/// @brief Convert a ZDA time to a full UTC date
///
/// The ZDA string provides year/month/day in addition to time.  Do the conversion.
///
/// \param year
/// \param month
/// \param day
/// \param hours
/// \param minutes
/// \param seconds
/// \return
ros::Time from_nmea_utc_date(int year, int month, int day, int hours, int minutes, double seconds);

}
#endif //DS_NMEA_PARSERS_UTIL_H

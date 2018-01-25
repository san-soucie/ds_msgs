#ifndef DS_NMEA_PARSERS_GLL_H
#define DS_NMEA_PARSERS_GLL_H

#include "ds_nmea_msgs/Gll.h"
namespace ds_nmea_msgs
{
bool from_string(Gll& output, const std::string &nmea_string);
}

#endif //DS_NMEA_PARSERS_GLL_H

#ifndef DS_NMEA_PARSERS_GGA_H
#define DS_NMEA_PARSERS_GGA_H

#include "ds_nmea_msgs/Gga.h"

namespace ds_nmea_msgs
{
bool from_string(Gga& output, const std::string &nmea_string);
}
#endif //DS_NMEA_PARSERS_GGA_H

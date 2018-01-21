#ifndef DS_NMEA_PARSERS_PIXSEATITUD_H
#define DS_NMEA_PARSERS_PIXSEATITUD_H

#include "ds_nmea_msgs/PixseAtitud.h"

namespace ds_nmea_msgs
{
bool from_string(PixseAtitud& output, const std::string &nmea_string);
}
#endif //DS_NMEA_PARSERS_PIXSEATITUD_H

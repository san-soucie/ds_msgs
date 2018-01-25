#ifndef DS_NMEA_PARSERS_PIXSEHTSTS_H
#define DS_NMEA_PARSERS_PIXSEHTSTS_H

#include "ds_nmea_msgs/PixseHtsts.h"

namespace ds_nmea_msgs
{
bool from_string(PixseHtsts& output, const std::string &nmea_string);
}

#endif //DS_NMEA_PARSERS_PIXSEHTSTS_H

#ifndef DS_NMEA_PARSERS_PIXSESPEED_H
#define DS_NMEA_PARSERS_PIXSESPEED_H

#include "ds_nmea_msgs/PixseSpeed.h"

namespace ds_nmea_msgs
{

bool from_string(PixseSpeed& output, const std::string &nmea_string);

}
#endif //DS_NMEA_PARSERS_PIXSESPEED_H

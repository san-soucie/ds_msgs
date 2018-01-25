#ifndef DS_NMEA_PARSERS_PIXSESTDSPD_H
#define DS_NMEA_PARSERS_PIXSESTDSPD_H

#include "ds_nmea_msgs/PixseStdspd.h"

namespace ds_nmea_msgs
{
bool from_string(PixseStdspd& output, const std::string &nmea_string);
}
#endif //DS_NMEA_PARSERS_PIXSESTDSPD_H

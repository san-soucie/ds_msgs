#ifndef DS_NMEA_PARSERS_PIXSESTDHRP_H
#define DS_NMEA_PARSERS_PIXSESTDHRP_H

#include "ds_nmea_msgs/PixseStdhrp.h"

namespace ds_nmea_msgs
{

bool from_string(PixseStdhrp& output, const std::string &nmea_string);

}

#endif //DS_NMEA_PARSERS_PIXSESTDHRP_H

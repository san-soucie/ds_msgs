#ifndef DS_NMEA_PARSERS_PIXSEUTMWGS_H
#define DS_NMEA_PARSERS_PIXSEUTMWGS_H

#include "ds_nmea_msgs/PixseUtmwgs.h"

namespace ds_nmea_msgs
{

bool from_string(PixseUtmwgs& output, const std::string &nmea_string);

}

#endif //DS_NMEA_PARSERS_PIXSEUTMWGS_H

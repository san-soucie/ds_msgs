#ifndef DS_NMEA_PARSERS_HDT_H
#define DS_NMEA_PARSERS_HDT_H

#include "ds_nmea_msgs/Hdt.h"

namespace ds_nmea_msgs
{

bool from_string(Hdt& output, const std::string &nmea_string);

}

#endif //DS_NMEA_PARSERS_HDT_H

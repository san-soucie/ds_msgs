#ifndef DS_NMEA_PARSERS_PIXSEALGSTS_H
#define DS_NMEA_PARSERS_PIXSEALGSTS_H

#include "ds_nmea_msgs/PixseAlgsts.h"

namespace ds_nmea_msgs
{

bool from_string(PixseAlgsts& output, const std::string &nmea_string);

}

#endif //DS_NMEA_PARSERS_PIXSEALGSTS_H

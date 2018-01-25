#ifndef DS_NMEA_PARSERS_PIXSEHEAVE_H
#define DS_NMEA_PARSERS_PIXSEHEAVE_H

#include "ds_nmea_msgs/PixseHeave.h"

namespace ds_nmea_msgs
{

bool from_string(PixseHeave& output, const std::string &nmea_string);

}
#endif //DS_NMEA_PARSERS_PIXSEHEAVE_H

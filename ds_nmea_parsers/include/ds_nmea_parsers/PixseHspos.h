#ifndef DS_NMEA_PARSERS_PIXSEHSPOS_H
#define DS_NMEA_PARSERS_PIXSEHSPOS_H

#include "ds_nmea_msgs/PixseHspos.h"

namespace ds_nmea_msgs
{

bool from_string(PixseHspos& output, const std::string &nmea_string);

}

#endif //DS_NMEA_PARSERS_PIXSEHSPOS_H

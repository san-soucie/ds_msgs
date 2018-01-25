#ifndef DS_NMEA_PARSERS_PIXSESTATUS_H
#define DS_NMEA_PARSERS_PIXSESTATUS_H

#include "ds_nmea_msgs/PixseStatus.h"

namespace ds_nmea_msgs
{

bool from_string(PixseStatus& output, const std::string &nmea_string);

}
#endif //DS_NMEA_PARSERS_PIXSESTATUS_H

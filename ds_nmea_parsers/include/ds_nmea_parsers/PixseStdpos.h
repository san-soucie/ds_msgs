#ifndef DS_NMEA_PARSERS_PIXSESTDPOS_H
#define DS_NMEA_PARSERS_PIXSESTDPOS_H

#include "ds_nmea_msgs/PixseStdpos.h"

namespace ds_nmea_msgs
{

bool from_string(PixseStdpos& output, const std::string &nmea_string);

}
#endif //DS_NMEA_PARSERS_PIXSESTDPOS_H

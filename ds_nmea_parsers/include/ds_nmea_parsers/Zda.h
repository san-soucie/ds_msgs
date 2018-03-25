//
// Created by ivaughn on 3/25/18.
//

#ifndef DS_NMEA_PARSERS_ZDA_H
#define DS_NMEA_PARSERS_ZDA_H

#include "ds_nmea_msgs/Zda.h"
namespace ds_nmea_msgs
{
bool from_string(Zda& output, const std::string& nmea_string);
}

#endif // DS_NMEA_PARSERS_ZDA_H

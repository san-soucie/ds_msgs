#ifndef DS_NMEA_MSGS_UTIL_H
#define DS_NMEA_MSGS_UTIL_H

#include "ds_nmea_msgs/Hdt.h"
#include "ds_nmea_msgs/PixseAtitud.h"
#include "ds_nmea_msgs/PixsePositi.h"
#include "ds_nmea_msgs/PixseSpeed.h"
#include "ds_nmea_msgs/PixseUtmwgs.h"
#include "ds_nmea_msgs/PixseHeave.h"
#include "ds_nmea_msgs/PixseStdhrp.h"
#include "ds_nmea_msgs/PixseStdpos.h"
#include "ds_nmea_msgs/PixseStdspd.h"
#include "ds_nmea_msgs/PixseAlgsts.h"
#include "ds_nmea_msgs/PixseStatus.h"
#include "ds_nmea_msgs/PixseHtsts.h"
#include "ds_nmea_msgs/PixseHspos.h"
#include "ds_nmea_msgs/Gga.h"

#include <utility>
#include <string>
namespace ds_nmea_msgs
{


bool from_string(Hdt& output, const std::string &nmea_string);
bool from_string(PixseAtitud& output, const std::string &nmea_string);
bool from_string(PixsePositi& output, const std::string &nmea_string);
bool from_string(PixseSpeed& output, const std::string &nmea_string);
bool from_string(PixseUtmwgs& output, const std::string &nmea_string);
bool from_string(PixseHeave& output, const std::string &nmea_string);
bool from_string(PixseStdhrp& output, const std::string &nmea_string);
bool from_string(PixseStdpos& output, const std::string &nmea_string);
bool from_string(PixseStdspd& output, const std::string &nmea_string);
bool from_string(PixseAlgsts& output, const std::string &nmea_string);
bool from_string(PixseStatus& output, const std::string &nmea_string);
bool from_string(PixseHtsts& output, const std::string &nmea_string);
bool from_string(PixseHspos& output, const std::string &nmea_string);
bool from_string(Gga& output, const std::string &nmea_string);

}
#endif //DS_NMEA_MSGS_UTIL_H

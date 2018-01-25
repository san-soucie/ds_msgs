#include "ds_nmea_parsers/Hdt.h"

namespace ds_nmea_msgs
{

bool from_string(Hdt& output, const std::string &nmea_string)
{
  auto true_flag = char{0};

  const auto n = sscanf(
      nmea_string.c_str(), "$%*2cHDT,%lf,%1c*%02hhx\r\n", &output.heading, &true_flag, &output.checksum);

  if (n < 1) {
    return false;
  }

  if (n >= 3)
  {
    output.is_true = static_cast<unsigned char>(true_flag == 'T');
  }
  return true;
}


}

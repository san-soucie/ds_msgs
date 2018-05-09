#include "ds_nmea_parsers/Vtg.h"
#include "ds_nmea_parsers/util.h"

#include <list>

#include <gtest/gtest.h>

using namespace ds_nmea_msgs;

TEST(VTG, valid_strings)
{

  auto gen = [](
      std::string talker, double degrees_true, double degrees_mag, double speed_knots, double speed_kph, uint8_t mode, uint8_t checksum)
  {
    auto msg = ds_nmea_msgs::Vtg{};
    msg.talker = talker;
    msg.track_degrees_true = degrees_true;
    msg.track_degrees_magnetic = degrees_mag;
    msg.speed_knots = speed_knots;
    msg.speed_km_per_hour = speed_kph;
    msg.mode = mode;
    msg.checksum = checksum;
    return msg;
  };

  const auto test_pairs =
      std::list<std::pair<std::string, ds_nmea_msgs::Vtg>>{
          {
              "$GNVTG,,T,,M,,N,,K,N*32\r\n",
              gen("GN", Vtg::VTG_NO_DATA, Vtg::VTG_NO_DATA, Vtg::VTG_NO_DATA, Vtg::VTG_NO_DATA, 'N', 0x32)
          },
          {
              "$GNVTG,285.09,T,,M,0.84,N,1.6,K,A*1E\r\n",
              gen("GN", 285.09, Vtg::VTG_NO_DATA, 0.84, 1.6, 'A', 0x1E)
          },
          {
              "$GNVTG,176.77,T,,M,0.00,N,0.0,K,A*13\r\n",
              gen("GN", 176.77, Vtg::VTG_NO_DATA, 0.00, 0.0, 'A', 0x13)
          }
      };

  // Loop through all provided cases
  for (const auto& test_pair : test_pairs)
  {
    auto msg = ds_nmea_msgs::Vtg{};
    auto expected = test_pair.second;
    const auto ok = ds_nmea_msgs::from_string(msg, test_pair.first);

    // Should have succeeded
    ASSERT_TRUE(ok);

    // All fields should match.
    EXPECT_STREQ(expected.talker.data(), msg.talker.data());
    EXPECT_FLOAT_EQ(expected.track_degrees_true, msg.track_degrees_true);
    EXPECT_FLOAT_EQ(expected.track_degrees_magnetic, msg.track_degrees_magnetic);
    EXPECT_FLOAT_EQ(expected.speed_knots, msg.speed_knots);
    EXPECT_FLOAT_EQ(expected.speed_km_per_hour, msg.speed_km_per_hour);
    EXPECT_STREQ(expected.mode.data(), msg.mode.data());
    EXPECT_FLOAT_EQ(expected.checksum, msg.checksum);
  }
}

// Run all the tests that were declared with TEST()
int main(int argc, char** argv)
{
  ros::Time::init();
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


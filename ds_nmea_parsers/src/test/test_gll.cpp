#include "ds_nmea_parsers/Gll.h"
#include "ds_nmea_parsers/util.h"

#include <list>

#include <gtest/gtest.h>

using namespace ds_nmea_msgs;

TEST(PIXSE_GGA, valid_strings)
{

  auto gen = [](
      std::string talker, double latitude, uint8_t latitude_dir, double longitude, uint8_t longitude_dir,
      ros::Time timestamp, uint8_t status, uint8_t checksum)
  {
    auto msg = ds_nmea_msgs::Gll{};
    msg.talker = talker;
    msg.latitude = latitude;
    msg.latitude_dir = latitude_dir;
    msg.longitude = longitude;
    msg.longitude_dir = longitude_dir;
    msg.timestamp = timestamp;
    msg.status = status;
    msg.checksum = checksum;
    return msg;
  };

  const auto test_pairs =
      std::list<std::pair<std::string, ds_nmea_msgs::Gll>>{
          {
              "$GPGLL,4916.45,N,12311.12,W,225444,A*1D\r\n",
              gen("GP", 49.27417, 'N', 123.1853,'W', from_nmea_utc(22, 54, 44), Gll::GLL_DATA_VALID, 0x1D)
          },
          {
              "$GPGLL,0000.0000,N,00000.0000,E,235947.000,V*2D",
              gen("GP", 0.0, 'N', 0.0, 'E', from_nmea_utc(23, 59, 47), Gll::GLL_DATA_INVALID, 0x2D)

          },
          {
              "$GPGLL,4250.5589,S,14718.5084,E,092204.999,A*2D",
              gen("GP", 42.84265, 'S', 147.30847, 'E', from_nmea_utc(9, 22, 4.999), Gll::GLL_DATA_VALID, 0x2D)
          }
      };

  // Loop through all provided cases
  for (const auto& test_pair : test_pairs)
  {
    auto msg = ds_nmea_msgs::Gll{};
    auto expected = test_pair.second;
    const auto ok = ds_nmea_msgs::from_string(msg, test_pair.first);

    // Should have succeeded
    ASSERT_TRUE(ok);

    // All fields should match.
    EXPECT_STREQ(expected.talker.data(), msg.talker.data());
    EXPECT_EQ(expected.timestamp, msg.timestamp);
    EXPECT_FLOAT_EQ(expected.latitude, msg.latitude);
    EXPECT_EQ(expected.latitude_dir, msg.latitude_dir);
    EXPECT_FLOAT_EQ(expected.longitude, msg.longitude);
    EXPECT_EQ(expected.longitude_dir, msg.longitude_dir);
    EXPECT_EQ(expected.status, msg.status);
    EXPECT_EQ(expected.checksum, msg.checksum);
  }
}

// Run all the tests that were declared with TEST()
int main(int argc, char** argv)
{
  ros::Time::init();
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


#include "ds_nmea_parsers/PixsePositi.h"

#include <list>
#include <gtest/gtest.h>

TEST(PIXSE_POSITI, valid_strings)
{

  auto gen = [](double lat, double lon, double alt, uint8_t checksum) {
    auto msg = ds_nmea_msgs::PixsePositi{};
    msg.latitude = lat;
    msg.longitude = lon;
    msg.altitude = alt;
    msg.checksum = checksum;
    return msg;
  };

  const auto test_pairs =
      std::list<std::pair<std::string, ds_nmea_msgs::PixsePositi>>{
          {"$PIXSE,POSITI,-15.14096288,186.22231161,0.033*79\r\n", gen(-15.14096288, 186.22231161, 0.033, 0x79)}
      };

  // Loop through all provided cases
  for (const auto& test_pair : test_pairs)
  {
    auto msg = ds_nmea_msgs::PixsePositi{};
    auto expected = test_pair.second;
    const auto ok = ds_nmea_msgs::from_string(msg, test_pair.first);

    // Should have succeeded
    EXPECT_TRUE(ok);

    // All fields should match.
    EXPECT_FLOAT_EQ(expected.latitude, msg.latitude);
    EXPECT_FLOAT_EQ(expected.longitude, msg.longitude);
    EXPECT_FLOAT_EQ(expected.altitude, msg.altitude);
    EXPECT_EQ(expected.checksum, msg.checksum);
  }
}

// Run all the tests that were declared with TEST()
int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


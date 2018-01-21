#include "ds_nmea_parsers/PixseUtmwgs.h"

#include <list>
#include <gtest/gtest.h>

TEST(PIXSE_UTMWGS, valid_strings)
{

  auto gen = [](uint8_t lat_zone, int16_t lon_zone, double eastings, double northings, double altitude, uint8_t checksum) {
    auto msg = ds_nmea_msgs::PixseUtmwgs{};
    msg.latitude_utm_zone = lat_zone;
    msg.longitude_utm_zone = lon_zone;
    msg.eastings = eastings;
    msg.northings = northings;
    msg.altitude = altitude;
    msg.checksum = checksum;
    return msg;
  };

  const auto test_pairs =
      std::list<std::pair<std::string, ds_nmea_msgs::PixseUtmwgs>>{
          {
              "$PIXSE,UTMWGS,L,2,201472.606,8324191.634,0.032*3E\r\n",
              gen('L', 2, 201472.606, 8324191.634, 0.032, 0x3E)
          },
          {
              "$PIXSE,UTMWGS,L,2,201472.605,8324191.634,0.032*3D\r\n",
              gen('L', 2, 201472.605, 8324191.634, 0.032, 0x3D)
          }
      };

  // Loop through all provided cases
  for (const auto& test_pair : test_pairs)
  {
    auto msg = ds_nmea_msgs::PixseUtmwgs{};
    auto expected = test_pair.second;
    const auto ok = ds_nmea_msgs::from_string(msg, test_pair.first);

    // Should have succeeded
    EXPECT_TRUE(ok);

    // All fields should match.
    EXPECT_EQ(expected.latitude_utm_zone, msg.latitude_utm_zone);
    EXPECT_EQ(expected.longitude_utm_zone, msg.longitude_utm_zone);
    EXPECT_FLOAT_EQ(expected.eastings, msg.eastings);
    EXPECT_FLOAT_EQ(expected.northings, msg.northings);
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


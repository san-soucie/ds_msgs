#include "ds_nmea_msgs/util.h"

#include <list>
#include <gtest/gtest.h>

TEST(PIXSE_UTMWGS, valid_strings)
{

  auto gen = [](double east, double north, double vert, uint8_t checksum) {
    auto msg = ds_nmea_msgs::PixseStdspd{};
    msg.east = east;
    msg.north = north;
    msg.vertical = vert;
    msg.checksum = checksum;
    return msg;
  };

  const auto test_pairs =
      std::list<std::pair<std::string, ds_nmea_msgs::PixseStdspd>>{
          {"$PIXSE,UTMWGS,0.013,0.013,0.095*71\r\n", gen(0.013, 0.013, 0.095, 0x71)}
      };

  // Loop through all provided cases
  for (const auto& test_pair : test_pairs)
  {
    auto msg = ds_nmea_msgs::PixseStdspd{};
    auto expected = test_pair.second;
    const auto ok = ds_nmea_msgs::from_string(msg, test_pair.first);

    // Should have succeeded
    EXPECT_TRUE(ok);

    // All fields should match.
    EXPECT_FLOAT_EQ(expected.east, msg.east);
    EXPECT_FLOAT_EQ(expected.north, msg.north);
    EXPECT_FLOAT_EQ(expected.vertical, msg.vertical);
    EXPECT_EQ(expected.checksum, msg.checksum);
  }
}

// Run all the tests that were declared with TEST()
int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


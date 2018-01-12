#include "ds_nmea_parsers/parsers.h"

#include <list>
#include <gtest/gtest.h>

TEST(PIXSE_STDHRP, valid_strings)
{

  auto gen = [](double heading, double roll, double pitch, uint8_t checksum) {
    auto msg = ds_nmea_msgs::PixseStdhrp{};
    msg.heading = heading;
    msg.roll = roll;
    msg.pitch = pitch;
    msg.checksum = checksum;
    return msg;
  };

  const auto test_pairs =
      std::list<std::pair<std::string, ds_nmea_msgs::PixseStdhrp>>{
          {"$PIXSE,STDHRP,0.013,0.013,0.095*71\r\n", gen(0.013, 0.013, 0.095, 0x71)},
          {"$PIXSE,STDHRP,0.013,0.001,0.001*72\r\n", gen(0.013, 0.001, 0.001, 0x72)}
      };

  // Loop through all provided cases
  for (const auto& test_pair : test_pairs)
  {
    auto msg = ds_nmea_msgs::PixseStdhrp{};
    auto expected = test_pair.second;
    const auto ok = ds_nmea_msgs::from_string(msg, test_pair.first);

    // Should have succeeded
    EXPECT_TRUE(ok);

    // All fields should match.
    EXPECT_FLOAT_EQ(expected.heading, msg.heading);
    EXPECT_FLOAT_EQ(expected.roll, msg.roll);
    EXPECT_FLOAT_EQ(expected.pitch, msg.pitch);
    EXPECT_EQ(expected.checksum, msg.checksum);
  }
}

// Run all the tests that were declared with TEST()
int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


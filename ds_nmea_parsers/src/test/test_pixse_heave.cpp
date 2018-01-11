#include "ds_nmea_parsers/parsers.h"

#include <list>
#include <gtest/gtest.h>

TEST(PIXSE_HEAVE, valid_strings)
{

  auto gen = [](double surge, double sway, double heave, uint8_t checksum) {
    auto msg = ds_nmea_msgs::PixseHeave{};
    msg.surge = surge;
    msg.sway = sway;
    msg.heave = heave;
    msg.checksum = checksum;
    return msg;
  };

  const auto test_pairs =
      std::list<std::pair<std::string, ds_nmea_msgs::PixseHeave>>{
          {"$PIXSE,HEAVE_,0.000,0.000,-0.039*5E\r\n", gen(0, 0, -0.39, 0x5e)},
          {"$PIXSE,HEAVE_,0.000,0.000,0.284*77\r\n", gen(0, 0, 0.284, 0x77)}
      };

  // Loop through all provided cases
  for (const auto& test_pair : test_pairs)
  {
    auto msg = ds_nmea_msgs::PixseHeave{};
    auto expected = test_pair.second;
    const auto ok = ds_nmea_msgs::from_string(msg, test_pair.first);

    // Should have succeeded
    EXPECT_TRUE(ok);

    // All fields should match.
    EXPECT_FLOAT_EQ(expected.surge, msg.surge);
    EXPECT_FLOAT_EQ(expected.sway, msg.sway);
    EXPECT_FLOAT_EQ(expected.heave, msg.heave);
    EXPECT_EQ(expected.checksum, msg.checksum);
  }
}

// Run all the tests that were declared with TEST()
int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


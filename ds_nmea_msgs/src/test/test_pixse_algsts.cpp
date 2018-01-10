#include "ds_nmea_msgs/util.h"

#include <list>
#include <gtest/gtest.h>

TEST(PIXSE_ALGSTS, valid_strings)
{

  auto gen = [](uint32_t lsb, uint32_t msb, uint8_t checksum) {
    auto msg = ds_nmea_msgs::PixseAlgsts{};
    msg.lsb = lsb;
    msg.msb = msb;
    msg.checksum = checksum;
    return msg;
  };

  const auto test_pairs =
      std::list<std::pair<std::string, ds_nmea_msgs::PixseAlgsts>>{
          {"$PIXSE,ALGSTS,00000041,00030000*63", gen(0x41, 0x30000, 0x63)}
      };

  // Loop through all provided cases
  for (const auto& test_pair : test_pairs)
  {
    auto msg = ds_nmea_msgs::PixseAlgsts{};
    auto expected = test_pair.second;
    const auto ok = ds_nmea_msgs::from_string(msg, test_pair.first);

    // Should have succeeded
    EXPECT_TRUE(ok);

    // All fields should match.
    EXPECT_EQ(expected.lsb, msg.lsb);
    EXPECT_EQ(expected.msb, msg.msb);
    EXPECT_EQ(expected.checksum, msg.checksum);
  }
}

// Run all the tests that were declared with TEST()
int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


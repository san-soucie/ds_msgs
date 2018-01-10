#include "ds_nmea_msgs/util.h"

#include <list>
#include <gtest/gtest.h>

TEST(PIXSE_HTSTS, valid_strings)
{

  auto gen = [](uint32_t lsb, uint8_t checksum) {
    auto msg = ds_nmea_msgs::PixseHtsts{};
    msg.lsb = lsb;
    msg.checksum = checksum;
    return msg;
  };

  const auto test_pairs =
      std::list<std::pair<std::string, ds_nmea_msgs::PixseHtsts>>{
          {"$PIXSE,HT_STS,6FFD5551*36\r\n", gen(0x6FFD5551, 0x36)}
      };

  // Loop through all provided cases
  for (const auto& test_pair : test_pairs)
  {
    auto msg = ds_nmea_msgs::PixseHtsts{};
    auto expected = test_pair.second;
    const auto ok = ds_nmea_msgs::from_string(msg, test_pair.first);

    // Should have succeeded
    EXPECT_TRUE(ok);

    // All fields should match.
    EXPECT_EQ(expected.lsb, msg.lsb);
    EXPECT_EQ(expected.checksum, msg.checksum);
  }
}

// Run all the tests that were declared with TEST()
int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


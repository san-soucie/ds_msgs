#include "ds_nmea_parsers/parsers.h"

#include <list>
#include <gtest/gtest.h>

TEST(PIXSE_STATUS, valid_strings)
{

  auto gen = [](uint32_t lsb, uint32_t msb, uint8_t checksum) {
    auto msg = ds_nmea_msgs::PixseStatus{};
    msg.lsb = lsb;
    msg.msb = msb;
    msg.checksum = checksum;
    return msg;
  };

  const auto test_pairs =
      std::list<std::pair<std::string, ds_nmea_msgs::PixseStatus>>{
          {"$PIXSE,STATUS,08000200,00001A00*15\r\n", gen(0x8000200, 0x1A00, 0x15)}
      };

  // Loop through all provided cases
  for (const auto& test_pair : test_pairs)
  {
    auto msg = ds_nmea_msgs::PixseStatus{};
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


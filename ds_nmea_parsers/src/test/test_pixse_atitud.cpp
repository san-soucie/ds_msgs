#include "ds_nmea_parsers/parsers.h"

#include <list>
#include <gtest/gtest.h>

TEST(PIXSE_ATITUD, valid_strings)
{

  auto gen = [](double roll, double pitch, uint8_t checksum) {
    auto msg = ds_nmea_msgs::PixseAtitud{};
    msg.roll = roll;
    msg.pitch = pitch;
    msg.checksum = checksum;
    return msg;
  };

  const auto test_pairs =
      std::list<std::pair<std::string, ds_nmea_msgs::PixseAtitud>>{
          {"$PIXSE,ATITUD,1.129,5.394*62\r\n", gen(1.129,5.394, 0x62)}
      };

  // Loop through all provided cases
  for (const auto& test_pair : test_pairs)
  {
    auto msg = ds_nmea_msgs::PixseAtitud{};
    auto expected = test_pair.second;
    const auto ok = ds_nmea_msgs::from_string(msg, test_pair.first);

    // Should have succeeded
    EXPECT_TRUE(ok);

    // All fields should match.
    EXPECT_FLOAT_EQ(expected.roll, msg.roll);
    EXPECT_EQ(expected.pitch, msg.pitch);
    EXPECT_EQ(expected.checksum, msg.checksum);
  }
}

// Run all the tests that were declared with TEST()
int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

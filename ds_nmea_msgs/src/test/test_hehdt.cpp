#include "ds_nmea_msgs/util.h"
#include "ds_nmea_msgs/Hdt.h"

#include <list>
#include <gtest/gtest.h>

TEST(HEHDT, valid_strings)
{

  auto hdt = [](double heading, bool true_flag, uint8_t checksum) {
    auto msg = ds_nmea_msgs::Hdt{};
    msg.heading = heading;
    msg.is_true = static_cast<unsigned char>(true_flag);
    msg.checksum = checksum;
    return msg;
  };

  const auto test_pairs =
      std::list<std::pair<std::string, ds_nmea_msgs::Hdt>>{
          {"$HEHDT,123.4,T*1F\r\n", hdt(123.4, true, 0x1F)},
          {"$HEHDT,284.49,T*1C", hdt(284.49, true, 0x1C)}
      };

  // Loop through all provided cases
  for (const auto& test_pair : test_pairs)
  {
    auto msg = ds_nmea_msgs::Hdt{};
    auto expected = test_pair.second;
    const auto ok = ds_nmea_msgs::from_string(msg, test_pair.first);

    // Should have succeeded
    EXPECT_TRUE(ok);

    // All fields should match.
    EXPECT_FLOAT_EQ(expected.heading, msg.heading);
    EXPECT_EQ(expected.is_true, msg.is_true);
    EXPECT_EQ(expected.checksum, msg.checksum);
  }
}

// Run all the tests that were declared with TEST()
int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

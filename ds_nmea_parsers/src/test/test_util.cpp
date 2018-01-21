#include "ds_nmea_parsers/util.h"

#include <list>

#include <gtest/gtest.h>

TEST(NMEA_CHECKSUM, valid_strings)
{


  const auto test_pairs =
      std::list<std::pair<std::string, uint8_t>>{
          {"$GPGLL,5300.97914,N,00259.98174,E,125926,A*28", 0x28},
          {"$GPGGA,212354.657,,,,,0,00,50.0,,M,0.0,M,,0000*4A", 0x4A},
          {"random junk before$GPGGA,212354.657,,,,,0,00,50.0,,M,0.0,M,,0000*4A", 0x4A}  // Find the nmea string.
      };

  // Loop through all provided cases
  for (const auto& test_pair : test_pairs)
  {
    auto expected = test_pair.second;
    const auto chksum = ds_nmea_msgs::calculate_checksum(test_pair.first);

    // Should have succeeded
    ASSERT_EQ(expected, chksum);
  }
}

TEST(NMEA_CHECKSUM, invalid_strings)
{
  const auto test_pairs =
      std::list<std::pair<std::string, uint8_t>>{
          {"GPGLL,5300.97914,N,00259.98174,E,125926,A*28",  0},    // No leading '$'
          {"$GPGLL,5300.97914,N,00259.98174,E,125926,A",  0},      // No trailing '*'
      };

  // Loop through all provided cases
  for (const auto& test_pair : test_pairs)
  {
    auto expected = test_pair.second;
    const auto chksum = ds_nmea_msgs::calculate_checksum(test_pair.first);

    // Should have succeeded
    ASSERT_EQ(expected, chksum);
  }
}

TEST(NMEA_DECMIN, valid_conversions)
{
  const auto test_pairs =
      std::list<std::pair<double, double>>{
          {4523.342, 45.3890333},
          {-7323.43, -73.3905},
      };

  // Loop through all provided cases
  for (const auto& test_pair : test_pairs)
  {
    auto expected = test_pair.second;
    const auto result = ds_nmea_msgs::nmea_dec_min_dec_degrees(test_pair.first);

    // Should have succeeded
    ASSERT_FLOAT_EQ(expected, result);
  }
}
// Run all the tests that were declared with TEST()
int main(int argc, char** argv)
{
  ros::Time::init();
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


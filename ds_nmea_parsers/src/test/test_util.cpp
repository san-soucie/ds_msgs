/**
* Copyright 2018 Woods Hole Oceanographic Institution
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
* 3. Neither the name of the copyright holder nor the names of its contributors
*    may be used to endorse or promote products derived from this software
*    without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*/
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

TEST(NMEA_TO_UTC_STR, rounding)
{
  const auto test_pairs = 
      std::list<std::pair<double,std::string>>{
          {0, "000000.000"},
          {15, "000015.000"},
          {75, "000115.000"},
          {3675, "010115.000"},
          {15.553, "000015.553"},
          {75.292, "000115.292"},
          {3675.00002, "010115.000"}
      };
  for (const auto& test_pair : test_pairs)
  {
    ros::Time t;
    t.fromSec(test_pair.first);
    auto expected = test_pair.second;
    const auto actual = ds_nmea_msgs::to_nmea_utc_str(t);
    
    // should have succeeded
    ASSERT_EQ(expected, actual);
  }
  
}

// Run all the tests that were declared with TEST()
int main(int argc, char** argv)
{
  ros::Time::init();
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


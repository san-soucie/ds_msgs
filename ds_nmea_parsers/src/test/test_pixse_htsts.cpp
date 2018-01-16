#include "ds_nmea_parsers/parsers.h"

#include <list>
#include <gtest/gtest.h>

/// Enum flags are coded as decimal values in the message definitions....
/// make sure they're actually the expected powers of 2
TEST(PIXSE_HTSTS, status_enum_values)
{

  const auto expected_flag_order = std::vector<uint32_t>
      {
        ds_nmea_msgs::PixseHtsts::SYSTEM_OK,
        ds_nmea_msgs::PixseHtsts::ALIGNMENT_IN_PROGRESS,
        ds_nmea_msgs::PixseHtsts::SYSTEM_ERROR,
        ds_nmea_msgs::PixseHtsts::SYSTEM_WARNING,

        ds_nmea_msgs::PixseHtsts::SERIAL_INPUT_OK,
        ds_nmea_msgs::PixseHtsts::SERIAL_INPUT_ERROR,
        ds_nmea_msgs::PixseHtsts::SERIAL_OUTPUT_OK,
        ds_nmea_msgs::PixseHtsts::SERIAL_OUTPUT_ERROR,

        ds_nmea_msgs::PixseHtsts::ELECTRONIC_OK,
        ds_nmea_msgs::PixseHtsts::ELECTRONIC_ERROR,
        ds_nmea_msgs::PixseHtsts::FOG_OK,
        ds_nmea_msgs::PixseHtsts::FOG_ERROR,

        ds_nmea_msgs::PixseHtsts::ACCEL_OK,
        ds_nmea_msgs::PixseHtsts::ACCEL_ERROR,
        ds_nmea_msgs::PixseHtsts::CPU_OK,
        ds_nmea_msgs::PixseHtsts::CPU_ERROR,

        ds_nmea_msgs::PixseHtsts::TEMP_OK,
        ds_nmea_msgs::PixseHtsts::TEMP_ERROR,
        ds_nmea_msgs::PixseHtsts::NO_GPS1_DETECTED,
        ds_nmea_msgs::PixseHtsts::NO_GPS2_DETECTED,

        ds_nmea_msgs::PixseHtsts::NO_MANUAL_GPS_DETECTED,
        ds_nmea_msgs::PixseHtsts::NO_DVL_BOTTOM_TRACK_DETECTED,
        ds_nmea_msgs::PixseHtsts::NO_DVL_WATER_TRACK_DETECTED,
        ds_nmea_msgs::PixseHtsts::NO_EM_LOG_DETECTED,

        ds_nmea_msgs::PixseHtsts::NO_DEPTH_DETECTED,
        ds_nmea_msgs::PixseHtsts::NO_USBL_DETECTED,
        ds_nmea_msgs::PixseHtsts::NO_LBL_DETECTED,
        ds_nmea_msgs::PixseHtsts::NO_ALITITUDE_DETECTED,

        ds_nmea_msgs::PixseHtsts::NO_UTC_SYNC_DETECTED,
        ds_nmea_msgs::PixseHtsts::NO_PPS_SYNC_DETECTED,
        ds_nmea_msgs::PixseHtsts::NO_CTD_DETECTED,
        ds_nmea_msgs::PixseHtsts::ZUP_MODE_ACTIVATED,
      };

  for(auto i=0; i<expected_flag_order.size(); ++i)
  {
    EXPECT_EQ(expected_flag_order.at(i), 1 << i);
  }
}

TEST(PIXSE_HTSTS, valid_strings)
{

  auto gen = [](uint32_t lsb, uint8_t checksum) {
    auto msg = ds_nmea_msgs::PixseHtsts{};
    msg.status = lsb;
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
    EXPECT_EQ(expected.status, msg.status);
    EXPECT_EQ(expected.checksum, msg.checksum);
  }
}

// Run all the tests that were declared with TEST()
int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


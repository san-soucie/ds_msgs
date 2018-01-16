#include "ds_nmea_parsers/parsers.h"

#include <list>
#include <gtest/gtest.h>

/// Enum flags are coded as decimal values in the message definitions....
/// make sure they're actually the expected powers of 2
TEST(PIXSE_STATUS, lsb_enum_values)
{

  const auto expected_flag_order = std::vector<uint32_t>
      {
        ds_nmea_msgs::PixseStatusLsb::DATA_READY_ERROR,
        ds_nmea_msgs::PixseStatusLsb::SRC_POWER_ERROR,
        ds_nmea_msgs::PixseStatusLsb::SRC_DIODE_ERROR,
        ds_nmea_msgs::PixseStatusLsb::SRC_MODE_ERROR,

        ds_nmea_msgs::PixseStatusLsb::FOG_X_OVER_DYN_LG,
        ds_nmea_msgs::PixseStatusLsb::FOG_Y_OVER_DYN_LG,
        ds_nmea_msgs::PixseStatusLsb::FOG_Z_OVER_DYN_LG,
        ds_nmea_msgs::PixseStatusLsb::ACC_X_ACQ_ERROR,

        ds_nmea_msgs::PixseStatusLsb::ACC_Y_ACQ_ERROR,
        ds_nmea_msgs::PixseStatusLsb::ACC_Z_ACQ_ERROR,
        ds_nmea_msgs::PixseStatusLsb::FOG_X_STAT_ERROR,
        ds_nmea_msgs::PixseStatusLsb::FOG_Y_STAT_ERROR,

        ds_nmea_msgs::PixseStatusLsb::FOG_Z_STAT_ERROR,
        ds_nmea_msgs::PixseStatusLsb::FOG_X_VPI_ERROR,
        ds_nmea_msgs::PixseStatusLsb::FOG_Y_VPI_ERROR,
        ds_nmea_msgs::PixseStatusLsb::FOG_Z_VPI_ERROR,

        ds_nmea_msgs::PixseStatusLsb::RESERVED,
        ds_nmea_msgs::PixseStatusLsb::FOG_X_OVER_DYN,
        ds_nmea_msgs::PixseStatusLsb::FOG_Y_OVER_DYN,
        ds_nmea_msgs::PixseStatusLsb::FOG_Z_OVER_DYN,

        ds_nmea_msgs::PixseStatusLsb::FOG_X_RX_ERROR,
        ds_nmea_msgs::PixseStatusLsb::FOG_Y_RX_ERROR,
        ds_nmea_msgs::PixseStatusLsb::FOG_Z_RX_ERROR,
        ds_nmea_msgs::PixseStatusLsb::FOG_X_CRC_ERROR,

        ds_nmea_msgs::PixseStatusLsb::FOG_Y_CRC_ERROR,
        ds_nmea_msgs::PixseStatusLsb::FOG_Z_CRC_ERROR,
        ds_nmea_msgs::PixseStatusLsb::TEMP_ACQ_ERROR,
        ds_nmea_msgs::PixseStatusLsb::TEMP_THRESHOLD_ERROR,

        ds_nmea_msgs::PixseStatusLsb::DIODE_TEMP_THRESHOLD_ERROR,
        ds_nmea_msgs::PixseStatusLsb::FIFO_FULL_WARNING,
        ds_nmea_msgs::PixseStatusLsb::FIFO_FULL_ERROR,
        ds_nmea_msgs::PixseStatusLsb::SRC_POWER_ERROR2,
      };

  for(auto i=0; i<expected_flag_order.size(); ++i)
  {
    EXPECT_EQ(expected_flag_order.at(i), 1 << i);
  }
}

TEST(PIXSE_STATUS, msb_enum_values)
{

  const auto expected_flag_order = std::vector<uint32_t> {
      ds_nmea_msgs::PixseStatusMsb::FOG_X_ERROR,
      ds_nmea_msgs::PixseStatusMsb::FOG_Y_ERROR,
      ds_nmea_msgs::PixseStatusMsb::FOG_Z_ERROR,
      ds_nmea_msgs::PixseStatusMsb::SRC_ERROR,

      ds_nmea_msgs::PixseStatusMsb::ACC_X_ERROR,
      ds_nmea_msgs::PixseStatusMsb::ACC_Y_ERROR,
      ds_nmea_msgs::PixseStatusMsb::ACC_Z_ERROR,
      ds_nmea_msgs::PixseStatusMsb::TEMP_ERROR,

      ds_nmea_msgs::PixseStatusMsb::CSDP_OVERLOAD,
      ds_nmea_msgs::PixseStatusMsb::RESERVED01,
      ds_nmea_msgs::PixseStatusMsb::RESERVED02,
      ds_nmea_msgs::PixseStatusMsb::RESERVED03,

      ds_nmea_msgs::PixseStatusMsb::RESERVED04,
      ds_nmea_msgs::PixseStatusMsb::RESERVED05,
      ds_nmea_msgs::PixseStatusMsb::RESERVED06,
      ds_nmea_msgs::PixseStatusMsb::RESERVED07,

      ds_nmea_msgs::PixseStatusMsb::RESERVED08,
      ds_nmea_msgs::PixseStatusMsb::RESERVED09,
      ds_nmea_msgs::PixseStatusMsb::RESERVED10,
      ds_nmea_msgs::PixseStatusMsb::RESERVED11,

      ds_nmea_msgs::PixseStatusMsb::RESERVED12,
      ds_nmea_msgs::PixseStatusMsb::RESERVED13,
      ds_nmea_msgs::PixseStatusMsb::RESERVED14,
      ds_nmea_msgs::PixseStatusMsb::RESERVED15,

      ds_nmea_msgs::PixseStatusMsb::RESERVED16,
      ds_nmea_msgs::PixseStatusMsb::RESERVED17,
      ds_nmea_msgs::PixseStatusMsb::RESERVED18,
      ds_nmea_msgs::PixseStatusMsb::RESERVED19,

      ds_nmea_msgs::PixseStatusMsb::RESERVED20,
      ds_nmea_msgs::PixseStatusMsb::RESERVED21,
      ds_nmea_msgs::PixseStatusMsb::OPERATION_MODE_DEGRADED,
      ds_nmea_msgs::PixseStatusMsb::FAILURE,
  };

  for(auto i=0; i<expected_flag_order.size(); ++i)
  {
    EXPECT_EQ(expected_flag_order.at(i), 1 << i);
  }
}
TEST(PIXSE_STATUS, valid_strings)
{

  auto gen = [](uint32_t lsb, uint32_t msb, uint8_t checksum) {
    auto msg = ds_nmea_msgs::PixseStatus{};
    msg.lsb.flags = lsb;
    msg.msb.flags = msb;
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
    EXPECT_EQ(expected.lsb.flags, msg.lsb.flags);
    EXPECT_EQ(expected.msb.flags, msg.msb.flags);
    EXPECT_EQ(expected.checksum, msg.checksum);
  }
}

// Run all the tests that were declared with TEST()
int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


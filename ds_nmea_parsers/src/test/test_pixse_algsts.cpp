#include "ds_nmea_parsers/parsers.h"

#include "ds_nmea_msgs/PixseAlgstsLsb.h"
#include "ds_nmea_msgs/PixseAlgstsMsb.h"

#include <list>
#include <gtest/gtest.h>


/// Enum flags are coded as decimal values in the message definitions....
/// make sure they're actually the expected powers of 2
TEST(PIXSE_ALGSTS, lsb_enum_values)
{

  const auto expected_flag_order = std::vector<uint32_t>
      {
        ds_nmea_msgs::PixseAlgstsLsb::OPERATION_MODE_NAVIGATION,
        ds_nmea_msgs::PixseAlgstsLsb::OPERATION_MODE_ALIGNMENT,
        ds_nmea_msgs::PixseAlgstsLsb::OPERATION_MODE_FINE_ALIGNMENT,
        ds_nmea_msgs::PixseAlgstsLsb::OPERATION_MODE_DECK_RECKONING,

        ds_nmea_msgs::PixseAlgstsLsb::ALTITUDE_USING_GPS,
        ds_nmea_msgs::PixseAlgstsLsb::ALTITUDE_USING_DEPTH,
        ds_nmea_msgs::PixseAlgstsLsb::ALTITUDE_SABLILIZED,
        ds_nmea_msgs::PixseAlgstsLsb::ALTITUDE_HYDRO,

        ds_nmea_msgs::PixseAlgstsLsb::LOG_USED,
        ds_nmea_msgs::PixseAlgstsLsb::LOG_DATA_VALID,
        ds_nmea_msgs::PixseAlgstsLsb::LOG_WAITING_FOR_DATA,
        ds_nmea_msgs::PixseAlgstsLsb::LOG_DATA_REJECTED,

        ds_nmea_msgs::PixseAlgstsLsb::GPS_USED,
        ds_nmea_msgs::PixseAlgstsLsb::GPS_DATA_VALID,
        ds_nmea_msgs::PixseAlgstsLsb::GPS_WAITING_FOR_DATA,
        ds_nmea_msgs::PixseAlgstsLsb::GPS_DATA_REJECTED,

        ds_nmea_msgs::PixseAlgstsLsb::USBL_USED,
        ds_nmea_msgs::PixseAlgstsLsb::USBL_DATA_VALID,
        ds_nmea_msgs::PixseAlgstsLsb::USBL_WAITING_FOR_DATA,
        ds_nmea_msgs::PixseAlgstsLsb::USBL_DATA_REJECTED,

        ds_nmea_msgs::PixseAlgstsLsb::DEPTH_USED,
        ds_nmea_msgs::PixseAlgstsLsb::DEPTH_DATA_VALID,
        ds_nmea_msgs::PixseAlgstsLsb::DEPTH_WAITING_FOR_DATA,
        ds_nmea_msgs::PixseAlgstsLsb::DEPTH_DATA_REJECTED,

        ds_nmea_msgs::PixseAlgstsLsb::LBL_USED,
        ds_nmea_msgs::PixseAlgstsLsb::LBL_DATA_VALID,
        ds_nmea_msgs::PixseAlgstsLsb::LBL_WAITING_FOR_DATA,
        ds_nmea_msgs::PixseAlgstsLsb::LBL_DATA_REJECTED,

        ds_nmea_msgs::PixseAlgstsLsb::ALTITUDE_SATURATED,
        ds_nmea_msgs::PixseAlgstsLsb::SPEED_SATURATED,
        ds_nmea_msgs::PixseAlgstsLsb::RESERVED_1,
        ds_nmea_msgs::PixseAlgstsLsb::RESERVED_2,
  };

  for(auto i=0; i<expected_flag_order.size(); ++i)
  {
    EXPECT_EQ(expected_flag_order.at(i), 1 << i);
  }
}

TEST(PIXSE_ALGSTS, msb_enum_values)
{

  const auto expected_flag_order = std::vector<uint32_t> {
    ds_nmea_msgs::PixseAlgstsMsb::WATER_TRACK_USED,
    ds_nmea_msgs::PixseAlgstsMsb::WATER_TRACK_DATA_VALID,
    ds_nmea_msgs::PixseAlgstsMsb::WATER_TRACK_WAITING_FOR_DATA,
    ds_nmea_msgs::PixseAlgstsMsb::WATER_TRACK_REJECTED,

    ds_nmea_msgs::PixseAlgstsMsb::GPS2_USED,
    ds_nmea_msgs::PixseAlgstsMsb::GPS2_DATA_VALID,
    ds_nmea_msgs::PixseAlgstsMsb::GPS2_WAITING_FOR_DATA,
    ds_nmea_msgs::PixseAlgstsMsb::GPS2_DATA_REJECTED,

    ds_nmea_msgs::PixseAlgstsMsb::METROLOGY_USED,
    ds_nmea_msgs::PixseAlgstsMsb::METROLOGY_DATA_VALID,
    ds_nmea_msgs::PixseAlgstsMsb::METROLOGY_WAITING_FOR_DATA,
    ds_nmea_msgs::PixseAlgstsMsb::METROLOGY_DATA_REJECTED,

    ds_nmea_msgs::PixseAlgstsMsb::ALTITUDE_USED,
    ds_nmea_msgs::PixseAlgstsMsb::ALTITUDE_DATA_VALID,
    ds_nmea_msgs::PixseAlgstsMsb::ALTITUDE_WAITING_FOR_DATA,
    ds_nmea_msgs::PixseAlgstsMsb::ALTITUDE_DATA_REJECTED,

    ds_nmea_msgs::PixseAlgstsMsb::OPERATION_MODE_ZUP,
    ds_nmea_msgs::PixseAlgstsMsb::ZUP_VALID,
    ds_nmea_msgs::PixseAlgstsMsb::OPERATION_MODE_ZUP_VALID,
    ds_nmea_msgs::PixseAlgstsMsb::ZUP_BENCH_VALID,

    ds_nmea_msgs::PixseAlgstsMsb::STATIC_ALIGNMENT,
    ds_nmea_msgs::PixseAlgstsMsb::GO_TO_NAV,
    ds_nmea_msgs::PixseAlgstsMsb::RESERVED_1,
    ds_nmea_msgs::PixseAlgstsMsb::RESERVED_2,

    ds_nmea_msgs::PixseAlgstsMsb::EM_LOG_USED,
    ds_nmea_msgs::PixseAlgstsMsb::EM_LOG_DATA_VALID,
    ds_nmea_msgs::PixseAlgstsMsb::EM_LOG_WAITING_FOR_DATA,
    ds_nmea_msgs::PixseAlgstsMsb::EM_LOG_DATA_REJECTED,

    ds_nmea_msgs::PixseAlgstsMsb::GPS_MANUAL_USED,
    ds_nmea_msgs::PixseAlgstsMsb::GPS_MANUAL_DATA_VALID,
    ds_nmea_msgs::PixseAlgstsMsb::GPS_MANUAL_WAITING_FOR_DATA,
    ds_nmea_msgs::PixseAlgstsMsb::GPS_MANUAL_DATA_REJECTED,
  };

  for(auto i=0; i<expected_flag_order.size(); ++i)
  {
    EXPECT_EQ(expected_flag_order.at(i), 1 << i);
  }
}

TEST(PIXSE_ALGSTS, valid_strings)
{

  auto gen = [](uint32_t lsb, uint32_t msb, uint8_t checksum) {
    auto msg = ds_nmea_msgs::PixseAlgsts{};
    msg.lsb.flags = lsb;
    msg.msb.flags = msb;
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


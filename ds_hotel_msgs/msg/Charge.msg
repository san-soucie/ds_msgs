#for ds_coulomb_counter

std_msgs/Header header
ds_core_msgs/DsHeader ds_header

#four 16 bit charge values, float
float32[4] charge

#four charge accumulator status numbers
int16[4] status

# The standard 2-part DsHeader block
# This allows both a standard ROS header and DS-specific header blocks
# See HEADERS.md in ds_core_msgs for details
std_msgs/Header header
ds_core_msgs/DsHeader ds_header

string ip_addr
string netmask
string brdcst
string dfltgw
string dfltip
string dflmac
string dflprt
string laripa
string larmac
string larprt
string lfpipa
string lfpmac
string lfpprt 
string remipa
string raripa
string rarmac
string rsubnt
string brdgen
string brdgip
string guiipa 
string fpg3vr
string fpg6vr
string softvr
string reboot
string dfmode
string master_slaven
string logena
string acsten
string acstmast_slaven
string acstmfg
string lamdid
string ramdid
string sensitivity_ctrl
string lrhaln
string status1hz_enable
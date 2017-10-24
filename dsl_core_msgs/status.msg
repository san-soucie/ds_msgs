# Status Enum
uint8 DSL_STATUS_GOOD=0     # Everything is good.  Data is reported. Go for launch
uint8 DSL_STATUS_ERROR=1    # Something is wrong.  Complain to the human
uint8 DSL_STATUS_WARNING=2  # Something could be wrong
uint8 DSL_STATUS_ALERT=3    # Everything looks OK, but may not be doing the right thing
uint8 DSL_STATUS_DISABLED=4 # Disabled by another part of the system
uint8 DSL_STATUS_UNKNOWN=99 # No data!  This can't be good


###############################################################################
# Standard timestamp
time stamp

# The path of the status being reported
# This is almost always related to the name of the 
# node generating the status
string path

# This is the short status message.  "OK" for good.
string message

# This is a long, more detailed description of any issue.  "OK" for "good"
string description

# Our current status
uint8 status

# The status that should be used if the time + TTL is exceeded
uint8 status_on_timeout

# This status is considered valid until time + ttl_seconds.  After then,
# any UI should display status_on_timeout and adjust the displayed
# message accordingly
float32 ttl_seconds



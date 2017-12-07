# An enum to represent the source of a sound velocity measurement
# If you have a choice of method, Chen-Millero is probably a good
# bet for anything CTD-cast related.

# Unknown.  Don't use this.
int8 SV_METHOD_UNKNOWN=0 
  
# Direct measurement
# Usually via a Sound Velocity Probe that shoots actual sound
int8 SV_METHOD_DIRECT=1

# Chen-Millero algorithm
# best for depth < 1000m
int8 SV_METHOD_CHEN_MILLERO=2 

# The Del Grosso algorithm
# best for depth > 1000m
int8 SV_METHOD_DEL_GROSSO=3 


int8 value

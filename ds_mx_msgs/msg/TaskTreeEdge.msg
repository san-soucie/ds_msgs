# This message encodes a single named Task Tree edge from one node to another.
# Note that in this context, "Node" refers to a Graph node, NOT a ROS Node.  In the Task Tree,
# all nodes are Tasks.

string name

# An edge is primarily defined by its parent and child Tasks
uint8[16] parent_id
uint8[16] subtask_id


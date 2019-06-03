# A TaskTree Vertex describes a single Task.
uint8[16] task_id
string type

string role

# Each role generates a new dialog box; try to reuse existing roles
string TASK_TREE_VERTEX_ROOT = "root"
string TASK_TREE_VERTEX_SAFETY = "safety"
string TASK_TREE_VERTEX_PAYLOAD = "payload"
string TASK_TREE_VERTEX_SEQUENCE = "sequence"
string TASK_TREE_VERTEX_COMPLEX = "complex"
string TASK_TREE_VERTEX_EMPTY = "empty"
string TASK_TREE_VERTEX_PRIMITIVE = "primitive"



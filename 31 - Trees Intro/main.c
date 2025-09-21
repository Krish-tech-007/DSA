#include <stdio.h>
#include <stdlib.h>


/*
Example tree:
        7
     /  |   \
    8   2    11
   / \   \    \
  1   0   2    3
                 \
                  4
*/

/*
Structure:
7
├── 8
│   ├── 1
│   └── 0
├── 2
│   └── 2
└── 11
    └── 3
        └── 4
*/

/*
Terminologies:
Root: Node that has no parent nodes but is linked to other nodes. Top most node.
Parent: Node that is directly above any other node. It is called as the parent of that node.
Child: Node that is directly below any other node. It is called as the child of that node.
Leaf / External: Lowest Node that does not have any children.
Internal: Nodes that are not external nodes. Have both parent and atleast one child node.
Siblings: Nodes belonging to the same parent.
Ancestors: All nodes above the selected node are it's ancestors. Parent and Parent of parents.
Example: 7 is ancestor of 4. But 8 is not an ancestor of 4.
Descendants: All nodes below the selected node are it's descendants. Child and child of children.
Degree of a node: No. of direct children it has

Depth of a node: No. of edges from root to that node
Example: For 7, it is 0. For 11, it is 1. For 4, it is 3.

Height: No. of edges from the node to the deepest leaf
Example: For 11, it is 2. For 7, it is 3.

A tree is made up of node and edges.
If a tree has n nodes, then it has n-1 edges
*/
int main()
{

    return 0;
}

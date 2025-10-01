#include <stdio.h>
#include <stdlib.h>


/*
We do rotation in AVL trees so that the balance factor of nodes don't get negatively impacted after insertion
Example:
Before insertion:
        7 -> 1
       /
      5 -> 0
After insertion:
        7-> 2
       /
      5 -> 1
     /
    4 -> 0

Ideal structure:
         5 -> 0
        / \
   0 <-4   7 -> 0

Different types of rotations in AVL trees:
1. LL Rotation - Left Left Rotation
LL Rotation is a single right rotation used to rebalance an AVL tree
Used when a node is inserted into the left subtree of the left child, causing the tree to become left-heavy.
It happens when:
- A node is inserted into the left subtree of a node’s left child.
- The balance factor of the ancestor node becomes greater than +1.
LL rotation is a clockwise rotation. More precisely, it's a right rotation around the unbalanced node.
Called LL because insertion at Left of Left.

2. RR Rotation - Right Right Rotation
Example:
Before Insertion:
7 -> -1
 \
  9 -> 0

After insertion:
7 -> -2
 \
  9 -> -1
   \
    11 -> 0

Ideal structure:
    9
   / \
  7   11

Anticlockwise rotation.
RR Rotation is a single left rotation used to rebalance an AVL tree
Used when a node is inserted into the right subtree of the right child, causing the tree to become right-heavy
It happens when:
- A node is inserted into the right subtree of a node’s right child.
- The balance factor of the ancestor node becomes less than -1.
RR rotation shifts the weight from the right-heavy subtree back toward the center
Called RR because insertion at Right of Right

3. LR Rotation - Left Right Rotation
Insertion at Left's Right
Example:
Before Insertion
    7 -> 1
   /
  4 -> 0

After insertion:
    7 -> 2
   /
  4 -> 1
   \
    5 -> 0

Ideal Structure:
    5
   / \
  4   7

Rotations:
    7           7             5
   /           /             / \
  4      ->   5     ->      4   7
   \         /
    5       4
First anti clockwise then clockwise

4. RL Rotation - Right Left Rotation
Insertion at Right's Left
Example:
Before Insertion:
    7
     \
     11
After insertion:
    7
     \
     11
    /
   10
Ideal structure:
     10
    /  \
   7    11
Rotations:
    7            7              10
     \            \            /  \
     11    ->      10 ->      7    11
    /               \
   10                11

First Clockwise then anticlockwise

*/
int main()
{

    return 0;
}

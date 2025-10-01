#include <stdio.h>
#include <stdlib.h>


/*
We can perform rotate operations to balance a binary search tree such that the newly formed tree satisfies all the properties of a BST.
Two basic operations:
1. Left Rotate with respect to a node: Node is moved towards the left
2. Right Rotate with respect to a node: Node is moved towards the right
*/

/*
Example:
Left Rotating with respect to 9
        9
      / P \
     8     15
           / \
          11  20
P represents a pulley, only for understanding purposes

11 could not be attached, hence it is reinserted into the tree

After rotation:
        15
       /   \
     9     20
    / \
   8   11

If we right rotate the resultant tree, we will get the first tree that we started with

*/

/*
In order to balance an AVL tree after insertion, we can follow the following:
1. For a Left-Left insertion: Right rotate with respect to the first imbalanced node
2. For a Right-Right insertion: Left rotate with respect to the first imbalanced node
3. For a Left-Right Insertion: Left rotate once and then right rotate once
4. For a Right-Left Insertion: Right rotate once and then left rotate once
*/

/*
1. LL Insertion
Example:
Balanced tree
        11
       /  \
     9     18
    / \
  5    10
After insertion:
        11
       /  \
     9     18
    / \
   5    10
  /
 4

Right Rotation required with respect to 11 since it's balance factor is now 2

After Right Rotation: 10 needs to be reinserted into the tree
        9
      /   \
     5     11
    /     /  \
   4     10   18

4. Right Left Insertion
Example:
Balanced Tree:
        7
       / \
      1   10
            \
             17
After Insertion:
        7 -> 2
       / \
      1   10-> 2
            \
             17 -> 1
            /
           16 -> 0
Here two rotations are required
First rotation is done with respect to child of first imbalanced node in the insertion path
Child of first imbalanced node (10) = 17
After right rotation

        7 -> 2
       / \
      1   10-> 2
            \
             16 -> 1
               \
                17 -> 0

Second rotation is done with respect to first imbalanced node in the insertion path
First imbalanced node = 10
After left rotation:
        7
       / \
      1   16
         /  \
        10   17
*/
int main()
{

    return 0;
}

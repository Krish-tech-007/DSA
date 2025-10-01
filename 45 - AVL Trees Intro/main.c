#include <stdio.h>
#include <stdlib.h>

/*
Why do we need AVL trees?
1. Almost all of the operations in a Binary Search tree are of order O(h) where h is the height of the tree
2. If the tree is not planned properly, the height can get as high as n, where n is the number of nodes, i.e, skewed tree
3. To guarantee an upper bound of O(logn) for all these operations, we use balanced and AVL trees
*/

/*
What is an AVL tree?
It is a height balanced binary search tree
Height difference between the heights of left and right subtrees for every node is less than or equal to 1
Balanced factor = Height of left subtree - Height of right subtree. Can be calculated for every node
Can be -1, 0 or 1 for a node to be balanced in Binary Search Tree
Can be -1, 0 or 1 for all nodes of an AVL tree
*/

/*
It may happen that while inserting an element inside the tree, the balance factor will be updated and it goes out of range
To fix that we need to perform rotations
*/
int main()
{

    return 0;
}

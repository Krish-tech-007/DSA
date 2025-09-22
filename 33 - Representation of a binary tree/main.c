#include <stdio.h>
#include <stdlib.h>

/*
Representation of a binary tree: Methods / Ways
Primarily two ways
1. Arrays - Less used, size fixed
2. Linked List -
*/

/*
Using arrays:
If we have this given binary tree, it can be represented using arrays in the following manner
        7
       / \
     11   2
    / \   / \
   7   1 11  9
Root -> 0th Index
11 (1st level) -> 1st index
2 -> 2nd Index
7 (2nd level) -> 3rd index
1 -> 4th index
11 (2nd level) -> 5th index
9 -> 6th index

Array: 7 11 2 7 1 11 9

If our binary tree looked like this
        7
       / \
     11   2
    / \   / \
   7   1 11  9
  /           \
 2             11
 Root -> 0th Index
11 (1st level) -> 1st index
2 -> 2nd Index
7 (2nd level) -> 3rd index
1 -> 4th index
11 (2nd level) -> 5th index
9 -> 6th index
2 (3rd level) -> 7th index
NULL -> 8th index
NULL -> 9th index
NULL -> 10th index
NULL -> 11th index
NULL -> 12th index
NULL -> 13th index
11 (3rd level) -> 14th index

Array: 7 11 2 7 1 11 9 2 NULL NULL NULL NULL NULL NULL 11
So the array must be of size 15

We use binary tree for binary search
We want to create efficiently modifiable tree structure that can be expanded further in order to keep storing keys
Such that the search is in logn time and we can remove a given key at any time

Insertion and deletion is not easy using array representation
Extending the tree is also not a feasible choice
*/

/*
Linked representation of a binary tree
It is not called a linked list representation because list is a linear data structure
It uses pointers and is similar to linked list but is not linked list

We will use doubly linked list

If we have
        2
       / \
     1     4
    / \     \
  11  12     3

It will look
                                +-------+-------+-------+
                                |   L   |   2   |   R   |
                                +---+---+-------+---+---+
                                    |                   |
                                    v                   v
                      +-------+-------+-------+     +-------+-------+-------+
                      |   L   |   1   |   R   |     |   L   |   4   |   R   |
                      +---+---+-------+---+---+     +---+---+-------+---+---+
                          |           |                 X               |
                          v           v                                 v
   +-------+-------+-------+     +-------+-------+-------+       +-------+-------+-------+
   |   L   |  11   |   R   |     |   L   |  12   |   R   |       |   L   |   3   |   R   |
   +-------+-------+-------+     +-------+-------+-------+       +-------+-------+-------+
       X               X             X               X               X               X




*/

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
int main()
{

    return 0;
}

#include <stdio.h>
#include <stdlib.h>


/*
Bubble Sort:
Called bubble sort because just like in any medium the heaviest object will go deep and the lightest object will bubble up

Sorting will be done in passes
1st pass:
Compare Index 0 and 1, If incorrect order, swap.
Compare Index 1 and 2, If incorrect order, swap.
...
Compare Index n-2 and n-1, If incorrect order, swap.

By doing this, the largest element will go to the last index

In the second pass, we will do the same thing but we will limit the comparison before the last element since it is already in its correct position

After the second pass, the second largest element will be sorted as the second last element

After each pass, we will compare one less element than before

For n elements, we have to do at max n-1 passes

Example:
7 11 9 2 17 4
First pass: We did 5 comparisons. 5 swaps are possible
(0,1): 7 11 9 2 17 4
(1,2): 7 9 11 2 17 4
(2,3): 7 9 2 11 17 4
(3,4): 7 9 2 11 17 4
(4,5): 7 9 2 11 4  17

Second pass: We did 4 comparisons. 4 swaps are possible
(0,1): 7 9 2 11 4 17
(1,2): 7 2 9 11 4 17
(2,3): 7 2 9 11 4 17
(3,4): 7 2 9 4 11 17

Third pass: We did 3 comparisons. 3 swaps are possible
(0,1): 2 7 9 4 11 17
(1,2): 2 7 9 4 11 17
(2,3): 2 7 4 9 11 17

Fourth pass: We did 2 comparisons. 2 swaps are possible
(0,1): 2 7 4 9 11 17
(1,2): 2 4 7 9 11 17

Fifth pass: We did 1 comparisons. 1 swap is possible
(0,1): 2 4 7 9 11 17

Array is sorted

Total number of comparisons:
1 + 2 + 3 + 4 + 5 + ... + (n-1) = [ n(n-1) ] / 2 = O(n^2)

Is this stable algorithm? Yes, since the order is retained

Is this recursive algorithm? No, since recursion is not used

Is this an adaptive algorithm? By default is is not adaptive, but we can make it adaptive
If in the first pass, no comparisons are done then the array is sorted

If array is already sorted, the time complexity is O(n)

*/

int main()
{
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int *arr = (int *) malloc(sizeof(int) * size);

    printf("Enter elements into the array\n");
    for(int i = 0; i<size; i++){
        printf("Enter element at index %d: ", i);
        scanf("%d", arr+i);
    }

    // Bubble sort implementation
    for(int i = 0; i<size-1; i++){
        int isSorted = 1;
        for(int j = 0; j<size-i-1; j++){
            if(*(arr+j) > *(arr+j+1)){
                int temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            break;
        }
    }

    printf("Sorted array: ");
    for(int i = 0; i<size; i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");

    free(arr);
    return 0;
}

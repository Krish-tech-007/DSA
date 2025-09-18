#include <stdio.h>
#include <stdlib.h>


/*
Insertion sort is for when we want to insert an element into a sorted array
Here we enter an element into the rear of the array then keep on checking if the adjacent element is bigger, if yes we swap
We continue to do the swapping till the inserted element is greater than it's left adjacent element
*/

/*
Insertion sort can also be used to sort an unsorted array

Suppose we have an array of 5 elements
7 2 91 77 3

We consider 7 to be a single sorted array in which we try to insert an element
All elements to the right of the first element are considered unsorted

Now we try to insert 2 into the sorted array of 7

Now our sorted array is 2 7
We then try to insert 91 into the sorted array of 2 7

Now our sorted array is 2 7 91
We then try to insert 77 into our sorted array of 2 7 91

Now our sorted array is 2 7 77 91
We then try to insert 3 into our sorted array of 2 7 77 91

Now our sorted array is 2 3 7 77 91
*/

// We try to keep the left hand sorted and keep inserting the elements from the rights

// It takes n-1 steps at max to sort the array using Insertion sort
// In nth pass, we can do n swaps at max

// Time complexity: O(n^2)
// Best case: O(n)

// The algorithm is adaptive by default

// Is the algorithm stable? Yes

// After each iteration of insertion sort, we do not get any useful information
// Unlike bubble sort, where the large elements keep on pilling at the end
// Thus no useful intermediate information is obtained during the execution of insertion sort

void display(int *arr, int size){
    printf("Array: ");
    for(int i = 0; i<size; printf("%d ", *(arr+i)),i++);
    printf("\n");
}
int main()
{
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int *arr = (int *) malloc(sizeof(int) * size);

    printf("Enter elements into the array\n");
    for(int i = 0; i<size; i++){
        printf("Enter element at index %d: ", i+1);
        scanf("%d", (arr+i));
    }

    printf("Unsorted array: ");
    for(int i = 0; i<size; i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");

    // Insertion sort implementation
    for(int i = 0; i<size-1; i++){ // As i moves, elements before i+1 are sorted
        for(int j = i+1; j>0; j--){
            if(*(arr+j) < *(arr+j-1)){
                int temp = *(arr+j);
                *(arr+j) = *(arr+j-1);
                *(arr+j-1) = temp;
            }
            else{
                break;
            }
        }
    }

    printf("Sorted array: ");
    for(int i = 0; i<size; i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");

    return 0;
}

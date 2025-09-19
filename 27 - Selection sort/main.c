#include <stdio.h>
#include <stdlib.h>


/*
Selection sort:
We find the smallest element and bring it to the first index
We then find the second smallest element and bring it to the second index
And so on, so forth

We do a total of n-1 passes
We do a total of ( n(n+1) ) / 2 comparisons

Time complexity = O(n^2)
*/

/*
Analysis of the algorithm:
At 0th pass, we needed to do n-1 comparison and at most 1 swap
At 1st pass, we needed to do n-2 comparison and at most 1 swap
...
At n-2 pass, we needed to do 1 comparison and at most 1 swap
*/

/*
We can also determine the element of the minimum index and then swap after the inner loop ends
Then the maximum swaps would be be n-1
If the array is sorted, comparisons will happen but swapping won't happen

Is the algorithm stable? Not stable
Example: 7 8 8 1 8
Is the algorithm adaptive? No
*/



void display(int *arr, int size){
    printf("Array: ");
    for(int i = 0; i<size; printf("%d ", *(arr+i)),i++);
    printf("\n");
}

void selectionSort(int *arr, int size){
    for(int i = 0; i<size-1; i++){
        int minIndex = i;
        for(int j = i+1; j<size; j++){
            if(*(arr+minIndex) > *(arr+j))
                minIndex = j;
        }
        if(minIndex != i){
        int temp = *(arr+i);
        *(arr+i) = *(arr+minIndex);
        *(arr+minIndex) = temp;
        }
    }
}
int main()
{

    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int *arr = (int *) malloc(sizeof(int) * size);

    printf("Enter elements into the array\n");
    for(int i = 0; i<size; i++){
        printf("Enter element at Index %d: ", i+1);
        scanf("%d", arr+i);
    }

    printf("Unsorted ");
    display(arr, size);
    // Implementation of selection sort
    for(int i = 0; i<size-1; i++){
        for(int j = i+1; j<size; j++){
            if(*(arr+i) > *(arr+j)){
                int temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
            }
        }
    }

    printf("Sorted ");
    display(arr, size);

    free(arr);


    return 0;
}

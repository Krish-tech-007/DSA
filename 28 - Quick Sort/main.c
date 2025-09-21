#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int size){
    printf("Array: ");
    for(int i = 0; i<size; printf("%d ", *(arr+i)),i++);
    printf("\n");
}

void displayIndex(int *arr, int startIndex, int endIndex){
    printf("Received array: ");
    for(int i = startIndex; i<=endIndex; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int *arr, int startIndex, int lastIndex){
    if((lastIndex-startIndex)<=0){
        return;
    }
    int pivot = arr[lastIndex]; //pivot becomes last element
    int i, j, temp;
    j = startIndex;
    i = j-1;
    for(;j<lastIndex;j++){
        if(arr[j]<pivot){
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    // J reaches the index of the pivot element, J is holding that index now
    // Final resting place of pivot will be i+1
    i++;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    quickSort(arr, i+1, lastIndex);
    quickSort(arr, startIndex, i-1);
}

/*
Quick Sort Analysis:
Worst case: When array is already sorted
For array of size n, we have to partition the array n-1 times
Loop -> n times
Time complexity: O(n^2)

Best case: When the pivot comes right in the middle
Time complexity: O(nlogn)
Example: We have an array of 16
The pivot is in the middle so we split the array into 8 and 7
    8 gets divided into 4 and 3
        4 gets divided into 2 and 1
        3 gets divided into 1 and 1
    7 gets divided into 3 and 3
        3 gets divided into 1 and 1
        3 gets divided into 1 and 1

*/

/*
Debug Edition - Working implementation
For better understanding
void quickSort(int *arr, int startIndex, int lastIndex){
    printf("\nNew Call\n"); // Debug
    printf("%Difference: %d\n", lastIndex-startIndex); //Debug
    if((lastIndex-startIndex)<=0){
        return;
    }
    int pivot = arr[lastIndex]; //pivot becomes last element
    displayIndex(arr, startIndex, lastIndex); //Debug
    printf("Pivot: %d\n", pivot); //Debug
    int i, j, temp;
    j = startIndex;
    i = j-1;
    for(;j<lastIndex;j++){
        if(arr[j]<pivot){
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    // J reaches the index of the pivot element, J is holding that index now
    // Final resting place of pivot will be i+1
    i++;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    quickSort(arr, i+1, lastIndex);
    quickSort(arr, startIndex, i-1);

    /*
    if(i==0){ // If pivot's correct position is the first index
        quickSort(arr, i+1, lastIndex);
    }
    else if(i==lastIndex){
        quickSort(arr, startIndex, i-1);
    }
    else{
        quickSort(arr, i+1, lastIndex);
        quickSort(arr, startIndex, i-1);
    }
}
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

    printf("Unsorted ");
    display(arr, size);
    quickSort(arr, 0, size-1);
    printf("Sorted ");
    display(arr, size);


    free(arr);
    return 0;
}




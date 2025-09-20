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


/*

First try on own
void quickSort(int *arr, int beginningIndex, int endIndex){
    if(endIndex<=0 || beginningIndex <=0){
        return;
    }
    else{
        int pivot = arr[endIndex];
        int i,j;
        printf("Before entering for loop\n");
        display(arr, 5);
        for(j = beginningIndex, i=j-1; j<=endIndex; j++){
            if(arr[j] < pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        i++;
        printf("After for loop and before swap\n");
        display(arr, 5);
        swap(arr[i], arr[j-1]);

        printf("After for loop and pivot swap\n");
        display(arr, 5);
        printf("\n\n");
        quickSort(arr, i-1, endIndex-i);
        quickSort(arr, i+1, endIndex-i);

        return;

    }
}
*/

/*
Debug code:
void quickSort(int *arr, int beginning, int size){
    if(size<=1){
        return;
    }
    else{
        int pivot = *(arr+size-1);
        printf("Pivot element: %d\n", pivot);
        // Array - 1 2 3
        // To access 3, arr[2]
        // To access 3, *(arr+2)
        // To access last element, *(arr+size-1)

        int i,j;
        printf("Before entering for loop\n");
        display(arr, 5);
        for(j = beginning, i=j-1; j<size; j++){
            if(*(arr+j) < pivot){
                i++;
                swap(arr+i, arr+j);
            }
        }
        i++;
        printf("After for loop and before swap\n");
        display(arr, 5);
        swap(arr+i, arr+j-1);

        // 5 4 3 2 1
        //     p
        // 0, 5-2-1 = 2
        printf("After for loop and pivot swap\n");
        display(arr, 5);
        printf("\n\n");
        quickSort(arr, 0, size-i-1);
        quickSort(arr, i+1, size-i-1);

        return;

    }
}
*/




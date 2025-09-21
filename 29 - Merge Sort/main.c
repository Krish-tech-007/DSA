#include <stdio.h>
#include <stdlib.h>


/*
Merging Procedure:
Creates a sorted array by merging two sorted arrays
Example:
Sorted array 1: 7 9 8 19 22
Sorted array 2: 1 6 9 11
Final merged sorted array would be of size = sizeof(array1) + sizeof(array2)
Three index variables i-> for first array, j-> for second array, k-> for merged array
for loop k = 0 to k = total size - 1 times
At each iteration check if arr1[i]<arr2[j]
    If true  -> finalarr[k] = arr[i], i++
    If false -> finalarr[k] = arr[j], j++
*/

/*
Merge Sort is recursive
*/
void display(int *arr, int size){
    printf("Array: ");
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int * mergeSorted(int *arr1, int *arr2, int size1, int size2){
    int size = size1 + size2;
    int *arr3 = (int *) malloc(sizeof(int) * size);
    int i, j, k;
    i=j=k=0;
    for(;k<size;k++){
        if(arr1[i]<arr2[j]){
            arr3[k] = arr1[i];
            i++;
        }
        else{
            arr3[k] = arr2[j];
            j++;
        }
    }
    return arr3;
}
// Alternate implementation, checks bounds
int *merge(int *arr1, int *arr2, int size1, int size2){
    int totalSize = size1 + size2;
    int * arr3 = (int *) malloc(sizeof(int) * totalSize);
    int i,j,k;
    i = j = k = 0;
    while(i<size1 && j<size2){
        if(arr1[i]<arr2[j]){
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else{
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }
    while(i<size1){
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while(j<size2){
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    return arr3;
}

// Merging within the array
void mergeSortedArray(int *arr, int startIndex1, int endIndex1, int startIndex2, int endIndex2, int size){
    int i=startIndex1,j=startIndex2,k=0;
    int *mergedArr = (int *) malloc(sizeof(int) * size);
    while(i<=endIndex1 && j<=endIndex2){
        if(arr[i]<arr[j])
            mergedArr[k++] = arr[i++];
        else
            mergedArr[k++] = arr[j++];
    }
    while(i<=endIndex1)
        mergedArr[k++] = arr[i++];
    while(j<=endIndex2)
        mergedArr[k++] = arr[j++];

    k = 0;
    for(i = startIndex1; i<=endIndex1; arr[i] = mergedArr[k++],i++);
    for(j = startIndex2; j<=endIndex2; arr[j] = mergedArr[k++], j++);

    free(mergedArr);

}

void *mergeSort(int *arr, int startIndex, int endIndex){
    if(endIndex - startIndex <= 0){
        return;
    }
    int mid = (endIndex + startIndex) / 2;
    // If 4 elements, mid = (0+3) = 1.5 = 1, which is the second element
    // If 5 elements, mid = (0+4) = 2, which is the third element
    mergeSort(arr, startIndex, mid);
    mergeSort(arr, mid+1, endIndex);

    int size = (mid - startIndex+ 1) + (endIndex - mid + 1);
    mergeSortedArray(arr, startIndex, mid, mid+1, endIndex, size);
}
int main()
{

    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int *arr = (int *) malloc(sizeof(int) * size);

    printf("Enter elements into the array\n");
    for(int i = 0; i<size; i++){
        printf("Enter element at Index %d: ", i);
        scanf("%d", arr+i);
    }

    printf("Unsorted "); display(arr, size);
    mergeSort(arr, 0, size-1);
    printf("Sorted "); display(arr, size);

    free(arr);

    return 0;
}

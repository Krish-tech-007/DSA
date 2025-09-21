#include <stdio.h>
#include <stdlib.h>


// Count sort is one of the fastest sorting technique

/*
Procedure:
Select the maximum element from the given array
Create an auxiliary array of size = maximum element + 1
Initialize elements of the auxiliary array to 0

Traverse the original array,
Whenever we encounter an element, For example: We encounter 3, so we increment 1 at the 3rd index of the auxiliary array

Now after we complete traversing the original array, we will copy the elements into the original array
Copying elements sequentially that are greater than 0, if greater than 1, signifies more than 1 in existence, so if n, then n times copied

The auxiliary array tells us how many times each element is occurring in the given array
*/

/*
Analysis of count sort:
Time complexity: O(m+n) = O(n) since n is very large
Space complexity: O(m)

Benefit: Linear time
Drawback: It takes up lot of memory if the maximum element is too large
*/

void display(int *arr, int size){
    printf("Array: ");
    for(int i = 0; i<size; i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");
}
void countSort(int *arr, int size){
    int max = *(arr+0);
    for(int i = 1; i<size; i++)
        if(*(arr+i)>max)
            max = *(arr+i);

    int *sortedArr = (int *) malloc(sizeof(int) * max + 1);

    for(int i = 0; i<max+1; *(sortedArr+i)=0,i++);

    for(int i = 0; i<size; i++){
        int index = *(arr+i);
        sortedArr[index]++;
    }

    int index = 0;
    for(int i = 0; i<max+1; i++){
        if(*(sortedArr+i)==0)
            continue;
        while(*(sortedArr+i)>0){
            *(arr+index) = i;
            *(sortedArr+i) = *(sortedArr+i)-1;
            index++;
        }
    }

    free(sortedArr);
}
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

    display(arr, size);
    countSort(arr, size);
    display(arr, size);

    free(arr);
    return 0;
}

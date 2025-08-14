#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int n){
    // Traversal - Visiting each element of a data structure atleast once
    for(int i =0; i<n; i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

void indexInsertion(int *arr, int *size, int capacity, int element, int index){
    if(size>=capacity){
        printf("Cannot insert into the array. No space");
        return;
    }
    for(int i = *size; i>index;i--){
        *(arr+i) = *(arr+i-1);
    }
    *(arr+index) = element;
    *size = *size + 1;
}
int main()
{
    int arr[100]= {1,2,3,4,7,8,9,10};
    int size = 8, capacity = 100, element=5, index=4;
    display(arr,size);
    indexInsertion(arr, &size, capacity, element, index);
    display(arr,size);

    element = 6, index =5;
    indexInsertion(arr, &size, capacity, element, index);
    display(arr,size);
    return 0;
}

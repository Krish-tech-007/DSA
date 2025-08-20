#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int size){
    printf("Displaying array elements\n");
    for(int i = 0; i<size; i++){
        printf("%d ", *(arr+i));
    }
}
void delete(int *arr, int *size, int capacity, int index){
    for(int i = index; i<*size-1; i++){
        *(arr+i) = *(arr+i+1);
    }
    *size = *size - 1;
}
int main()
{
    int arr [10] = {1,2,3,4,5};
    int size = 5, capacity = 10, index = 2;
    delete(arr, &size, capacity, index);
    display(arr, size);
    return 0;
}

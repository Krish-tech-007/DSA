#include <stdio.h>
#include <stdlib.h>

void linearSearch(int *arr, int size, int element){
    for(int i = 0; i<size; i++){
        if(*(arr+i)==element){
            printf("Element found at index: %d\n", i);
            return;
        }
    }
}

void binarySearch(int *arr, int size, int element){
    int low = 0, high = size - 1, mid = (low+high) / 2;
    while(low<=high){
        if(*(arr+mid)==element){
            printf("Element found at index: %d\n", mid);
            return;
        }
        else if(element < *(arr+mid)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
        mid = (low+high) / 2;
    }
}
int main()
{
    int arr[100] = {1,2,3,4,5};
    int size = 5, element = 5;
    linearSearch(arr, size, element);
    binarySearch(arr, size, element);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

//ADT: Abstract Data Type
//It is a collection of set of values and set of operations that can be performed
// Structures are used to create custom datatypes in C
struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *sptr, int tsize, int usize){
    sptr->total_size = tsize;
    sptr->used_size = usize;
    sptr->ptr = (int *) malloc(sptr->total_size*sizeof(int)); //malloc is used for dynamic memory allocation from the heap
    //If we used stack memory, then the array would get deleted once the execution of the function ends
}

void show(struct myArray *sptr){
    for(int i = 0; i<sptr->used_size; i++){
        printf("%d\n", *(sptr->ptr+i));
    }
}

void setValue(struct myArray *sptr){
    for(int i = 0; i<sptr->used_size; i++){
        printf("Enter element at index %d: ", i);
        scanf("%d", (sptr->ptr+i));
    }
}

int main()
{
    struct myArray marks;
    createArray(&marks, 10, 2);
    setValue(&marks);
    show(&marks);
    return 0;
}

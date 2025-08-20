#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next; //Self referential structure
};

/*
void display(struct Node *head){
    //O(N) -> traversal
    struct Node *temp = head;
    printf("Displaying the elements\n");
    while(temp->next!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
    printf("\n");
}
*/


/*
void freeMemory(struct Node *head){
    struct Node *temp = head;
    struct Node *temp2;
    while(temp->next!=NULL){
        temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
    free(temp);
}
*/

/*
void insert(struct Node *head, int element){
    struct Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = (struct Node *) malloc(1*sizeof(struct Node));
    temp->next->data = element;
    temp->next->next = NULL;
}
*/


void insert(struct Node *ptr, int element){
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = (struct Node *) malloc(1*sizeof(struct Node));
    ptr->next->data = element;
    ptr->next->next = NULL;
}

void display(struct Node *ptr){
    //O(N) -> traversal
    printf("Displaying the elements\n");
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeMemory(struct Node *ptr){
    struct Node *temp;
    while(ptr!=NULL){
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
}

int main()
{
    struct Node *head;
    head = (struct Node *) malloc (1 * sizeof(struct Node));
    head->data = 1;
    head->next = NULL;

    insert(head, 10);
    insert(head, 20);

    display(head);

    freeMemory(head);
    return 0;
}

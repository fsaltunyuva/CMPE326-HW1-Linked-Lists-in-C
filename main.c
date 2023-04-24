#include <stdio.h>
#include <stdlib.h>

struct Node {
    int user_id;
    int item_id;
    int rating;
    struct Node* next;
};

void printList(struct Node* n)
{
    while (n != NULL) {
        printf("%d %d %d \n", n->user_id, n->item_id, n->rating);
        n = n->next;
    }
}

void insert(int user_id, int item_id, int rating){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->user_id = user_id;
    temp->item_id = item_id;
    temp->rating = rating;
}

int main()
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // allocate 3 nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->user_id = 1;
    head->item_id = 1;
    head->rating = 1;
    head->next = second;

    second->user_id = 2;
    second->item_id = 2;
    second->rating = 2;
    second->next = third;

    third->user_id = 3;
    third->item_id = 4;
    third->rating = 3;
    third->next = NULL;


    printList(head);

    return 0;
}
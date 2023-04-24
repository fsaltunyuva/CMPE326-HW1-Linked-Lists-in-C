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

void deleteNode(struct Node** head_ref, int par_user_id, int par_item_id)
{
    // Store head node
    struct Node *temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->user_id == par_user_id && temp->item_id == par_item_id) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->user_id != par_user_id && temp->item_id != par_item_id) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}

void append(struct Node** head_ref, int par_user_id, int par_item_id, int par_rating)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref;  /* used in step 5*/

    /* 2. put in the data  */
    new_node->user_id  = par_user_id;
    new_node->item_id  = par_item_id;
    new_node->rating  = par_rating;

    /* 3. This new node is going to be the last node, so make next
          of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

int average(struct Node** head_ref, int par_item_id){
    int sum = 0;
    int node_count = 0;
    struct Node *temp = *head_ref, *prev;

    while (temp != NULL) {
        if(temp->item_id == par_item_id){
            sum += temp->rating;
            node_count++;
        }
        prev = temp;
        temp = temp->next;
    }

    return sum/node_count;
}

int main()
{
    struct Node* head = NULL;

    //head = (struct Node*)malloc(sizeof(struct Node));

    //head->user_id = 1;
    //head->item_id = 1;
    //head->rating = 1;
    //head->next = second;

    append(&head, 1, 1, 1);
    append(&head, 2, 2, 2);
    append(&head, 4, 2, 4);
    append(&head, 3, 2, 6);
    append(&head, 3, 3, 3);
    deleteNode(&head, 1, 1);

    printf("%d\n", average(&head,2));

    printList(head);

    return 0;
}
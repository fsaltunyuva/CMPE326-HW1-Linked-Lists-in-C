#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int user_id;
    int item_id;
    int rating;
    struct Node* next;
};

void printList(struct Node* n)
{
    while (n != NULL) {
        printf("User ID:%d\tItem ID:%d\tRating:%d \n", n->user_id, n->item_id, n->rating);
        n = n->next;
    }
}

void deleteNode(struct Node** head_ref, int par_user_id, int par_item_id)
{
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->user_id == par_user_id && temp->item_id == par_item_id) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->user_id != par_user_id && temp->item_id != par_item_id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;

    free(temp);
}
/*
void update_data(struct Node** head_ref, struct Node** par_old, struct Node** par_new) {
    struct Node *curr = *head_ref;
    struct Node *old = *par_old;
    struct Node *new = *par_new;

    while(curr->next!=NULL) {
        if(curr->rating == old->rating) {
            curr->rating = new->rating;
            printf("\n%d found , replaced with %d\n", old, new);
            return;
        }
        curr = curr->next;
    }

    printf("%d does not exist in the list\n", old);
}
 */

void append(struct Node** head_ref, int par_user_id, int par_item_id, int par_rating)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    new_node->user_id  = par_user_id;
    new_node->item_id  = par_item_id;
    new_node->rating  = par_rating;

    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        printf("Customer rating (%d, %d) is added succesful\n", par_user_id, par_item_id);
        return;
    }

    int update_condition = 0;
    while (last->next != NULL){
        if(last->user_id == par_user_id && last->item_id == par_item_id){
            update_condition = 1;
            last->rating = par_rating;
            printf("Customer rating (%d, %d) is updated\n", par_user_id, par_item_id);
            break;
            //update_data(&*head_ref, &last, &new_node);
        }
        last = last->next;
    }

    if(update_condition != 1){ //If a value updated, do not try to add the element to the end
        last->next = new_node;

        printf("Customer rating (%d, %d) is added succesful\n", par_user_id, par_item_id);
    }

    return;
}

int average(struct Node** head_ref, int par_item_id){
    int sum = 0;
    int node_count = 0;
    int item_id_found = 0;
    struct Node *temp = *head_ref;

    while (temp != NULL) {
        if(temp->item_id == par_item_id){
            item_id_found = 1;
            sum += temp->rating;
            node_count++;
        }
        temp = temp->next;
    }

    if(item_id_found == 1){
        printf("Average rating (%d) is: %d \n", par_item_id, sum/node_count);
        return sum/node_count;
    }
    else{
        return 0;
    }

}

void rating_function(struct Node** head_ref, int par_user_id, int par_item_id){

    struct Node *temp = *head_ref, *prev;

    bool isPrinted = false;

    while (temp != NULL) {
        if(temp->user_id == par_user_id && temp->item_id == par_item_id){
            printf("Customer rating (%d, %d) is: %d \n", par_user_id, par_item_id, temp->rating);
            isPrinted = true;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if(!isPrinted) {
        printf("Customer rating (%d, %d) is: %d \n", par_user_id, par_item_id, 0);
    }
}

int main()
{
    struct Node* head = NULL;
    char input[20];
    int user_id;
    int item_id;
    int rating;

    while (1) {
        scanf("%19[^\n]", &input);
        char *p = strtok(input, " ");
        char *array[4];
        int i = 0;

        while (p != NULL){
            array[i++] = p;
            p = strtok(NULL, " ");
        }

        if(strcmp(array[0], "INSERT") == 0){
            sscanf(array[1], "%d", &user_id);
            sscanf(array[2], "%d", &item_id);
            sscanf(array[3], "%d", &rating);
            append(&head, user_id, item_id, rating);
            fgets(input, 20, stdin);
        }
        else if(strcmp(array[0], "RATING") == 0){
            sscanf(array[1], "%d", &user_id);
            sscanf(array[2], "%d", &item_id);
            rating_function(&head, user_id, item_id);
            fgets(input, 20, stdin);
        }
        else if(strcmp(array[0], "AVERAGE") == 0){
            sscanf(array[1], "%d", &item_id);
            average(&head, item_id);
            fgets(input, 20, stdin);
        }
        else if(strcmp(array[0], "REMOVE") == 0){
            sscanf(array[1], "%d", &user_id);
            sscanf(array[2], "%d", &item_id);
            deleteNode(&head, user_id, item_id);
            fgets(input, 20, stdin);
        }
        //DEBUG
        else if(strcmp(array[0], "PRINT") == 0){
            printList(head);
            fgets(input, 20, stdin);
        }
        //DEBUG
        else if(strcmp(array[0], "BREAK") == 0){
            break;
        }

        /*
        scanf("%s %d %d %d", &input, &user_id, &item_id, &rating);
        append(&head, user_id, item_id, rating);
        printList(head);
        */
    }

    //printList(head);

    return 0;
}
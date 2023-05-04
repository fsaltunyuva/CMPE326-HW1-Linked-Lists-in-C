#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int user_id;
    int item_id;
    double rating;
    struct Node *next;
};

void printList(struct Node *n) { //To debug the program on certain scenarios
    while (n != NULL) {
        printf("User ID:%d\tItem ID:%d\tRating:%.1lf \n", n->user_id, n->item_id, n->rating);
        n = n->next;
    }
}

void deleteNode(struct Node **head_ref, int par_user_id, int par_item_id) {
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->user_id == par_user_id && temp->item_id == par_item_id) { //Deletion of the head node
        *head_ref = temp->next;
        printf("Customer rating (%d,%d) is removed successful\n", par_user_id, par_item_id);
        free(temp);
        return;
    }

    while (temp != NULL && temp->user_id != par_user_id &&
           temp->item_id != par_item_id) { //Assigning prev and temp to the desired place
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) { //If given node does not exist
        printf("Customer rating (%d,%d) does not exist\n", par_user_id, par_item_id);
        return;
    }

    prev->next = temp->next; //Set previous node's next to the deleted node's next
    printf("Customer rating (%d,%d) is removed successful\n", par_user_id, par_item_id);
    free(temp);
}

void insertNode(struct Node **head_ref, int par_user_id, int par_item_id, double par_rating) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    struct Node *temp = *head_ref;

    new_node->user_id = par_user_id;
    new_node->item_id = par_item_id;
    new_node->rating = par_rating;

    new_node->next = NULL;

    if (*head_ref == NULL) { //If the linked list is empty, add the first node as head
        *head_ref = new_node;
        printf("Customer rating (%d, %d) is added successful\n", par_user_id, par_item_id);
        return;
    }

    int update_condition = 0; //If there is an update it is 1 otherwise 0
    int head_condition = 0; //If update occurs in the head node it is 1, otherwise 0
    int last_condition = 0; //If update occurs in the last node it is 1, otherwise 0

    if (temp->user_id == par_user_id && temp->item_id ==
                                        par_item_id) { //It checks that the condition of updating the head node (The last while loop in this function cannot check head node)
        update_condition = 1;
        head_condition = 1;
        temp->rating = par_rating;
        printf("Customer rating (%d, %d) is updated\n", par_user_id, par_item_id);
    }

    while (last->next != NULL) { //Assigning the last value to the last node in the instant linked list
        last = last->next;
    }

    if (last->user_id == par_user_id && last->item_id == par_item_id && head_condition ==
                                                                        0) { //It checks that the condition of updating the last node (The last while loop in this function cannot check the last node)
        update_condition = 1;
        last_condition = 1;
        last->rating = par_rating;
        printf("Customer rating (%d, %d) is updated\n", par_user_id, par_item_id);
    }

    while (temp->next != NULL && head_condition == 0 &&
           last_condition == 0) { //It checks the nodes between the head node and the last node
        if (temp->user_id == par_user_id && temp->item_id == par_item_id) {
            update_condition = 1;
            temp->rating = par_rating;
            printf("Customer rating (%d, %d) is updated\n", par_user_id, par_item_id);
            break;
        }
        temp = temp->next;
    }

    if (update_condition != 1) { //If a value updated, do not try to add the element to the end
        temp->next = new_node;

        printf("Customer rating (%d, %d) is added successful\n", par_user_id, par_item_id);
    }

    return;
}

double average(struct Node **head_ref, int par_item_id) {
    double sum = 0;
    int node_count = 0;
    int item_id_found = 0;
    struct Node *temp = *head_ref;

    while (temp != NULL) {
        if (temp->item_id == par_item_id) {
            item_id_found = 1;
            sum += temp->rating;
            node_count++;
        }
        temp = temp->next;
    }

    if (item_id_found == 1) {
        printf("Average rating (%d) is: %.1lf \n", par_item_id, sum / node_count);
        return sum / node_count;
    } else {
        printf("Average rating (%d) is: %.1lf \n", par_item_id, 0.0);
        return 0;
    }

}

void rating_function(struct Node **head_ref, int par_user_id,
                     int par_item_id) { //Named rating_function to prevent confusion with rating variable

    struct Node *temp = *head_ref;

    int isPrinted = 0;

    while (temp != NULL) {
        if (temp->user_id == par_user_id && temp->item_id == par_item_id) {
            printf("Customer rating (%d, %d) is: %.1lf \n", par_user_id, par_item_id, temp->rating);
            isPrinted = 1;
            break;
        }
        temp = temp->next;
    }

    if (isPrinted == 0) {
        printf("Customer rating (%d, %d) is: %.1lf \n", par_user_id, par_item_id, 0.0);
    }
}

int main() {
    struct Node *head = NULL;
    char input[20];
    int user_id;
    int item_id;
    double rating;

    while (1) {
        scanf("%19[^\n]", input);
        char *p = strtok(input, " ");
        char *array[4];
        int i = 0;

        while (p != NULL) {
            array[i++] = p;
            p = strtok(NULL, " ");
        }

        if (strcmp(array[0], "INSERT") == 0) {
            sscanf(array[1], "%d", &user_id);
            sscanf(array[2], "%d", &item_id);
            sscanf(array[3], "%lf", &rating);
            insertNode(&head, user_id, item_id, rating);
            fgets(input, 20, stdin);
        } else if (strcmp(array[0], "RATING") == 0) {
            sscanf(array[1], "%d", &user_id);
            sscanf(array[2], "%d", &item_id);
            rating_function(&head, user_id, item_id);
            fgets(input, 20, stdin);
        } else if (strcmp(array[0], "AVERAGE") == 0) {
            sscanf(array[1], "%d", &item_id);
            average(&head, item_id);
            fgets(input, 20, stdin);
        } else if (strcmp(array[0], "REMOVE") == 0) {
            sscanf(array[1], "%d", &user_id);
            sscanf(array[2], "%d", &item_id);
            deleteNode(&head, user_id, item_id);
            fgets(input, 20, stdin);
        } else if (strcmp(array[0], "break") == 0) {
            break;
        }
            //DEBUG
        else if (strcmp(array[0], "PRINT") == 0) {
            printList(head);
            fgets(input, 20, stdin);
        }//DEBUG
    }
    return 0;
}
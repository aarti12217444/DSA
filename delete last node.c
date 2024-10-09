#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Function to delete the last node in the list
struct node* delete_last(struct node *head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }

    if (head->link == NULL) {
        // If there's only one node, free it and return NULL
        free(head);
        return NULL;
    }

    struct node *temp = head;
    
    // Traverse to the second-to-last node
    while (temp->link->link != NULL) {
        temp = temp->link;
    }

    // Free the last node and set the second-to-last node's link to NULL
    free(temp->link);
    temp->link = NULL;

    return head;
}

// Function to print the linked list
void print_list(struct node *head) {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

int main() {
    // Initialize the linked list with three nodes
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->link = malloc(sizeof(struct node));
    head->link->data = 20;
    head->link->link = malloc(sizeof(struct node));
    head->link->link->data = 30;
    head->link->link->link = NULL;

    printf("Original list: ");
    print_list(head);

    // Delete the last node
    head = delete_last(head);

    printf("List after deleting the last node: ");
    print_list(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Function to delete the first node in the list
struct node* delete_first(struct node *head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }
    
    struct node *temp = head;  // Temporary pointer to store the current head
    head = head->link;         // Move the head pointer to the second node
    free(temp);                // Free the memory of the old head
    
    return head;  // Return the new head pointer
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

    // Delete the first node
    head = delete_first(head);

    printf("List after deleting the first node: ");
    print_list(head);

    return 0;
}

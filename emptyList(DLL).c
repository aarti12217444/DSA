#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Function to create an empty list (just initialize the head to NULL)
struct node* create_empty_list() {
    struct node *head = NULL;  // No nodes, so head is NULL
    return head;
}

// Function to check if the list is empty
int is_empty(struct node *head) {
    return head == NULL;
}

// Function to print the doubly linked list
void print_list(struct node *head) {
    if (is_empty(head)) {
        printf("List is empty!\n");
        return;
    }

    struct node *temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Create an empty doubly linked list
    struct node *head = create_empty_list();

    // Check if the list is empty
    if (is_empty(head)) {
        printf("The list is currently empty.\n");
    }

    // Print the empty list
    print_list(head);

    return 0;
}

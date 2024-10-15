#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Function to insert a node in an empty doubly linked list
struct node* addToEmpty(int data) {
    // Allocate memory for the new node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    // Initialize the new node
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;  // Return the new node as the head of the list
}

// Function to print the doubly linked list
void print_list(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Insert a node in an empty list
    struct node *head = NULL;
    head = addToEmpty(10);

    // Print the list
    printf("Doubly linked list after insertion: ");
    print_list(head);

    // Free the allocated memory
    free(head);

    return 0;
}

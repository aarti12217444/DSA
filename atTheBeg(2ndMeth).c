#include <stdio.h>
#include <stdlib.h>

// Define a struct for the node
struct node {
    int data;
    struct node *link;
};

// Function to add a node at the beginning of the list
void add_beg(struct node **head, int data) {
    struct node *ptr = malloc(sizeof(struct node)); // Allocate memory for the new node
    ptr->data = data;  // Set the data for the new node
    ptr->link = *head; // Point the new node to the current head
    *head = ptr;       // Update the head pointer to the new node
}

int main() {
    // Initialize the head node
    struct node *head = malloc(sizeof(struct node)); // Allocate memory for the head node
    head->data = 45;  // Set the data for the head node
    head->link = NULL; // Set the link to NULL (end of the list)
    
    // Add a second node
    struct node *ptr = malloc(sizeof(struct node)); // Allocate memory for another node
    ptr->data = 98;  // Set the data for the second node
    ptr->link = NULL; // Set the link to NULL
    head->link = ptr; // Link the head node to the second node

    // Add a new node at the beginning
    int data = 3;
    add_beg(&head, data);

    // Traverse and print the linked list
    ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data); // Print the data in each node
        ptr = ptr->link; // Move to the next node
    }

    return 0;
}

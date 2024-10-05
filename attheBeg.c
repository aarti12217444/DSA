#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node *link;
};

// Function to add a node at the beginning of the linked list
struct node* add_beg(struct node* head, int d) {
    struct node *ptr = malloc(sizeof(struct node));  // Allocate memory for the new node
    ptr->data = d;  // Set the data
    ptr->link = NULL;  // Set the link to NULL
    ptr->link = head;  // Point the new node to the current head
    head = ptr;  // Update the head to the new node
    return head;
}

int main() {
    // Creating the first node
    struct node *head = malloc(sizeof(struct node));  // Allocate memory for the head
    head->data = 45;  // Set the data for the head node
    head->link = NULL;  // Set the next link to NULL

    // Creating the second node
    struct node *ptr = malloc(sizeof(struct node));  // Allocate memory for the next node
    ptr->data = 545;  // Set the data for the second node
    ptr->link = NULL;  // Set the next link to NULL
    head->link = ptr;  // Link the head node to the second node

    // Adding a new node at the beginning
    int data = 3;
    head = add_beg(head, data);  // Update head to the new node added at the beginning

    // Traversing the linked list and printing the data
    ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);  // Print the data in the current node
        ptr = ptr->link;  // Move to the next node
    }

    return 0;
}

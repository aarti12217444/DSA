#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Function to insert a node at a certain position
void insert_at_position(struct node **head, int data, int position) {
    // Create a new node
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    // If inserting at the beginning (position 1)
    if (position == 1) {
        temp->link = *head;
        *head = temp;
        return;
    }

    // Traverse to the node just before the insertion position
    struct node *prev = *head;
    for (int i = 1; i < position - 1 && prev != NULL; i++) {
        prev = prev->link;
    }

    // Check if the position is valid (within the list)
    if (prev == NULL) {
        printf("Position out of bounds.\n");
        free(temp);
        return;
    }

    // Insert the new node
    temp->link = prev->link;
    prev->link = temp;
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
    // Initialize the linked list with one node
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    // Insert nodes at different positions
    insert_at_position(&head, 20, 2);  // Insert 20 at position 2
    insert_at_position(&head, 30, 3);  // Insert 30 at position 3
    insert_at_position(&head, 15, 2);  // Insert 15 at position 2
    insert_at_position(&head, 5, 1);   // Insert 5 at position 1 (beginning)

    // Print the list to verify
    print_list(head);

    return 0;
}

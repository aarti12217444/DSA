#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Function to delete a node at a specific position
struct node* delete_at_position(struct node *head, int position) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }

    // If the node to be deleted is the head (position 1)
    if (position == 1) {
        struct node *temp = head;
        head = head->link;
        free(temp);
        return head;
    }

    // Traverse to the node before the one to be deleted
    struct node *prev = head;
    for (int i = 1; i < position - 1; i++) {
        if (prev == NULL || prev->link == NULL) {
            printf("Invalid position.\n");
            return head;
        }
        prev = prev->link;
    }

    // Check if the node to be deleted exists
    if (prev->link == NULL) {
        printf("Invalid position.\n");
        return head;
    }

    struct node *temp = prev->link;  // The node to be deleted
    prev->link = temp->link;         // Bypass the node to be deleted
    free(temp);                      // Free the memory of the deleted node

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
    // Initialize the linked list with four nodes
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->link = malloc(sizeof(struct node));
    head->link->data = 20;
    head->link->link = malloc(sizeof(struct node));
    head->link->link->data = 30;
    head->link->link->link = malloc(sizeof(struct node));
    head->link->link->link->data = 40;
    head->link->link->link->link = NULL;

    printf("Original list: ");
    print_list(head);

    // Delete the node at the third position
    head = delete_at_position(head, 3);

    printf("List after deleting node at position 3: ");
    print_list(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Function to reverse the linked list
struct node* reverse(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->link;   // Store the next node
        current->link = prev;   // Reverse the current node's pointer
        prev = current;         // Move prev to the current node
        current = next;         // Move to the next node
    }

    head = prev;  // Update head to the new first node (previously the last node)
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

    // Reverse the linked list
    head = reverse(head);

    printf("Reversed list: ");
    print_list(head);

    return 0;
}

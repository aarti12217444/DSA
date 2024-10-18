#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Function to insert a node at a specific position in the list
struct node* insert_between(struct node *head, int data, int pos) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;

    // If inserting at the beginning (position 1)
    if (pos == 1) {
        new_node->prev = NULL;
        new_node->next = head;
        if (head != NULL) {
            head->prev = new_node;
        }
        head = new_node;
        return head;
    }

    // Traverse to the position before where the new node will be inserted
    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is out of bounds
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(new_node);
        return head;
    }

    // Insert between nodes
    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }

    temp->next = new_node;

    return head;
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

// Function to free the doubly linked list
void free_list(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct node *head = NULL;

    // Manually create a list: 10 <-> 20 <-> 30
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 10;
    head->prev = NULL;
    head->next = (struct node*)malloc(sizeof(struct node));
    
    head->next->data = 20;
    head->next->prev = head;
    head->next->next = (struct node*)malloc(sizeof(struct node));
    
    head->next->next->data = 30;
    head->next->next->prev = head->next;
    head->next->next->next = NULL;

    // Print the list before insertion
    printf("Before insertion:\n");
    print_list(head);

    // Insert node with value 25 between 20 and 30 (position 3)
    head = insert_between(head, 25, 3);

    // Print the list after insertion
    printf("After insertion:\n");
    print_list(head);

    // Free the entire list
    free_list(head);

    return 0;
}

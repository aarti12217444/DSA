#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

// Function to add a node to an empty list
struct node* addToEmpty(struct node *head, int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

// Function to add a node at the end of the list
struct node* addAtEnd(struct node *head, int data) {
    struct node *temp, *tp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    tp = head;
    while (tp->next != NULL) {
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;

    return head;
}

// Function to create a doubly linked list with n nodes
struct node* createList(struct node *head) {
    int n, data, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        return head;
    }

    printf("Enter the element for node 1: ");
    scanf("%d", &data);
    head = addToEmpty(head, data);

    for (i = 1; i < n; i++) {
        printf("Enter the element for node %d: ", i + 1);
        scanf("%d", &data);
        head = addAtEnd(head, data);
    }
    return head;
}

// Function to print the list
void printList(struct node *head) {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;

    // Create a doubly linked list
    head = createList(head);

    // Print the list
    printf("The elements in the list are: ");
    printList(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a doubly linked list node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to delete the first node of a doubly linked list
void deleteFirstNode(struct Node **head) {
    // Check if the list is empty
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    // Store the current head node in a temporary pointer
    struct Node *temp = *head;
    
    // Update the head pointer to the next node
    *head = (*head)->next;

    // If there is a next node, set its prev pointer to NULL
    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    // Free the memory of the removed node
    free(temp);
    printf("First node deleted.\n");
}

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Helper function to display the list
void displayList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create a doubly linked list with sample data
    struct Node *head = createNode(10);
    head->next = createNode(20);
    head->next->prev = head;
    head->next->next = createNode(30);
    head->next->next->prev = head->next;

    printf("Original list: ");
    displayList(head);

    // Delete the first node
    deleteFirstNode(&head);

    printf("List after deletion: ");
    displayList(head);

    return 0;
}

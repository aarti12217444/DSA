#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Function to insert a node at the beginning of the list
struct node* insertAtBeg(struct node* head, int data){
    struct node* new_node=malloc(sizeof(struct node));
    new_node->data=data;
    new_node->prev=NULL;
    new_node->next=head;
    
    if(head!= NULL){
        head ->prev = new_node;
    }
    head = new_node;
    return head;
}
// Function to print the doubly linked list
void print_list(struct node* head){
    struct node * temp=head;
    while(temp!=NULL){
       printf("%d <->",temp->data);
       temp=temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;

    // Insert nodes at the beginning
    head=insertAtBeg(head,10);
     head=insertAtBeg(head,20);
      head=insertAtBeg(head,30);
       head=insertAtBeg(head,40);

    // Print the list after insertion
    printf("After inserting: ");
    print_list(head);



    return 0;
}

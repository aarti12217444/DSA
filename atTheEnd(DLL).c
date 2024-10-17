#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node* atTheEnd(struct node *head, int data){
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    
    if(head==NULL){
       new_node->prev=NULL;
       return new_node;
    }
    
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    temp->next=new_node;
    new_node->prev=temp;
    
    return head;
}
void print_list(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
    printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    }

int main() {
    struct node *head = NULL;


    head = atTheEnd(head, 10);  
    head = atTheEnd(head, 20);  
    head = atTheEnd(head, 30);  


    printf("After insertion at the end:\n");
    print_list(head);


    free(head);

    return 0;
}







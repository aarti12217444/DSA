#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

void count_of_node(struct node *head){
    int count=0;
    if(head==NULL)
    printf("Linked List is empty");
    struct  node* ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->link;
    }
    printf("%d\n",count);
    
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    
    struct node *current = malloc(sizeof(struct node));
    current->data = 5;
    current->link = NULL;
    head->link=current;
    
    current=malloc(sizeof(struct node));
    current->data=78;
    current->link=NULL;
    head->link->link=current;

    count_of_node(head);
    
    printf("Data in the first node: %d\n", head->data);  
    printf("Data in the second node: %d\n", head->link->data);
    printf("Data in the third node: %d\n", head->link->link->data);
    

    return 0;
}

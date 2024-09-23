#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

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
    
    printf("Data in the first node: %d\n", head->data);  
    printf("Data in the second node: %d\n", head->link->data);
    printf("Data in the third node: %d\n", head->link->link->data);
    

    return 0;
}

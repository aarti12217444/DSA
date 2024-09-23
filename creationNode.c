#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

int main(){
    struct node *head = malloc(sizeof(struct node));
    if(head==NULL){
        printf("Memory allocation failed");
        return 1;
    }
    head->data = 45;
    head->link = NULL;
    
    struct node *current = malloc(sizeof(struct node));
    if(head==NULL){
        printf("Memory allocation failed");
        free(head);
        return 1;
    }
    current->data = 5;
    current->link = NULL;
    head->link=current;
    
    printf("Data in the first node: %d\n", head->data);  
    printf("Data in the second node: %d\n", current->data);
    
    free(head);
    free(current);
    
    return 0;
}



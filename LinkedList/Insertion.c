#include<stdio.h>
#include<stdlib.h>
int main(){
    //Declaration
    struct Node{
        int data;
        struct Node* next;
    };

    //Creation

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node)); 
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));

    // Assign data
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    new->data=14;
    new->next=NULL;

    //Insert at first
    new->next=head;

    struct Node* ptr=new;

    while(ptr!=NULL){
        printf("%d \n",ptr->data);
        ptr=ptr->next;
    }

    


    




    
    
    
    



}
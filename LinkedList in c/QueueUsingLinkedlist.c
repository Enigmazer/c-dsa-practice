/*Enqueue and dequeue operations using linked list*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;
node* head=NULL;

void enqueue(){
    int val;
    node* temp = malloc(sizeof(node));
    printf("Enter value = ");
    scanf("%d",&val);
    if(head==NULL){
        temp->data=val;
        temp->next=NULL;
        head=temp;
        return;
    }
    node* temp2=head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp->data=val;
    temp->next=NULL;
    temp2->next=temp;
}

void dequeue(){
    if(head==NULL){
        printf("Queue is empty.");
        return;
    }
    node* temp=head;
    printf("Removed element is: %d",temp->data);
    head=temp->next;
    free(temp);
}

int main(){
    int choice;
    printf("\n1.Enqueue\n2.Dequeue\n3.EXIT");
    do{
        printf("\nEnter choice = ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Exiting.....");
                return 0;
            default:
                printf("Invalid choice.");
        }
    }while(1);
}
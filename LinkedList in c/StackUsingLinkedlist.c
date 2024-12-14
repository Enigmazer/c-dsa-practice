/*Push and pop operations using linked list*/

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int data;
    struct node *next;
}node;
node *head=NULL;

node* push(){
    int value;
    node *temp = malloc(sizeof(node));
    printf("Enter value for insertion = ");
    scanf("%d",&value);
    temp->data=value;
    temp->next=head;
    return temp;
}

void pop(){
    if(head==NULL){
        printf("Stack is empty.");
        return;
    }
    node *temp=head;
    printf("Poped element is %d",temp->data);
    head=temp->next;
    free(temp);
}


int main(){
    int choice;
    printf("\n1.Push\n2.Pop\n3.EXIT");
    do{
    printf("\nEnter choice = ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            head=push();
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("\nExiting.....");
            return 0;
        default:
            printf("Invalid choice");
    }}while(1);
}
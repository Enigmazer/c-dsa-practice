/* This is a simple linkedlist program made in c
Author - Arun (enigmazer)
*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

int value(){
	int val;
	printf("Enter value for insertion = ");
	scanf("%d",&val);
	return val;
}
struct node * createNode(int val){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data=val;
	newNode->next=NULL;
	return newNode;
}
struct node * insAtFirst (struct node *headptr,int val){
	struct node *ptr = createNode(val);
	ptr->next = headptr;
	return ptr;
}
struct node * insAnywhere (struct node *headptr,int val){
	int idx,i=1;
	printf("Enter index = ");
	scanf("%d",&idx);
	if(idx==0){
		return insAtFirst(headptr,val);
	}else{
	struct node *ptr = createNode(val);
	struct node *p = headptr;
	while(p!=NULL && i!=idx){
		p=p->next;
		i++;
	}
	if(p==NULL){
		printf("error: Index out of bond\n");
	}else{
		ptr->next=p->next;
		p->next=ptr;
	}
	}
	return headptr;
}
struct node * insAtLast (struct node *headptr,int val){
	if(isEmpty(headptr)){
		headptr=insAtFirst(headptr,val);
		return headptr;
	}else{
	struct node *ptr = createNode(val);
	struct node *p = headptr;
	while(p->next!=NULL){
	      p=p->next;
	}
	p->next=ptr;
	return headptr;
	}
}
void display (struct node *headptr){
	if(isEmpty(headptr)){
		printf("LinkedList is Empty\n");
	}else{
		while(headptr!=NULL){
			printf("Data: %d\n",headptr->data);
			headptr=headptr->next;
		}
	}
}
struct node * deleteFront(struct node *headptr){
	if(isEmpty(headptr)){
		printf("LinkedList is Empty\n");
		return headptr;
	}else{
	struct node *temp=headptr;
	printf("Deleted Element is: %d\n",temp->data);
	headptr=temp->next;
	free(temp);
	return headptr;
	}
}
struct node * deleteAnywhere(struct node *headptr){
	if(isEmpty(headptr)){
		printf("LinkedList is Empty\n");
		return headptr;
	}else{
	int i=1,idx;
	struct node *temp=headptr;
	printf("Enter index of the value you want to delete = ");
	scanf("%d",&idx);
	if(idx==0){
		headptr=deleteFront(headptr);
		return headptr;
	}else{
		while(temp!=NULL && i!=idx){
			temp=temp->next;
			i++;
		}
		if(temp->next==NULL){
			printf("Provided index is alredy empty\n");
		}else{
		printf("Deleted Element is: %d\n",temp->next->data);
		temp->next=temp->next->next;
		}
	}
	return headptr;
	}
}
struct node * deleteLast(struct node *headptr){
	if(isEmpty(headptr)){
		printf("LinkedList is Empty\n");
		return headptr;
	}else{
	if(headptr->next==NULL){
		//headptr=deleteFront(headptr);
		printf("Deleted Element is: %d\n",headptr->data);
		headptr=NULL;
		return headptr;
	}else{
	struct node *p=headptr;
	struct node *q=p->next;
	while (q->next!=NULL){
		p=p->next;
		q=p->next;
	}
	printf("Deleted Element is: %d\n",q->data);
	p->next=NULL;
	free(q);
	return headptr;
	}
	}
}
int isEmpty(struct node *headptr){
	if(headptr==NULL){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	int op,val;
	struct node *head=NULL;
clrscr();
       //	do{
	printf("\nOperations\n 1.Insert at first\n 2.Insert anywhere in list\n 3.Insert at last\n 4.Display\n 5.Delete front\n 6.Delete anywhere in list\n 7.Delete last\n 8.Is linkedlist empty\n 9.Exit\n");
	do{
	printf("Select option = ");
	scanf("%d",&op);
		switch(op){
		case 1:
			val=value();
			head=insAtFirst(head,val);
		break;
		case 2:
			val=value();
			head=insAnywhere(head,val);
		break;
		case 3:
			val=value();
			head=insAtLast(head,val);
		break;
		case 4:
			display(head);
		break;
		case 5:
			head=deleteFront(head);
		break;
		case 6:
			head=deleteAnywhere(head);
		break;
		case 7:
			head=deleteLast(head);
		break;
		case 8:
			if(isEmpty(head)){
				printf("LinkedList is Empty\n");
			}else{
				printf("LinkedList is not Empty\n");
			}
		break;
		case 9:
			printf("EXITING....");
		break;
		default:
			printf("Invalid option\n");
		}
	}while(op!=9);
getch();
return 0;
}
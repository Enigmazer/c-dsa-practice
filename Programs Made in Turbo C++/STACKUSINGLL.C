/*
Stack using linkedlist
Dynamic(runtime memory allocatoin) Stack*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define maxsize 5;
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;

void push(){

	int val,max,count;
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	count = st_count();
	max=maxsize;
	if (count<max){
	scanf("%d",&val);
	temp->data = val;
	temp->next = head;
	head = temp;
	}else{
	printf("overflow");
	}
}
void pop(){
	struct node *temp;
	if(head==NULL){
	   printf("Stack is underflow\n");
	}else{
	temp=head;
		printf("the deleted element is %d\n",temp->data);
		head=head->next;
		free(temp);
	}
}
void empty(){
	if(head==NULL){
		printf("empty");
	}else{
		printf("not empty");
	}
}
void full(){
	int count,max;
	max=maxsize;
	count=st_count();
	if(count==max){
		printf("full");
	}else{
		printf("not full");
	}
}
int st_count(){
	int count=0;
	struct node *temp;
	temp = head;
	while(temp!=NULL){
		temp=temp->next;
		count++;
	}
	return count;
}
void display(){
	struct node *temp;
	if(head==NULL){
	   printf("Stack is underflow\n");
	}else{
		temp = head;
		while(temp!=NULL){
			printf("data = %d\n",temp->data);
			temp=temp->next;
		}
	}
}


int main () {
	// int max = 5;
	 int options;
clrscr();
	// printf("Enter the size of the array = ");
	// scanf("%d",&n);
	// a=(int*)malloc(n*sizeof(int));
	 printf("Choose option :- \n1.Push\n2.Pop\n3.Display\n4.Is Empty\n5.Is full\n6.EXIT\n");

	 do{
	 printf("\nOption = ");
	 scanf("%d",&options);
	 switch(options){
	 case 1:
		push();
	 break;
	 case 2:
		pop();
	 break;
	 case 3:
		display();
	 break;
	 case 4:
		empty();
	 break;
	 case 5:
		full();
	 break;
	 case 6:
		printf("EXITING.....");
	 break;
	 default:
		printf("Invalid input\n");
	 }}while(options!=6);

getch();
return 0;
}

/* stack can be defined as a container in which insertion
and deletion can be done from one end which is known as top of the stack */

/*
use of stack
1.stack is used for balancing of symbols
2.for reversing the string
3.undo and redo operations
4.recursive function
5.expresion conversion (exprsn - prefix,postfix,infix)
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int top=-1,*a,n;
void push(){
	if(top>n-2){
	printf("Stack is full\n");
	}else{
	top++;
	scanf("%d",(a+top));
	}
}
void pop(){
	if(top<0){
	   printf("Stack is underflow\n");
	}else{
		printf("the deleted element is %d\n",*(a+top));
		top--;
	}
}
void display(){
	int i;
	if(top<0){
	   printf("Stack is underflow\n");
	}else{
	for(i=top; i>=0; i--){
	printf("%d\n",*(a+i));
	}}
}


int main () {
	// int max = 5;
	 int options;
clrscr();
	 printf("Enter the size of the array = ");
	 scanf("%d",&n);
	 a=(int*)malloc(n*sizeof(int));
	 printf("Choose option :- \n1.Push\n2.Pop\n3.Display\n4.EXIT\n");

	 do{
	 printf("Option = ");
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
		printf("EXITING.....");
	 break;
	 default:
		printf("Invalid input\n");
	 }}while(options!=4);


getch();
return 0;
}
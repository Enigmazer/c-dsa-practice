#include<stdio.h>
#include<conio.h>

int top=-1,a[5];
void push(){
	if(top>=4){
	printf("Stack is full\n");
	}else{
	top++;
	scanf("%d",&a[top]);
	}
}
void pop(){
	if(top<0){
	   printf("Stack is underflow\n");
	}else{
		printf("the deleted element is %d\n",a[top]);
		top--;
	}
}
void display(){
	int i;
	if(top<0){
	   printf("Stack is underflow\n");
	}else{
	for(i=top; i>=0; i--){
	printf("%d\n",a[i]);
	}}
}


int main () {
	// int max = 5;
	 int options;
clrscr();
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
		printf("Invalid input");
	 }}while(options!=4);


getch();
return 0;
}
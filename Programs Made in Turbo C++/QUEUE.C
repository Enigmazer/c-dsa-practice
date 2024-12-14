/* Queue Program */

#include<stdio.h>
#include<conio.h>

#define max 5

int r=-1,f=-1,a[max];

void insert(){
	int val;
	if(r==max-1){
		printf("Overflow\n");
	}else{
		if(f==-1){
			f++;
		}
		r++;
		printf("Enter value for insertion = ");
		scanf("%d",&val);
		a[r]=val;
	}
}
void deletel(){
	int temp;
	if(f==-1){
		printf("Underflow\n");
	}else{
		temp=a[f];
		printf("Deleted element is = %d",temp);
		if(f==r){
			f=-1;
			r=-1;
		}else{
		f++;
		}
	}
}
void display(){
	int i;
	if(f==-1){
		printf("Underflow\n");
	}else{
		for(i=f; i<=r; i++){
			printf("Element: %d\n",a[i]);
		}
	}
}

int main(){
	 int op;
clrscr();
	 printf("Choose option :- \n1.Insert\n2.Delete\n3.Display\n4.EXIT\n");

	 do{
	 printf("\nOption = ");
	 scanf("%d",&op);
	 switch(op){
	 case 1:
		insert();
	 break;
	 case 2:
		deletel();
	 break;
	 case 3:
		display();
	 break;
	 case 4:
		printf("EXITING.....");
	 break;
	 default:
		printf("Invalid input\n");
	 }}while(op!=4);

getch();
return 0;
}
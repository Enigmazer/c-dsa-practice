/* This is a temperature reading managment system and
it stores the last 5 readings at a time*/

#include<stdio.h>
#include<conio.h>

#define max 5

int r=-1,f=-1,a[max];

void insert(){
	int val;
	if((r+1)%max==f){
		f++;
	}
		if(f==-1){
			f=0;
		}
		r=(r+1)%max;
		printf("Enter temperature reading = ");
		scanf("%d",&val);
		a[r]=val;
}
/*void deletel(){
	int temp;
	if(f==-1){
		printf("No redings found\n");
		return;
	}
		temp=a[f];
		printf("Deleted reading is = %d degrees",temp);
		if(f==r){
			f=-1;
			r=-1;
		}else{
			f=(f+1)%max;
		}
} */
void display(){
	int i;
	if(f==-1){
		printf("No redings found\n");
	}else{
		i=f;
		printf("Readings are :\n");
		while(i!=r){
			printf("%d degrees\n",a[i]);
			i=(i+1)%max;
		}
		printf("%d degrees\n",a[r]);
	}
}

void main(){
	 int op;
clrscr();
	 printf("Choose option :- \n1.Insert reading\n2.Display readings\n3.EXIT\n");

	 do{
	 printf("\nOption = ");
	 scanf("%d",&op);
	 switch(op){
	 case 1:
		insert();
	 break;
	 case 2:
		display();
	 break;
	 case 3:
		printf("EXITING.....");
		getch();
	 break;
	 default:
		printf("Invalid input\n");
	 }}while(op!=3);
}
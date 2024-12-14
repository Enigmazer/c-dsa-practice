/* Patients Managment System using priority
  queue (it's not circular priority queue) */

#include<stdio.h>
#include<conio.h>
#include<string.h>

#define max 4

int r=-1,f=-1,a[max];
typedef struct{
	char name[16];
}string;
string name[max];

void sortList(){
	int i,j,temp,swapped,i2=0;
	string tempN;
	string tempN2;
	for(i=f; i<r; i++){
		swapped=0;
		for(j=f; j<r-i2; j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				tempN=name[j];
				tempN2=name[j+1];
				name[j]=tempN2;
				name[j+1]=tempN;
				swapped=1;
			}
		}
		i2++;
		if(swapped==0){
			break;
		}
	}
}

void addP(){
	if(r==max-1){
		printf("List is full\n");
	}else{
		if(f==-1){
			f=0;
		}
		r++;
		printf("Enter patient name(use '_' insted of space) = ");
		scanf("%s",&name[r].name);
		printf("Enter %s's priority(1-10) according to their condition = ",name[r].name);
		scanf("%d",&a[r]);
	}
}
void removeP(){
	if(f==-1){
		printf("List is Empty\n");
	}else{
		sortList();
		printf("%s is removed from list\n",name[f].name);
		if(f==r){
			f=-1;
			r=-1;
		}else{
		f++;
		}
	}
}
void displayPList(){
	int i,j;
	if(f==-1){
		printf("List is empty\n");
	}else{
		sortList();
		printf("_________________________________________________________________________\n");
		j=1;
		for(i=f; i<=r; i++){
			printf("Patient %d:  Name: %-16s|  Priority: %d\n",j,name[i].name,a[i]);
			j++;
		}
		printf("_________________________________________________________________________");
	}
}

void main(){
	 int choice;
clrscr();
	 printf("-- Patients Managment System --");
	 printf("\n1.Add patient\n2.Remove patient\n3.Display patient list\n4.Close System");
	 do{
		printf("\nEnter choice = ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				addP();
				break;
			case 2:
				removeP();
				break;
			case 3:
				displayPList();
				break;
			case 4:
				printf("\nClosing.....");
				getch();
				break;
			default:
				printf("Invalid Choice");
		}
	 }while(choice!=4);
}
/* Insertion Sort */


#include<stdio.h>
#include<conio.h>

int main(){
	 int a[10]={43,5,7,3,41,4,6,87,3,21};
	 int i,j,key;
clrscr();
	for(i=1; i<10; i++){
		key=a[i];
		j=i;
		while(j>0 && a[j-1]>key){
			a[j]=a[j-1];
			j--;
		}
		a[j]=key;
	}
	for(i=0; i<10; i++){
		printf("A = %d\n",a[i]);
	}
getch();
return 0;
}

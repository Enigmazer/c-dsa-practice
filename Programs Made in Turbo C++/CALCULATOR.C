/* This is a simple calculator */


#include<stdio.h>
#include<conio.h>

void main() {
    double a[1000],total=0;
    int i;
    char ch;

    clrscr();

    printf("\n------------ Instructions ------------\n\nThis are the operators you can use\n 1.+(add)\n 2.-(subtract)\n 3.*(multiply)\n 4./(divide) \n");
    printf("\nNOTE : Enter '=' sign when asked for operator to end the calculation\n");
    printf("\nEnter no. : ");
    scanf("%lf",&total);

    for (i=1; i<1000; i++) {

	printf("\nEnter operator : ");
	scanf(" %c",&ch);

	if(ch == '=' ) {
	    printf("Total = %.3lf", total);
	    getch();
	    return 0;
	}

	printf("\nEnter no. : ");
	scanf("%lf",&a[i]);

	switch (ch) {
	    case '+': total=total+a[i];
	    break;
	    case '-': total=total-a[i];
	    break;
	    case '*': total=total*a[i];
	    break;
	    case '/': if(a[i] == 0 || total == 0) {
		 printf("can't divide by 0\n");
	    } else {
		     total=total/a[i];
	    }
	    break;
	    default : printf("Choose a valid operator");
	    break;
	}
    }

    printf("\nTotal = %lf",total);

    getch();
}
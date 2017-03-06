//Lab 3: Simple Calculator
//Zachary Shumate
//9-9-1014
//Section 1

#include<stdio.h>

main(){
	int operation;
	do{
	
		printf("\n\nCalculator Menu\n");
		printf("(1) Addition\n");
		printf("(2) Subtraction\n");
		printf("(3) Multiplication\n");
		printf("(4) Division\n");
		printf("(5) Modulus (integers only)\n");
		printf("(6) Test if prime (integers only)\n");
		printf("(7) Exit\n");
	
		printf("\nPlease choose an operation: ");
		scanf("%d",&operation);
	
		switch(operation){
			float n1;
			float n2;
			int number1;
			int number2;
			
			case 1:
				printf("Enter the first number: ");
				scanf("%f",&n1);
				printf("Enter the second number: ");
				scanf("%f",&n2);
				printf("\n%.2f + %.2f = %.2f",n1,n2,n1+n2);
				break;
			case 2:
				printf("Enter the first number: ");
				scanf("%f",&n1);
				printf("Enter the second number: ");
				scanf("%f",&n2);
				printf("\n%.2f - %.2f = %.2f",n1,n2,n1-n2);
				break;
			case 3:
				printf("Enter the first number: ");
				scanf("%f",&n1);
				printf("Enter the second number: ");
				scanf("%f",&n2);
				printf("\n%.2f * %.2f = %.2f",n1,n2,n1*n2);
				break;
			case 4:
				printf("Enter the first number: ");
				scanf("%f",&n1);
				printf("Enter the second number: ");
				scanf("%f",&n2);
				printf("\n%.2f / %.2f = %.2f",n1,n2,n1/n2);
				break;
			case 5:
				printf("Enter the first number: ");
				scanf("%d",&number1);
				printf("Enter the second number: ");
				scanf("%d",&number2);
				printf("\n%d %% %d = %d",number1,number2,number1%number2);
				break;
			case 6:
				printf("Enter the number to be tested: ");
				scanf("%d",&number1);
				for(number2=number1-1;number2>1;number2--){
					if(number1%number2==0){
						printf("\nNot prime: %d * %d = %d",number2,number1/number2,number1);
						break;
					}
				}
				if(number2==1){
					printf("\n%d is prime",number1);
				}
				break;
			case 7:
				printf("\nGood Bye!");
				break;
		}
	}while(operation!=7);
}

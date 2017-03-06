//Lab 4: Simple Calculator
//Zachary Shumate
//9-16-1014
//Section 1

#include<stdio.h>

float addition(float,float);
float subtraction(float,float);
float multiplication(float,float);
float division(float,float);
int modulus(int,int);
void prime(int);
int factorial(int);
float power(float,float);
void fibonacci(int);

main(){
	int operation;
	do{
	
		printf("\n\nCalculator Menu\n");
		printf("(1) Addition\n");
		printf("(2) Subtraction\n");
		printf("(3) Multiplication\n");
		printf("(4) Division\n");
		printf("(5) Modulus (integers only)\n");
		printf("(6) Test if Prime (integers only)\n");
		printf("(7) Factorial (integers only)\n");
		printf("(8) Power\n");
		printf("(9) Fibonacci Sequence\n");
		printf("(0) Exit\n");
	
		printf("\nPlease choose an operation: ");
		scanf("%d",&operation);
	
		switch(operation){
			float n1;
			float n2;
			int number1;
			int number2;
			int i;
			
			case 1:
				printf("Enter the first number: ");
				scanf("%f",&n1);
				printf("Enter the second number: ");
				scanf("%f",&n2);
				printf("\n%.2f + %.2f = %.2f",n1,n2,addition(n1,n2));
				break;
			case 2:
				printf("Enter the first number: ");
				scanf("%f",&n1);
				printf("Enter the second number: ");
				scanf("%f",&n2);
				printf("\n%.2f - %.2f = %.2f",n1,n2,subtraction(n1,n2));
				break;
			case 3:
				printf("Enter the first number: ");
				scanf("%f",&n1);
				printf("Enter the second number: ");
				scanf("%f",&n2);
				printf("\n%.2f * %.2f = %.2f",n1,n2,multiplication(n1,n2));
				break;
			case 4:
				printf("Enter the first number: ");
				scanf("%f",&n1);
				printf("Enter the second number: ");
				scanf("%f",&n2);
				printf("\n%.2f / %.2f = %.2f",n1,n2,division(n1,n2));
				break;
			case 5:
				printf("Enter the first number: ");
				scanf("%d",&number1);
				printf("Enter the second number: ");
				scanf("%d",&number2);
				printf("\n%d %% %d = %d",number1,number2,modulus(number1,number2));
				break;
			case 6:
				printf("Enter the number to be tested: ");
				scanf("%d",&number1);
				prime(number1);
				break;
			case 7:
				printf("Enter a number: ");
				scanf("%d",&number1);
				printf("\nThe factorial of %d is %d",number1,factorial(number1));
				break;
			case 8:
				printf("Enter a number: ");
				scanf("%f",&n1);
				printf("Enter the power: ");
				scanf("%f",&n2);
				printf("\n%.2f raised to the %.2f power is %.2f",n1,n2,power(n1,n2));
				break;
			case 9:
				printf("How many numbers of he Fibonacci Sequence would you like to see: ");
				scanf("%d",&number1);
				fibonacci(number1);
				break;
			case 0:
				printf("\nGood Bye!");
				break;
		}
	}while(operation!=0);
}

float addition(float n1,float n2){
	return n1+n2;
}
float subtraction(float n1,float n2){
	return n1-n2;
}
float multiplication(float n1,float n2){
	return n1*n2;
}
float division(float n1,float n2){
	return n1/n2;
}
int modulus(int number1,int number2){
	return number1%number2;
}
void prime(int number1){
	int number2;
	for(number2=number1-1;number2>1;number2--){
		if(number1%number2==0){
			printf("\nNot prime: %d * %d = %d",number2,number1/number2,number1);
			break;
		}
	}
	if(number2==1){
		printf("\n%d is prime",number1);
	}
}
int factorial(int n1){
	int number=1;
	for(n1;n1>0;n1--){
		number*=n1;
	}
	return number;
}
float power(float n1,float power){
	float i;
	float number=1;
	for(i=0;i<power;i++){
		number*=n1;
	}
	return number;
}
void fibonacci(int n1){
	int i;
	int fibonacci[n1];
	fibonacci[0]=1;
	fibonacci[1]=1;
	printf("%d\n%d\n",fibonacci[0],fibonacci[1]);
	for(i=2;i<n1;i++){
		fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
		printf("%d\n",fibonacci[i]);
	}
}

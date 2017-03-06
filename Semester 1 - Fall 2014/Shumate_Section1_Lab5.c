//Lab 5: Story
//Zachary Shumate
//9-23-1014
//Section 1

#include<stdio.h>
#include<time.h>

main(){
	char name[50];
	int age;
	char color[50];
	char hobby[50];
	char animal[50];
	char time[50];
	int r1=rand()%3;
	int r2=rand()%3;
	int r3=rand()%3;
	
	printf("\nWhat is your name? ");
	scanf("%s",&name);
	printf("\nWhat is your age? ");
	scanf("%d",&age);
	printf("\nWhat is your favorite color? ");
	scanf("%s",&color);
	printf("\nWhat is your favorite hobby? ");
	scanf("%s",&hobby);
	printf("\nWhat is your favorite animal? ");
	scanf("%s",&animal);
	
	char *pName=&name;
	char *pColor=&color;
	char *pAnimal=&animal;
	char *pHobby=&hobby;
	
	printf("\n\n%s was stranded on an island at the age of %d with nothing but a %s ",pName,age,pColor);
	switch(r1){
		case 0:
			printf("rowboat. ");
			break;
		case 1:
			printf("spaceship. ");
			break;
		case 2:
			printf("wagon. ");
			break;
	}
	printf("%s did %s everyday until %s found a ",pName,pHobby,pName);
	switch(r2){
		case 0:
			printf("tiny %s. ",pAnimal);
			break;
		case 1:
			printf("large %s. ",pAnimal);
			break;
		case 2:
			printf("%s. ",pAnimal);
			break;
	}
	switch(r3){
		case 0:
			printf("%s lived a satisfying life on the island. ",pName);
			break;
		case 1:
			printf("%s was rescued from the island. ",pName);
			break;
		case 2:
			printf("%s became the absolute ruler of the island. ",pName);
			break;
	}
}

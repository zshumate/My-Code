//Lab 6: Phone Book
//Zachary Shumate
//9-30-1014
//Section 1

#include<stdio.h>

typedef struct friend{
	char firstName[50];
	char lastName[50];
	char phoneNumber[50];
}f;

void addFriend(f*);
void deleteFriend(f*);
void showPhoneBook(f*);

int counter = 0;

main(){
	int operation;
	f *phoneBook = (f*)malloc(sizeof(f));
	
	do{
		printf("\n\nPhone Book Application\n");
		printf("(1) Add Friend\n");
		printf("(2) Delete Friend\n");
		printf("(3) Open Phone Book\n");
		printf("(0) Exit\n");
	
		printf("\nWhat do you want to do? ");
		scanf("%d",&operation);
	
		switch(operation){
			case 1:
				addFriend(phoneBook);
				break;
			case 2:
				deleteFriend(phoneBook);
				break;
			case 3:
				showPhoneBook(phoneBook);
				break;
			case 0:
				printf("\nGood Bye!");
				break;
		}
	}while(operation!=0);
	free(phoneBook);
}

void addFriend(f* phoneBook){
	phoneBook = (f*)realloc(phoneBook,((counter)+1)*sizeof(f));
	printf("\nEnter Friend's first name:\t");
    scanf("%s",phoneBook[counter].firstName);
    printf("\nEnter Friend's last name:\t");
    scanf("%s",phoneBook[counter].lastName);
    printf("\nEnter Friend's phone number:\t");
    scanf("%s",phoneBook[counter].phoneNumber);
   	counter++;
   	printf("\n\tContact Added");
}

void deleteFriend(f* phoneBook){
	char deleteFirst[50];
	char deleteLast[50];
	printf("Enter the first name of the person to be deleted:\t");
    scanf("%s",deleteFirst);
    printf("Enter the last name of the person to be deleted:\t");
    scanf("%s",deleteLast);
    int i;
    int x;
    for(i=0; i<counter; i++){
    	if(strcmp(phoneBook[i].firstName,deleteFirst)==0){
    		if(strcmp(phoneBook[i].lastName,deleteLast)==0){
    			for(x=i;x<counter;x++){
    				strcpy(phoneBook[x].firstName,phoneBook[x+1].firstName);
					strcpy(phoneBook[x].lastName,phoneBook[x+1].lastName);
					strcpy(phoneBook[x].phoneNumber,phoneBook[x+1].phoneNumber);
    			}
    			counter--;
    			printf("\n\tContact Deleted");
    		}
    	}
    }
}

void showPhoneBook(f* phoneBook){
	int i;
	printf("\nPhone Book");
	for(i=0; i<counter; i++){
		printf("\n%s %s %s",phoneBook[i].firstName,phoneBook[i].lastName,phoneBook[i].phoneNumber);
	}
}

//Lab 8: Advanced Phone Book
//Zachary Shumate
//10-21-1014
//Section 1

#include<stdio.h>

typedef struct friend{
	char firstName[50];
	char lastName[50];
	char phoneNumber[50];
}f;

void addFriend(f*, int*);
void deleteFriend(f*, int*);
void showPhoneBook(f*, int);
void sort(f*, int);
void find(f*, int);
void random(f*, int);
void deletAll(f*, int*);
void save(f*, int);
void load(f*, int*);

main(){
	int operation;
	int counter = 0;
	f *phoneBook = (f*)malloc(sizeof(f));
	
	do{
		printf("\n\nPhone Book Application\n");
		printf("(1) Add Friend\n");
		printf("(2) Delete Friend\n");
		printf("(3) Open Phone Book\n");
		printf("(4) Sort Phone Book\n");
		printf("(5) Search Contact\n");
		printf("(6) Random Contact\n");
		printf("(7) Delete All Contacts\n");
		printf("(8) Save Contacts\n");
		printf("(9) Load Contacts\n");
		printf("(0) Exit\n");
	
		printf("\nWhat do you want to do? ");
		scanf("%d",&operation);
	
		switch(operation){
			case 1:
				addFriend(phoneBook, &counter);
				break;
			case 2:
				deleteFriend(phoneBook, &counter);
				break;
			case 3:
				showPhoneBook(phoneBook, counter);
				break;
			case 4:
				sort(phoneBook, counter);
				break;
			case 5:
				find(phoneBook, counter);
				break;
			case 6:
				random(phoneBook, counter);
				break;
			case 7:
				deleteAll(phoneBook, &counter);
				break;
			case 8:
				save(phoneBook, counter);
				break;
			case 9:
				load(phoneBook, &counter);
				break;
			case 0:
				printf("\nGood Bye!");
				free(phoneBook);
				break;
		}
	}while(operation!=0);
}

void addFriend(f* phoneBook, int *counter){
	phoneBook = (f*)realloc(phoneBook,(*counter+1)*sizeof(f));
	printf("\nEnter Friend's first name:\t");
    scanf("%s",phoneBook[*counter].firstName);
    printf("\nEnter Friend's last name:\t");
    scanf("%s",phoneBook[*counter].lastName);
    printf("\nEnter Friend's phone number:\t");
    scanf("%s",phoneBook[*counter].phoneNumber);
   	(*counter)++;
   	printf("\n\tContact Added");
}

void deleteFriend(f* phoneBook, int* counter){
	char deleteFirst[50];
	char deleteLast[50];
	printf("Enter the first name of the person to be deleted:\t");
    scanf("%s",deleteFirst);
    printf("Enter the last name of the person to be deleted:\t");
    scanf("%s",deleteLast);
    int i;
    int x;
    for(i=0; i<*counter; i++){
    	if(strcmp(phoneBook[i].firstName,deleteFirst)==0){
    		if(strcmp(phoneBook[i].lastName,deleteLast)==0){
    			for(x=i;x<*counter;x++){
    				strcpy(phoneBook[x].firstName,phoneBook[x+1].firstName);
					strcpy(phoneBook[x].lastName,phoneBook[x+1].lastName);
					strcpy(phoneBook[x].phoneNumber,phoneBook[x+1].phoneNumber);
    			}
    			(*counter)--;
    			phoneBook = (f*)realloc(phoneBook,((*counter)*sizeof(f)));
    			printf("\n\tContact Deleted");
    		}
    	}
    }
}

void showPhoneBook(f* phoneBook, int counter){
	int i;
	printf("\nPhone Book");
	if(counter>0){
		for(i=0; i<counter; i++){
			printf("\n%s\t%s\t%s",phoneBook[i].firstName,phoneBook[i].lastName,phoneBook[i].phoneNumber);
		}
	}
	else{
		printf("\nNo records");
	}
}

void sort(f* phoneBook, int counter){
	int i, j;
	int swap=1;
	f temp;
	
	while((0<counter-1)&&(swap==1)){
		swap=0;
		i=0;
		for(j=0; j<counter; j++){
			for(i=0; i<counter-1; i++){
				if((strcmp(phoneBook[i+1].lastName, phoneBook[i].lastName))<0){
					strcpy(temp.firstName, phoneBook[i].firstName);
					strcpy(temp.lastName, phoneBook[i].lastName);
					strcpy(temp.phoneNumber, phoneBook[i].phoneNumber);
					strcpy(phoneBook[i].firstName, phoneBook[i+1].firstName);
					strcpy(phoneBook[i].lastName, phoneBook[i+1].lastName);
					strcpy(phoneBook[i].phoneNumber, phoneBook[i+1].phoneNumber);
					strcpy(phoneBook[i+1].firstName, temp.firstName);
					strcpy(phoneBook[i+1].lastName, temp.lastName);
					strcpy(phoneBook[i+1].phoneNumber, temp.phoneNumber);
					swap=1;
				}
			}
		}
	}
}

void find(f* phoneBook, int counter){
	int x;
    int found = 0;
    char findFN[50];
    char findLN[50];
    
    printf("Enter the first name of the contact you would like to find.\t");
    scanf("%s", &findFN);
    printf("Enter the last name of the contact you would like to find.\t");
    scanf("%s", &findLN);
    
	if(counter > 0){  
		for(x=0; x<=counter; x++){
			if (strcmp(findFN, phoneBook[x].firstName) == 0 && strcmp(findLN, phoneBook[x].lastName)==0){
				found = 1;
				printf("%s\t%s\t%s\n", phoneBook[x].firstName, phoneBook[x].lastName, phoneBook[x].phoneNumber);
			}       
		}
		if (found != 1){
			printf("Contact not found.\n");
		}
	}
	else{
		printf("Phonebook is empty.\n");
	}
}

void random(f* phoneBook, int counter){
	srand(time(NULL)); 
    if(counter>0){
    	int randomContact = rand()%counter;
		printf("%s\t%s\t%s\n", phoneBook[randomContact].firstName, phoneBook[randomContact].lastName, phoneBook[randomContact].phoneNumber);
	}
	else{
		printf("Phonebook is empty.\n");
	}
}

void deleteAll(f* phoneBook, int* counter){
	char nullEntry[5] = "NULL";
	int x;
	for(x=0; x<*counter; x++){
        strcpy(phoneBook[x].firstName, nullEntry);
        strcpy(phoneBook[x].lastName, nullEntry);
        strcpy(phoneBook[x].phoneNumber, nullEntry);
    }
	(*counter)=0;
	phoneBook = (f*)realloc(phoneBook,(sizeof(f)));
	printf("\n\tContacts Deleted");
}

void save(f* phoneBook, int counter){
	FILE* write;
	char file[50];
	int i;
	
	printf("Name the file for your contacts (end with .dat): ");
	scanf("%s",&file);
	write = fopen(file,"w");
	
	if(write==NULL){
		printf("File cannot be opened");
	}
	else{
		for(i=0;i<counter;i++){
			fprintf(write,"%s %s %s\n",phoneBook[i].firstName,phoneBook[i].lastName,phoneBook[i].phoneNumber);
		}
		printf("\tFile Saved");
	}
	fclose(write);
}

void load(f* phoneBook, int* counter){
	FILE* read;
	char file[50];
	
	printf("Name the file you want to open (end with .dat): ");
	scanf("%s",file);
	read = fopen(file,"r");
	
	if(read==NULL){
		printf("File cannot be opened");
	}
	else{
		while(!feof(read)){
			phoneBook = (f*)realloc(phoneBook,(*counter+1)*sizeof(f));
			fscanf(read,"%s %s %s\n", phoneBook[*counter].firstName, phoneBook[*counter].lastName, phoneBook[*counter].phoneNumber);
			(*counter)=(*counter)+1;
		}
		printf("\tFile Opened\n");
		fclose(read);
	}
}

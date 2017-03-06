#include<iostream>
#include<cctype>
#include<vector>
using namespace std;

int main(){
	vector<int> digits;
	vector<char> operations;
	int choice, digit, a;
	char oper;
	bool done = false;
	do{
		cout<<"Press 1 to enter a digit, 2 to enter an operation (+, -, *, or / only), or 3 to end."<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter the digit."<<endl;
				cin>>digit;
				digits.push_back(digit);
				break;
			case 2:
				cout<<"Enter the operation."<<endl;
				cin>>oper;
				operations.push_back(oper);
				 
				if(oper == '+' && digits.size() >= 2){
					a = digits.size();
					digits.push_back(digits.at(a-1) + digits.at(a-2));
					digits.erase(digits.begin() + a-1);
					digits.erase(digits.begin() + a-2);
				} 
				else if(oper == '+'){
					cout<<"Not enough digits yet."<<endl;
				}
				if(oper == '-'){
					a = digits.size();
					digits.push_back(digits.at(a-1) - digits.at(a-2));
					digits.erase(digits.begin() + a-1);
					digits.erase(digits.begin() + a-2);
				}
				else if(oper == '-'){
					cout<<"Not enough digits yet."<<endl;
				}
				if(oper == '*'){
					a = digits.size();
					digits.push_back(digits.at(a-1) * digits.at(a-2));
					digits.erase(digits.begin() + a-1);
					digits.erase(digits.begin() + a-2);
				}
				else if(oper == '-'){
					cout<<"Not enough digits yet."<<endl;
				}
				if(oper == '/'){
					a = digits.size();
					digits.push_back(digits.at(a-1) - digits.at(a-2));
					digits.erase(digits.begin() + a-1);
					digits.erase(digits.begin() + a-2);
				}
				else if(oper == '/'){
					cout<<"Not enough digits yet."<<endl;
				}
				 
				break;
			case 3:
				done = true;
				break;
		}
		 
	}while(done == false);
	 
	
	for(int i = 0; i < digits.size(); i++){
		cout<<"The result is: " <<digits.at(i)<<endl;
	}
}

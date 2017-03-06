//Lab 9: Tic-Tac-Toe
//Zachary Shumate
//10-28-1014
//Section 1

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class gameBoard{
	char location[9]={'1','2','3','4','5','6','7','8','9'};
	public:
		char getLocation(int);
		bool checkMove(int);
		void makeMove(int, char);
		int checkWin();
};

char gameBoard::getLocation(int x){
	return location[x];
}

bool gameBoard::checkMove(int x){
	if(x<0||x>9){
		cout << "Error: Invalid move. Please only select a number between 1 and 9." << endl;
		return true;
	}
	return false;
}

void gameBoard::makeMove(int x, char s){
	location[x]=s;
}

int gameBoard::checkWin(){
	if (getLocation(0) == getLocation(1) && getLocation(1) == getLocation(2)){
		return 1;
	}
	else if (getLocation(3) == getLocation(4) && getLocation(4) == getLocation(5)){
		return 1;
	}
	else if (getLocation(6) == getLocation(7) && getLocation(7) == getLocation(8)){
		return 1;
	}
	else if (getLocation(0) == getLocation(3) && getLocation(3) == getLocation(6)){
		return 1;
	}
	else if (getLocation(1) == getLocation(4) && getLocation(4) == getLocation(7)){
		return 1;
	}
	else if (getLocation(2) == getLocation(5) && getLocation(5) == getLocation(8)){
		return 1;
	}
	else if (getLocation(0) == getLocation(4) && getLocation(4) == getLocation(8)){
		return 1;
	}
	else if (getLocation(2) == getLocation(4) && getLocation(4) == getLocation(6)){
		return 1;
	}
	else if (getLocation(0) != '1' &&  getLocation(1) != '2'  &&  getLocation(2) != '3' && getLocation(3) != '4' && getLocation(4) != '5' && getLocation(5) != '6' && getLocation(6) != '7' && getLocation(7) != '8' && getLocation(8) != '9' ){
		cout << "Game over: Tie!\n";
		return -1;
	}
	else{
		return 0;
	}
}

main(){
	gameBoard board;
	char mark;
	int move;
	srand(time(NULL));
	int player = rand()%2;
	bool tie = false;
	bool retry;
	
	do{
		system("CLS");
		cout << "You are (x), the CPU is (O). \n\n";
		cout << " \t \t \t  |   | \n";
		cout << " \t \t \t" << board.getLocation(0) <<" | " << board.getLocation(1) << " | "<< board.getLocation(2) << "\t \n";
		cout << " \t \t \t  |   | \n";
		cout << "\t\t      -------------\t \n";
		cout << " \t \t \t  |   | \n";
		cout << " \t \t \t" << board.getLocation(3) <<" | " << board.getLocation(4) << " | "<< board.getLocation(5) << "\t \n";
		cout << " \t \t \t  |   | \n";
		cout << "\t\t      -------------\t \n";
		cout << " \t \t \t  |   | \n";
		cout << " \t \t \t" << board.getLocation(6) <<" | " << board.getLocation(7) << " | "<< board.getLocation(8) << "\t \n";
		cout << " \t \t \t  |   | \n\n";
		
		do{
			retry = false;
			if (player%2 == 0){
				mark = 'X';
				do{
					cout << "Enter the number of the space you wish to take: ";
					cin >> move;
				}while(board.checkMove(move));
				move--;
			}
			else{
		        cout << "CPU made its move\n";
				mark = 'O';
				move = rand()%10;
			}
		
			if ( move == 0 && board.getLocation(0) == '1'){
				board.makeMove(0,mark);
			}
			else if (move == 1 && board.getLocation(1) == '2'){
				board.makeMove(1,mark);
			}
			else if (move == 2 && board.getLocation(2) == '3'){
				board.makeMove(2,mark);
			}
			else if ( move == 3 && board.getLocation(3) == '4'){
				board.makeMove(3,mark);
			}
			else if (move == 4 && board.getLocation(4) == '5'){
				board.makeMove(4,mark);
			}
			else if (move == 5 && board.getLocation(5) == '6'){
				board.makeMove(5,mark);
			}
			else if (move == 6 && board.getLocation(6) && '7'){	
				board.makeMove(6,mark);
			}
			else if (move == 7 && board.getLocation(7) == '8'){
				board.makeMove(7,mark);
			}
			else if (move == 8 && board.getLocation(8) == '9'){
				board.makeMove(8,mark);
			}
			else{
				retry = true;
				cout << "Error: Invalid move.\n";
			}
		}while(retry);
		
		if (player%2 == 0){
			player = 1;
		}
		else{
			player = 0;
		}
	}while(board.checkWin()==0);
	if(board.checkWin()==1){
		if (player%2 == 0){
			cout << "\nCPU Wins!!!\n";
		}
		else{
			cout << "\nYou Win!!!\n";
		}
	}
}

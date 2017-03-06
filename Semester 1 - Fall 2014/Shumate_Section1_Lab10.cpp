//Lab 10: Tic-Tac-Toe
//Zachary Shumate
//11-4-1014
//Section 1

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

class gameBoard{
	string location[27]={"1 ","2 ","3 ","4 ","5 ","6 ","7 ","8 ","9 ","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27"};
	int scorePlayer = 0;
	int scoreCPU = 0;
	public:
		void increaseScore(int);
		int getScore(int);
		string getLocation(int);
		bool checkMove(int);
		void makeMove(int, string);
		bool checkWin();
};

void gameBoard::increaseScore(int player){
	if (player == 1){
		scorePlayer++;
	}
	else{
		scoreCPU++;
	}
}

int gameBoard::getScore(int player){
	if (player == 1){
		return scorePlayer;
	}
	else{
		return scoreCPU;
	}
}

string gameBoard::getLocation(int x){
	return location[x];
}

bool gameBoard::checkMove(int x){
	if(x<1||x>27){
		cout << "Error: Invalid move. Please only select a number between 1 and 27." << endl;
		return true;
	}
	return false;
}

void gameBoard::makeMove(int x, string s){
	location[x]=s;
}

bool gameBoard::checkWin(){
	if (getLocation(0) != "1 " &&  getLocation(1) != "2 "  &&  getLocation(2) != "3 " && getLocation(3) != "4 " && getLocation(4) != "5 " && getLocation(5) != "6 " && getLocation(6) != "7 " && getLocation(7) != "8 " && getLocation(8) != "9 " &&  getLocation(9) != "10" &&  getLocation(10) != "11" &&  getLocation(11) != "12" &&  getLocation(12) != "13" &&  getLocation(13) != "14" &&  getLocation(14) != "15" &&  getLocation(15) != "16" &&  getLocation(16) != "17" &&  getLocation(17) != "18" &&  getLocation(18) != "19" &&  getLocation(19) != "20" &&  getLocation(20) != "21" &&  getLocation(21) != "22" &&  getLocation(22) != "23" &&  getLocation(23) != "24" &&  getLocation(24) != "25" &&  getLocation(25) != "26" &&  getLocation(26) != "27"){
		return false;
	}
	else{
		return true;
	}
}
	gameBoard board;
	string mark;
	int move;

main(){
	srand(time(NULL));
	int player = rand()%2;
	bool tie = false;
	bool retry;
	
	do{
		cout << "You are (x), the CPU is (O). \n\n";
		system("CLS");
		cout << " \t \t   |    | \n";
		cout << " \t \t" << board.getLocation(0) <<" | " << board.getLocation(1) << " | "<< board.getLocation(2) << "\t \n";
		cout << " \t \t   |    | \n";
		cout << "\t       -------------\t \n";
		cout << " \t \t   |    | \n";
		cout << " \t \t" << board.getLocation(3) <<" | " << board.getLocation(4) << " | "<< board.getLocation(5) << "\t \n";
		cout << " \t \t   |    | \n";
		cout << "\t       -------------\t \n";
		cout << " \t \t   |    | \n";
		cout << " \t \t" << board.getLocation(6) <<" | " << board.getLocation(7) << " | "<< board.getLocation(8) << "\t \n";
		cout << " \t \t   |    | \n\n";
		
		cout << " \t \t \t   |    | \n";
		cout << " \t \t \t" << board.getLocation(9) <<" | " << board.getLocation(10) << " | "<< board.getLocation(11) << "\t \n";
		cout << " \t \t \t   |    | \n";
		cout << "\t\t       -------------\t \n";
		cout << " \t \t \t   |    | \n";
		cout << " \t \t \t" << board.getLocation(12) <<" | " << board.getLocation(13) << " | "<< board.getLocation(14) << "\t \n";
		cout << " \t \t \t   |    | \n";
		cout << "\t\t       -------------\t \n";
		cout << " \t \t \t   |    | \n";
		cout << " \t \t \t" << board.getLocation(15) <<" | " << board.getLocation(16) << " | "<< board.getLocation(17) << "\t \n";
		cout << " \t \t \t   |    | \n\n";
		
		cout << " \t \t \t \t   |    | \n";
		cout << " \t \t \t \t" << board.getLocation(18) <<" | " << board.getLocation(19) << " | "<< board.getLocation(20) << "\t \n";
		cout << " \t \t \t \t   |    | \n";
		cout << "\t\t\t       -------------\t \n";
		cout << " \t \t \t \t   |    | \n";
		cout << " \t \t \t \t" << board.getLocation(21) <<" | " << board.getLocation(22) << " | "<< board.getLocation(23) << "\t \n";
		cout << " \t \t \t \t   |    | \n";
		cout << "\t\t\t       -------------\t \n";
		cout << " \t \t \t \t   |    | \n";
		cout << " \t \t \t \t" << board.getLocation(24) <<" | " << board.getLocation(25) << " | "<< board.getLocation(26) << "\t \n";
		cout << " \t \t \t \t   |    | \n\n";
		
		do{
			retry = false;
			if (player%2 == 0){
				mark = "X ";
				do{
					cout << "Enter the number of the space you wish to take: ";
					cin >> move;
				}while(board.checkMove(move));
				move--;
			}
			else{
		        cout << "CPU made its move\n";
				mark = "O ";
				move = rand()%27;
			}
		
			if ( move == 0 && board.getLocation(0) == "1 "){
				board.makeMove(0,mark);
			}
			else if (move == 1 && board.getLocation(1) == "2 "){
				board.makeMove(1,mark);
			}
			else if (move == 2 && board.getLocation(2) == "3 "){
				board.makeMove(2,mark);
			}
			else if ( move == 3 && board.getLocation(3) == "4 "){
				board.makeMove(3,mark);
			}
			else if (move == 4 && board.getLocation(4) == "5 "){
				board.makeMove(4,mark);
			}
			else if (move == 5 && board.getLocation(5) == "6 "){
				board.makeMove(5,mark);
			}
			else if (move == 6 && board.getLocation(6) == "7 "){	
				board.makeMove(6,mark);
			}
			else if (move == 7 && board.getLocation(7) == "8 "){
				board.makeMove(7,mark);
			}
			else if (move == 8 && board.getLocation(8) == "9 "){
				board.makeMove(8,mark);
			}
			else if (move == 9 && board.getLocation(9) == "10"){
				board.makeMove(9,mark);
			}
			else if ( move == 10 && board.getLocation(10) == "11"){
				board.makeMove(10,mark);
			}
			else if (move == 11 && board.getLocation(11) == "12"){
				board.makeMove(11,mark);
			}
			else if (move == 12 && board.getLocation(12) == "13"){
				board.makeMove(12,mark);
			}
			else if ( move == 13 && board.getLocation(13) == "14"){
				board.makeMove(13,mark);
			}
			else if (move == 14 && board.getLocation(14) == "15"){
				board.makeMove(14,mark);
			}
			else if (move == 15 && board.getLocation(15) == "16"){
				board.makeMove(15,mark);
			}
			else if (move == 16 && board.getLocation(16) == "17"){	
				board.makeMove(16,mark);
			}
			else if (move == 17 && board.getLocation(17) == "18"){
				board.makeMove(17,mark);
			}
			else if (move == 18 && board.getLocation(18) == "19"){
				board.makeMove(18,mark);
			}
			else if (move == 19 && board.getLocation(19) == "20"){	
				board.makeMove(19,mark);
			}
			else if ( move == 20 && board.getLocation(20) == "21"){
				board.makeMove(20,mark);
			}
			else if (move == 21 && board.getLocation(21) == "22"){
				board.makeMove(21,mark);
			}
			else if (move == 22 && board.getLocation(22) == "23"){
				board.makeMove(22,mark);
			}
			else if ( move == 23 && board.getLocation(23) == "24"){
				board.makeMove(23,mark);
			}
			else if (move == 24 && board.getLocation(24) == "25"){
				board.makeMove(24,mark);
			}
			else if (move == 25 && board.getLocation(25) == "26"){
				board.makeMove(25,mark);
			}
			else if (move == 26 && board.getLocation(26) == "27"){	
				board.makeMove(26,mark);
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
	}while(board.checkWin());
	
	system("CLS");
	cout << "You are (x), the CPU is (O). \n\n";
	cout << " \t \t   |    | \n";
	cout << " \t \t" << board.getLocation(0) <<" | " << board.getLocation(1) << " | "<< board.getLocation(2) << "\t \n";
	cout << " \t \t   |    | \n";
	cout << "\t       -------------\t \n";
	cout << " \t \t   |    | \n";
	cout << " \t \t" << board.getLocation(3) <<" | " << board.getLocation(4) << " | "<< board.getLocation(5) << "\t \n";
	cout << " \t \t   |    | \n";
	cout << "\t       -------------\t \n";
	cout << " \t \t   |    | \n";
	cout << " \t \t" << board.getLocation(6) <<" | " << board.getLocation(7) << " | "<< board.getLocation(8) << "\t \n";
	cout << " \t \t   |    | \n\n";
	
	cout << " \t \t \t   |    | \n";
	cout << " \t \t \t" << board.getLocation(9) <<" | " << board.getLocation(10) << " | "<< board.getLocation(11) << "\t \n";
	cout << " \t \t \t   |    | \n";
	cout << "\t\t       -------------\t \n";
	cout << " \t \t \t   |    | \n";
	cout << " \t \t \t" << board.getLocation(12) <<" | " << board.getLocation(13) << " | "<< board.getLocation(14) << "\t \n";
	cout << " \t \t \t   |    | \n";
	cout << "\t\t       -------------\t \n";
	cout << " \t \t \t   |    | \n";
	cout << " \t \t \t" << board.getLocation(15) <<" | " << board.getLocation(16) << " | "<< board.getLocation(17) << "\t \n";
	cout << " \t \t \t   |    | \n\n";
	
	cout << " \t \t \t \t   |    | \n";
	cout << " \t \t \t \t" << board.getLocation(18) <<" | " << board.getLocation(19) << " | "<< board.getLocation(20) << "\t \n";
	cout << " \t \t \t \t   |    | \n";
	cout << "\t\t\t       -------------\t \n";
	cout << " \t \t \t \t   |    | \n";
	cout << " \t \t \t \t" << board.getLocation(21) <<" | " << board.getLocation(22) << " | "<< board.getLocation(23) << "\t \n";
	cout << " \t \t \t \t   |    | \n";
	cout << "\t\t\t       -------------\t \n";
	cout << " \t \t \t \t   |    | \n";
	cout << " \t \t \t \t" << board.getLocation(24) <<" | " << board.getLocation(25) << " | "<< board.getLocation(26) << "\t \n";
	cout << " \t \t \t \t   |    | \n\n";

	if (board.getLocation(0) == board.getLocation(1) && board.getLocation(1) == board.getLocation(2)){
		if(board.getLocation(0) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(3) == board.getLocation(4) && board.getLocation(4) == board.getLocation(5)){
		if(board.getLocation(3) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(6) == board.getLocation(7) && board.getLocation(7) == board.getLocation(8)){
		if(board.getLocation(6) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(0) == board.getLocation(3) && board.getLocation(3) == board.getLocation(6)){
		if(board.getLocation(0) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(1) == board.getLocation(4) && board.getLocation(4) == board.getLocation(7)){
		if(board.getLocation(1) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(2) == board.getLocation(5) && board.getLocation(5) == board.getLocation(8)){
		if(board.getLocation(2) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(0) == board.getLocation(4) && board.getLocation(4) == board.getLocation(8)){
		if(board.getLocation(0) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(2) == board.getLocation(4) && board.getLocation(4) == board.getLocation(6)){
		if(board.getLocation(2) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	
	
	if (board.getLocation(9) == board.getLocation(10) && board.getLocation(10) == board.getLocation(11)){
		if(board.getLocation(9) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(12) == board.getLocation(13) && board.getLocation(13) == board.getLocation(14)){
		if(board.getLocation(12) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(15) == board.getLocation(16) && board.getLocation(16) == board.getLocation(17)){
		if(board.getLocation(15) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(9) == board.getLocation(12) && board.getLocation(12) == board.getLocation(15)){
		if(board.getLocation(9) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(10) == board.getLocation(13) && board.getLocation(13) == board.getLocation(16)){
		if(board.getLocation(10) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(11) == board.getLocation(14) && board.getLocation(14) == board.getLocation(17)){
		if(board.getLocation(11) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(9) == board.getLocation(13) && board.getLocation(13) == board.getLocation(17)){
		if(board.getLocation(9) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(11) == board.getLocation(13) && board.getLocation(13) == board.getLocation(15)){
		if(board.getLocation(11) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	
	if (board.getLocation(18) == board.getLocation(19) && board.getLocation(19) == board.getLocation(20)){
		if(board.getLocation(18) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(21) == board.getLocation(22) && board.getLocation(22) == board.getLocation(23)){
		if(board.getLocation(21) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(24) == board.getLocation(25) && board.getLocation(25) == board.getLocation(26)){
		if(board.getLocation(24) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(18) == board.getLocation(21) && board.getLocation(21) == board.getLocation(24)){
		if(board.getLocation(18) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(19) == board.getLocation(22) && board.getLocation(22) == board.getLocation(25)){
		if(board.getLocation(19) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(20) == board.getLocation(23) && board.getLocation(23) == board.getLocation(26)){
		if(board.getLocation(20) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(18) == board.getLocation(22) && board.getLocation(22) == board.getLocation(26)){
		if(board.getLocation(18) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(20) == board.getLocation(22) && board.getLocation(22) == board.getLocation(24)){
		if(board.getLocation(20) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	
	if (board.getLocation(0) == board.getLocation(9) && board.getLocation(9) == board.getLocation(18)){
		if(board.getLocation(0) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(1) == board.getLocation(10) && board.getLocation(10) == board.getLocation(19)){
		if(board.getLocation(1) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(2) == board.getLocation(11) && board.getLocation(11) == board.getLocation(20)){
		if(board.getLocation(20) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(3) == board.getLocation(12) && board.getLocation(12) == board.getLocation(21)){
		if(board.getLocation(3) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(4) == board.getLocation(13) && board.getLocation(13) == board.getLocation(22)){
		if(board.getLocation(4) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(5) == board.getLocation(14) && board.getLocation(14) == board.getLocation(23)){
		if(board.getLocation(5) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(6) == board.getLocation(15) && board.getLocation(15) == board.getLocation(24)){
		if(board.getLocation(6) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(7) == board.getLocation(16) && board.getLocation(16) == board.getLocation(25)){
		if(board.getLocation(7) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}
	if (board.getLocation(8) == board.getLocation(17) && board.getLocation(17) == board.getLocation(26)){
		if(board.getLocation(8) == "X "){
			board.increaseScore(1);
		}
		else{
			board.increaseScore(0);
		}
	}

	if (board.getScore(1)<board.getScore(0)){
		cout << "\nCPU Wins!!!\n";
	}
	else if (board.getScore(1)>board.getScore(0)){
		cout << "\nYou Win!!!\n";
	}
	else{
		cout << "\nIt is a Tie!!!\n";
	}
	cout << "Player Score: " << board.getScore(1) << endl;
	cout << "CPU Score: " << board.getScore(0);
}

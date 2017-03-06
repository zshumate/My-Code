//Lab 10: Better Tic-Tac-Toe
//Julia Grady
//Section 1
//November 4th, 2014


#include <conio.h>
#include <iostream>
#include <time.h>
#include <string>
#include <cstdlib>


using namespace std;

class boardGame{

string places[28] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27"};
int scorePlayer = 0;
int scoreOther = 0;
public:
	string getLocation (int);
	void makeMove(int, string);
	void upCore(int);
	bool gameContinue();
	bool checkMove(int, string places);
	int getThing(int);
};
int boardGame::getThing(int doThing){
	if (doThing = 1){
		return scorePlayer;
	}
	else{ return scoreOther; }
}
void boardGame::upCore (int charels){
	if (charels = 1){
		scorePlayer++;
	}
	else{ scoreOther++; }
}
string boardGame::getLocation(int x){
	return places[x];
}

void boardGame::makeMove(int x, string s){
	places[x]=s;
}

bool boardGame::checkMove (int move, string places)
{
	if (move < 1 || move > 27)
    {                     		// error checking for input being different than expected

    	cout << "Error: This move is not Valid. Please only select a number between 1 and 27." << endl;
    	move = rand()%27;
    	
    }

    return true;
} 

bool boardGame::gameContinue ()     // return true; game is continuing
{
	if
	(  places[1] != "1" &&  places[2] != "2"  &&  places[3] != "3" && places[4] != "4" && places[5] != "5" 
    && places[6] != "6" && places[7] != "7" && places[8] != "8" && places[9] != "9" && places[10]!="10" && places[11]!="11" && places[12]!="12" 
	&& places[13]!="13" && places[14]!="14" && places[15]!="15" && places[16]!="16" && places[17]!="17" && places[18]!="18" && places[19]!="19" 
	&&  places[20] != "20" &&  places[21] != "21" &&  places[22] != "22" &&  places[23] != "23" &&  places[24] != "24" &&  places[25] != "25" &&  places[26] != "26" 
	&&  places[27] != "27")
	{
		cout << "Game over: Tie!\n";
		cout << "Print any character to exit.";
		getch();
		return false;
	}
	else
	{
		return true;
	}

}

int main() {
	
	boardGame stringels;
	int f = 0;
	int player;
	string mark;
	int move;

	srand(time(NULL));	//  who goes first
	player = rand()%2;
do 				// do while gameContinue == false
{
	cout << "Welcome to tic-tac-toe. \n\n";
	cout << "You are x, the CPU is O \n";

	cout << " \t \t \t  |   | \n";
	cout << " \t \t \t" << stringels.getLocation(1) <<" | " << stringels.getLocation(2) << " | "<< stringels.getLocation(3) << "\t \n";
	cout << " \t \t \t  |   | \n";
	cout << "\t\t      ____________\t \n";
	cout << " \t \t \t  |   | \n";
	cout << " \t \t \t" << stringels.getLocation(4) <<" | " << stringels.getLocation(5) << " | "<< stringels.getLocation(6) << "\t \n";		//gameboard
	cout << " \t \t \t  |   | \n";
	cout << "\t\t      ____________\t \n";
	cout << " \t \t \t  |   | \n";
	cout << " \t \t \t" << stringels.getLocation(7) <<" | " << stringels.getLocation(8) << " | "<< stringels.getLocation(9) << "\t \n";
	cout << " \t \t \t  |   | \n\n\n";

	cout << " \t \t \t   |    | \n";
	cout << " \t \t \t" << stringels.getLocation(10) <<" | " << stringels.getLocation(11) << " | "<< stringels.getLocation(12) << "\t \n";
	cout << " \t \t \t   |    | \n";
	cout << "\t\t       ____________\t \n";
	cout << " \t \t \t   |    | \n";
	cout << " \t \t \t" << stringels.getLocation(13) <<" | " << stringels.getLocation(14) << " | "<< stringels.getLocation(15) << "\t \n";		//gameboard
	cout << " \t \t \t   |    | \n";
	cout << "\t\t       ____________\t \n";
	cout << " \t \t \t   |    | \n";
	cout << " \t \t \t" << stringels.getLocation(16) <<" | " << stringels.getLocation(17) << " | "<< stringels.getLocation(18) << "\t \n";
	cout << " \t \t \t   |    | \n\n\n";

	cout << " \t \t \t   |    | \n";
	cout << " \t \t \t" << stringels.getLocation(19) <<" | " << stringels.getLocation(20) << " | "<< stringels.getLocation(21) << "\t \n";
	cout << " \t \t \t   |    | \n";
	cout << "\t\t       ____________\t \n";
	cout << " \t \t \t   |    | \n";
	cout << " \t \t \t" << stringels.getLocation(22) <<" | " << stringels.getLocation(23) << " | "<< stringels.getLocation(24) << "\t \n";		//gameboard
	cout << " \t \t \t   |    | \n";
	
	cout << "\t\t       ____________\t \n";
	cout << " \t \t \t   |    | \n";
	cout << " \t \t \t" << stringels.getLocation(25) <<" | " << stringels.getLocation(26) << " | "<< stringels.getLocation(27) << "\t \n";
	cout << " \t \t \t   |    | \n\n";

	if (player%2 == 0)	// if player is even
	{
		mark = "X ";
		cout << "Player's turn. \n";
		cout << "Player, enter the number of the space you wish to take.";
		cin >> move;
	}
	else
	{	// if player is odd
		
         cout << "CPU went first. Press any key to continue.\n";
              
              
		mark = "O ";			// CPU's turn, randomly picks number between 1-9, have decided to not wait for getch() when CPU takes their turn
		move = rand()%28;
		if (move < 1 )
		{
         move = move + 1;
                 }
		
	}

// checks if user input and places on board is empty
	if ( move == 1 && stringels.getLocation(1) == "1"  && (stringels.checkMove(move, stringels.getLocation(1)) == true) )
	{                              
		stringels.makeMove(1,mark);
		
	}
	else if (move == 2 && stringels.getLocation(2) == "2" && (stringels.checkMove(move, stringels.getLocation(2)) == true))
	{
		stringels.makeMove(2,mark);
			
	}
	else if (move == 3 && stringels.getLocation(3) == "3" && (stringels.checkMove(move, stringels.getLocation(3)) == true))
	{
		stringels.makeMove(3,mark);
		
	}
	else if ( move == 4 && stringels.getLocation(4) == "4" && (stringels.checkMove(move, stringels.getLocation(4)) == true))
	{
		stringels.makeMove(4,mark);
		
	}
	else if (move == 5 && stringels.getLocation(5) == "5" && (stringels.checkMove(move, stringels.getLocation(5)) == true))
	{
		stringels.makeMove(5,mark);
		
	}
	else if (move == 6 && stringels.getLocation(6) == "6" && (stringels.checkMove(move, stringels.getLocation(6)) == true))
	{
		stringels.makeMove(6,mark);
	}
	else if (move == 7 && stringels.getLocation(7) == "7" && (stringels.checkMove(move, stringels.getLocation(7)) == true))
	{	
		stringels.makeMove(7,mark);
	}
	else if (move == 8 && stringels.getLocation(8) == "8" && (stringels.checkMove(move, stringels.getLocation(8)) == true))
	{
		stringels.makeMove(8,mark); 
	}
	else if (move == 9 && stringels.getLocation(9) == "9" && (stringels.checkMove(move, stringels.getLocation(9)) == true))
	{
		stringels.makeMove(9,mark);
		
	}
	else if ( move == 10 && stringels.getLocation(10) == "10"  && (stringels.checkMove(move, stringels.getLocation(10)) == true) )
	{                              
		stringels.makeMove(10,mark);
	
	}
	else if ( move == 11 && stringels.getLocation(11) == "11"  && (stringels.checkMove(move, stringels.getLocation(11)) == true) )
	{                              
		stringels.makeMove(11,mark);
		
	}
	else if (move == 12 && stringels.getLocation(12) == "12" && (stringels.checkMove(move, stringels.getLocation(12)) == true))
	{
		stringels.makeMove(12,mark);
	}
	else if (move == 13 && stringels.getLocation(13) == "13" && (stringels.checkMove(move, stringels.getLocation(13)) == true))
	{
		stringels.makeMove(13,mark);
	}
	else if ( move == 14 && stringels.getLocation(14) == "14" && (stringels.checkMove(move, stringels.getLocation(14)) == true))
	{
		stringels.makeMove(14,mark);
	}
	else if (move == 15 && stringels.getLocation(15) == "15" && (stringels.checkMove(move, stringels.getLocation(15)) == true))
	{
		stringels.makeMove(15,mark);
	}
	else if (move == 16 && stringels.getLocation(16) == "16" && (stringels.checkMove(move, stringels.getLocation(16)) == true))
	{
		stringels.makeMove(16,mark);
	}
	else if (move == 17 && stringels.getLocation(17) == "17" && (stringels.checkMove(move, stringels.getLocation(17)) == true))
	{	
		stringels.makeMove(17,mark);
	}
	else if (move == 18 && stringels.getLocation(18) == "18" && (stringels.checkMove(move, stringels.getLocation(18)) == true))
	{
		stringels.makeMove(18,mark);
	}
	else if (move == 19 && stringels.getLocation(19) == "19" && (stringels.checkMove(move, stringels.getLocation(19)) == true))
	{
		stringels.makeMove(19,mark);
	}
	else if ( move == 20 && stringels.getLocation(20) == "20"  && (stringels.checkMove(move, stringels.getLocation(20)) == true) )
	{                              
		stringels.makeMove(20,mark);
	}
	else if ( move == 21 && stringels.getLocation(21) == "21"  && (stringels.checkMove(move, stringels.getLocation(21)) == true) )
	{                              
		stringels.makeMove(21,mark);
	}
	else if (move == 22 && stringels.getLocation(22) == "22" && (stringels.checkMove(move, stringels.getLocation(22)) == true))
	{
		stringels.makeMove(22,mark);
	}
	else if (move == 23 && stringels.getLocation(23) == "23" && (stringels.checkMove(move, stringels.getLocation(23)) == true))
	{
		stringels.makeMove(23,mark);
	}
	else if ( move == 24 && stringels.getLocation(24) == "24" && (stringels.checkMove(move, stringels.getLocation(24)) == true))
	{
		stringels.makeMove(24,mark);
	}
	else if (move == 25 && stringels.getLocation(25) == "25" && (stringels.checkMove(move, stringels.getLocation(25)) == true))
	{
		stringels.makeMove(25,mark);
	}
	else if (move == 26 && stringels.getLocation(26) == "26" && (stringels.checkMove(move, stringels.getLocation(26)) == true))
	{
		stringels.makeMove(26,mark);
	}
	else if (move == 27 && stringels.getLocation(27) == "27" && (stringels.checkMove(move, stringels.getLocation(27)) == true))
	{	
		stringels.makeMove(27,mark);
	}
	
	else if (player%2 == 0)
	{
		cout << "Error: Invalid move.\n";
		cout << "Enter any key to continue.\n";
		getch();
		player--;
	}
	else {       // else if cpu triggered an invalid move
         player--;
         }
         
	player++;
	system("CLS");
	
} while (stringels.gameContinue());	// gameContinue evaluating to true means game is not over, and loop continues

	if (stringels.getLocation(1) == stringels.getLocation(2) && stringels.getLocation(2) == stringels.getLocation(3))
	{
		if (stringels.getLocation(1)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(4) == stringels.getLocation(5) && stringels.getLocation(5) == stringels.getLocation(6))
	{
		if (stringels.getLocation(4)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(7) == stringels.getLocation(8) && stringels.getLocation(8) == stringels.getLocation(9))
	{
		if (stringels.getLocation(7)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(1) == stringels.getLocation(4) && stringels.getLocation(4) == stringels.getLocation(7))
	{
		if (stringels.getLocation(1)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(2) == stringels.getLocation(5) && stringels.getLocation(5) == stringels.getLocation(8))
	{
		if (stringels.getLocation(2)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(3) == stringels.getLocation(6) && stringels.getLocation(6) == stringels.getLocation(9))
	{
		if (stringels.getLocation(3)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(1) == stringels.getLocation(5) && stringels.getLocation(5) == stringels.getLocation(9))
	{
		if (stringels.getLocation(1)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(3) == stringels.getLocation(5) && stringels.getLocation(5) == stringels.getLocation(7))
	{
		if (stringels.getLocation(3)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(10) == stringels.getLocation(11) && stringels.getLocation(11) == stringels.getLocation(12))
	{
		if (stringels.getLocation(10)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(13) == stringels.getLocation(14) && stringels.getLocation(14) == stringels.getLocation(15))
	{
		if (stringels.getLocation(13)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(16) == stringels.getLocation(17) && stringels.getLocation(17) == stringels.getLocation(18))
	{
		if (stringels.getLocation(16)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(19) == stringels.getLocation(20) && stringels.getLocation(20) == stringels.getLocation(21))
	{
		if (stringels.getLocation(19)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(22) == stringels.getLocation(23) && stringels.getLocation(23) == stringels.getLocation(24))
	{
		if (stringels.getLocation(22)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(25) == stringels.getLocation(26) && stringels.getLocation(26) == stringels.getLocation(27))
	{
		if (stringels.getLocation(25)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(1) == stringels.getLocation(10) && stringels.getLocation(10) == stringels.getLocation(19))
	{
		if (stringels.getLocation(1)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(2) == stringels.getLocation(11) && stringels.getLocation(11) == stringels.getLocation(20))
	{
		if (stringels.getLocation(2)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(3) == stringels.getLocation(12) && stringels.getLocation(12) == stringels.getLocation(21))
	{
		if (stringels.getLocation(3)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(7) == stringels.getLocation(16) && stringels.getLocation(16) == stringels.getLocation(25))
	{
		if (stringels.getLocation(7)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(8) == stringels.getLocation(17) && stringels.getLocation(17) == stringels.getLocation(26))
	{
		if (stringels.getLocation(8)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(4) == stringels.getLocation(13) && stringels.getLocation(13) == stringels.getLocation(22))
	{
		if (stringels.getLocation(4)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(5) == stringels.getLocation(14) && stringels.getLocation(14) == stringels.getLocation(23))
	{
		if (stringels.getLocation(5)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(6) == stringels.getLocation(15) && stringels.getLocation(15) == stringels.getLocation(24))
	{
		if (stringels.getLocation(6)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
	if (stringels.getLocation(9) == stringels.getLocation(18) && stringels.getLocation(18) == stringels.getLocation(27))
	{
		if (stringels.getLocation(9)=="X "){
			stringels.upCore(1);
		}
		else{
			stringels.upCore(0);
		}
	}
 	
 	if (stringels.getThing(1)<stringels.getThing(0)){
 		cout <<"\nCOM Wins";
 	}
 	else if (stringels.getThing(1)>stringels.getThing(0)){
 		cout <<"\n You Win.";
 	}
 	else{
 		cout<<"\nTie.";
 	}
 	cout<<"\nPlayer score:"<<stringels.getThing(1);
 	cout<<"\nCOM Score:"<< stringels.getThing(0);
}




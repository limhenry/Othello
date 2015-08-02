/**********|**********|**********|
Program: main.cpp
Course: Bachelor of Computing Science (Hons) 
Year: 2015/16 Trimester 1
Name: LIM H*** R***
ID: 1********8
Email: henry@limhenry.me / ***************@gmail.com
Phone: ***-*******

Note: Some personal info are not showing due to personal privacy.
**********|**********|**********/

#include <iostream>
#include <string>
#include <sstream> 
#include <fstream>
#include <cstdlib>

void menu();
void display_board();
void player_turn();
bool check_game();

char board[8][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
char turn;	
//The amazing main menu
int main(){
	system("CLS");
	menu();
	return 0;
}

void menu(){
	turn = 'X';
	char select_menu;
	std::cout<<"#######################################\n";
	std::cout<<"|              OTHELLO!               |\n";
	std::cout<<"|                 BY                  |\n";
	std::cout<<"|            LIM H*** R***            |\n";
	std::cout<<"#######################################\n\n";
	std::cout<<"Welcome to Othello\n\nType a number to select an option\n\n1. New game \n2. Help \n3. Quit\n\n""Selection: ";
	std::cin>>select_menu;

	if (select_menu == '1'){
		system("CLS");
		std::cin.ignore();
		while (!check_game())
		{
			display_board();
			player_turn();
			check_game();
		}
	}
	else if(select_menu == '2'){
		//reading the help from help.txt
		system("CLS");
		std::string help_text;
		std::ifstream help ("help.txt");
		if (help.is_open())
		{
			while ( getline (help,help_text) )
			{
				std::cout << help_text << '\n';
			}
			help.close();
		}
		system("pause");
		main();
	}
	else if(select_menu == '3'){
		exit(0);
	}
	else{
		system("CLS");
		std::cout << "You have choose a incorrect value. Try Again. \n\n";
		menu();
	}
}


//showing the gameboard with multi-dimensional array
void display_board(){
	board[3][3] = 'X';
	board[3][4] = 'O';
	board[4][3] = 'O';
	board[4][4] = 'X';

	for (int row = 0; row <= 7; row = row + 1){
		std::cout << "  |---+---+---+---+---+---+---+---|\n" << 8 - row;
		for (int column = 0; column <=7; column = column + 1){
			std::cout << " | " << board[row][column];
		}
		std::cout << " | " << "\n";
	}     
	std::cout << "  |---+---+---+---+---+---+---+---|\n";
	std::cout << "    A   B   C   D   E   F   G   H\n";
	//todo: create and change the score to variable
	std::cout << "Score		: 0 = 2   X = 2\n";
}


void player_turn(){

	char a;
	int b;
	int row, column;

	//check which player is playing
	if (turn == 'X')
	{
		std::cout << "Current Player 	: X\n==> ";
	}
	else if (turn == 'O')
	{
		std::cout << "Current Player 	: O\n==> ";
	}

	//get input from user to do some awesome thing
	std::string choice;	
	std::getline(std::cin, choice);
	std::istringstream var(choice);
	for(int i=0; i< choice.length(); i++) {
		choice[i] = toupper(choice[i]); 
	}
	var >> a >> b;
	if (choice == "MENU"){
		main();
	}
	else if (choice == "NEXT"){
		system("CLS");
		if (turn == 'X'){
			turn = 'O';
		}
		else{
			turn = 'X';
		}
	}
	else{
		//changing the input(row) to ASCII and let magic happens
		a = toupper(a);
		column = (int)a - 65; 
		row = 8 - b;
		if (row >= 0 && row <= 7 && column >= 0 & column <= 7){
			if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
			{		
				board[row][column] = 'X';
				system("CLS");			
			}
			else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
			{
				board[row][column] = 'O';
				system("CLS");
			}    
			else
			{
				std::cout << "The cell you chose is used! Try again\n";
			}
		}
		else{
			std::cout<<"Invalid Value, Try Again. \n";
			player_turn();
		}
	}
}

//todo: this is for checking whether to game is over or not
bool check_game(){
	return false;
}

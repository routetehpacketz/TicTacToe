#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prototype functions
char game(char play);
void reset_board(char in[][3]);
void print_board(char in[][3]);
char take_input();
int update_board(char board[][3], char position, char player, int repeat);
char check_win(char board[][3], int p, char win);

void main(void) {
	//Create variable to restart game after win
	char play = 'T';
	do {
		play = game(play);
	} while (play == 'T'); {
		printf("Thanks for playing!\n");
	}
}

char game(char play) {
	//Create board and populate it with position numbers
	char board[3][3] = {};
	reset_board(board);
	//Check if game is won
	char win = 'F';
	//Array of player values to iterate for gameplay and populate board positions
	char players[2] = {'X','O'};
	//Begin do..while based on win variable
	do {
		//Repeat prompt for target position if position selected is invalid
		int repeat = 1;
		//Begin iterating players
		for (int i = 0; i < 2; i++) {
			char player = players[i];
			//Begin do..while based on repeat
			do {
				print_board(board);
				printf("It's player %c's turn!\n", players[i]);
				char position = take_input();
				repeat = update_board(board, position, player, repeat);
			} while (repeat == 1); {}
			//Check if current player has run
			win = check_win(board, player, win);
			//If game is won, announce winner and end player iteration so next player is not prompted
			if (win == 'T') {
				print_board(board);
				printf("Player %c has won!\n", player);
				break;
			}
		}
	}
	//If game is one, prompt to play again
	while (win == 'F'); {
		printf("Enter Y to play again: ");
		scanf_s(" %c", &play);
		if (play != 'Y') {
			play = 'F';
			return play;
		}
		else {
			printf("Let's keep playing!\n");
			play = 'T';
			return play;
		}
	}
}

//Populates the 2d array by
//iterating over a single nested for loop
//three times that increments ASCII 0 on
//each iteration
void reset_board(char in[][3]) {
	int v = 48;
	for (int ct = 0; ct <= 2; ++ct) {
		for (int ct2 = 0; ct2 <= 2; ++ct2) {
			in[ct][ct2] = v += 1;
		}
	}
}

//Prints 3x3 2d array with 3x3 appearance by printing
//a newline after each iteration of the X coordinate
void print_board(char board[][3]) {
	for (int ct = 0; ct <= 2; ++ct) {
		for (int ct2 = 0; ct2 <= 2; ++ct2) {
			printf("%c", board[ct][ct2]);
		}
		printf("\n");
	}
}

//Prompts user for input and returns char
char take_input(void) {
	char position;
	printf("Please enter a number position on the board: ");
	scanf_s(" %c", &position);
	return position;
}

//Determine target board position based on entered ASCII value of player's input
//If target position matches a player value, repeat prompt
int update_board(char board[][3], char position, char player, int repeat) {
	if (position == 49 && board[0][0] != 88 && board[0][0] != 79) {
		board[0][0] = player;
		repeat = 0;
		return repeat;
	}
	else if (position == 50 && board[0][1] != 88 && board[0][1] != 79) {
		board[0][1] = player;
		repeat = 0;
		return repeat;
	}
	else if (position == 51 && board[0][2] != 88 && board[0][2] != 79) {
		board[0][2] = player;
		repeat = 0;
		return repeat;
	}
	else if (position == 52 && board[1][0] != 88 && board[1][0] != 79) {
		board[1][0] = player;
		repeat = 0;
		return repeat;
	}
	else if (position == 53 && board[1][1] != 88 && board[1][1] != 79) {
		board[1][1] = player;
		repeat = 0;
		return repeat;
	}
	else if (position == 54 && board[1][2] != 88 && board[1][2] != 79) {
		board[1][2] = player;
		repeat = 0;
		return repeat;
	}
	else if (position == 55 && board[2][0] != 88 && board[2][0] != 79) {
		board[2][0] = player;
		repeat = 0;
		return repeat;
	}
	else if (position == 56 && board[2][1] != 88 && board[2][1] != 79) {
		board[2][1] = player;
		repeat = 0;
		return repeat;
	}
	else if (position == 57 && board[2][2] != 88 && board[2][2] != 79) {
		board[2][2] = player;
		repeat = 0;
		return repeat;
	}
	else {
		printf("That position is taken or doesn't exist!\n");
		repeat = 1;
		return repeat;
	}
}

//Check if player has won, set win variable to T if so
char check_win(char board[][3], int p, char w) {
	//Check vertical win
	if (board[0][0] == p && board[1][0] == p && board[2][0] == p) {
		w = 'T';
		return w;
	}
	else if (board[0][1] == p && board[1][1] == p && board[2][1] == p) {
		w = 'T';
		return w;
	}
	else if (board[0][2] == p && board[1][2] == p && board[2][2] == p) {
		w = 'T';
		return w;
	}
	//Check horizontal win
	else if (board[0][0] == p && board[0][1] == p && board[0][2] == p) {
		w = 'T';
		return w;
	}
	else if (board[1][0] == p && board[1][1] == p && board[1][2] == p) {
		w = 'T';
		return w;
	}
	else if (board[2][0] == p && board[2][1] == p && board[2][2] == p) {
		w = 'T';
		return w;
	}
	//Check diagonal win
	else if (board[0][0] == p && board[1][1] == p && board[2][2] == p) {
		w = 'T';
		return w;
	}
	else if (board[0][2] == p && board[1][1] == p && board[2][0] == p) {
		w = 'T';
		return w;
	}
	//Else keep win 0 to keep playing
	else {
		w = 'F';
		return w;
	}
}
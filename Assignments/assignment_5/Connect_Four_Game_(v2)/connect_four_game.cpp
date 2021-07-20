/*************************************************************************
 * ** Program: connect_four_game.cpp
 * ** Author: Pranav Prabhu
 * ** Date: 03/13/2021
 * ** Description: This program is written to play the game of Connect 4
 * ** Input: user desired number of rows and columns
 * ** Output: player who wins the game or a tie
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

// this is Struct data structure which stores players names and their ID (which is Xs and Os assigned during runtime to both players)
struct playerInfo {
	char playerName[100];
	char playerID;
};

int drop_piece(char** board, playerInfo activePlayer, int cols);
void check_board(char** board, int rows, playerInfo activePlayer, int dropChoice);
void print_board(char** board, int row, int col);
int horizontal_check(char** board, playerInfo activePlayer, int rows, int columns);
int vertical_check(char** board, playerInfo activePlayer, int rows, int cols);
int diagonal_check1(char** board, playerInfo activePlayer, int rows, int cols);
int diagonal_check2(char** board, playerInfo activePlayer, int rows, int cols);
int full_board(char** board, int cols);
void player_win(playerInfo activePlayer);
int restart(char** board, int rows, int cols);

/***************************************************************************************************************
 * ** Function: get_int()
 * ** Description: takes a prompt from the user as a string literal and checks if the inputs is a valid integer
 * ** Parameters: string prompt
 * ** Pre-conditions: takes a string prompt
 * ** Post-conditions: returns the provided integer
 **************************************************************************************************************/
int get_int(string prompt) {
  int num = 0;
  for (int i = 0; i < prompt.length(); i++) {
    if (prompt[i] > 47 && prompt[i] <= 57) {
      num = num * 10 + (int(prompt[i] - 48));            // num = 0 * 10 + (integer value of character - 48)) to return num
    } else {
      return -1;                // if non-integer values are detected, return -1
    }
  }
  return num;
}

/*******************************************************************************************
 * ** Function: create_arr()
 * ** Description: creates a 2D array which is the board for the game with rows and columns
 * ** Parameters: int rows, int cols
 * ** Pre-conditions: takes two integers namely rows and cols
 * ** Post-conditions: creates a 2D array which is basically the board for the game
 *******************************************************************************************/
char **create_arr(int rows, int cols) {
  char **arr = new char*[rows];        // dynamic allocation of memory of arr for rows
  for(int i = 0; i < rows; ++i) {
    arr[i] = new char[cols];            // dynamic allocation of memory of arr for columns
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      arr[i][j] = ' ';                    // set the initial condition of the board to empty
    }
  }
  return arr;
}

/***********************************************************************************************************
 * ** Function: validate_args()
 * ** Description: validates the number of arguments passed when calling the executable file during runtime
 * ** Parameters: int argc
 * ** Pre-conditions: takes an integer argc
 * ** Post-conditions: returns true or false to verify if the number of arguments is 3 or not
 ***********************************************************************************************************/
bool validate_args(int argc) {
  if (argc == 3) {
    return true;                  // return true if user entered correct number of arguments, else print error message
  } else if (argc > 3) {
    cout << "You entered too many arguments.\n";
  } else {
    cout << "You entered too few arguments.\n";
  }
  return false;
}

// my main() function is longer than 15 lines because I couldn't break this anymore because they are tied and related to each other
int main(int argc, const char *argv[]) {
  playerInfo playerOne, playerTwo;
  int rows, columns;
  
  if (validate_args(argc)) {                    // error-handling for invalid arguments when calling the executable file
    string rowStr(argv[1]);
    string colStr(argv[2]);
    rows = atoi(argv[1]);
    columns = atoi(argv[2]);
    while (rows > 20 || rows < 4/* || to_string(atoi(rowStr.c_str())) != rowStr*/) {
      cout << "Invalid rows! Please enter a number between 4 and 20: ";
      //cin.clear();
      //cin.ignore();
      cin >> rowStr;
      rows = atoi(rowStr.c_str());
    }
    while (columns < 4 || columns > 20/* || to_string(atoi(colStr.c_str())) != colStr*/) {
      cout << "Invalid columns! Please enter a number between 4 and 20: ";
      //cin.clear();
      //cin.ignore(123, '\n');
      cin >> colStr;
      columns = atoi(colStr.c_str());
    }
  } else {
    do {
      cout << "Enter a row length: ";
      cin >> rows;
    } while (rows < 4 || rows > 20);
    do {
      cout << "Enter a column length: ";
      cin >> columns;
    } while (columns < 4 || columns > 20);
  }
  
	char** board = create_arr(rows, columns);                  // create our board
	int dropChoice, horizontal_win, vertical_win,  diagonal_win, diagonal_win2, full, again;
  
  cout << "\nWelcome to the Game of Connect 4!!!" << endl << endl;
	cout << "Player One, please enter your name: ";
	cin >> playerOne.playerName;
	playerOne.playerID = 'X';
	cout << "Player Two, please enter your name: ";
	cin >> playerTwo.playerName;
	playerTwo.playerID = 'O';
  cout << "\n";
  
  print_board(board, rows, columns);
	do {                                    // this code block below if for player 1
		dropChoice = drop_piece(board, playerOne, columns);
		check_board(board, rows, playerOne, dropChoice);
    print_board(board, rows, columns);
    horizontal_win = horizontal_check(board, playerOne, rows, columns);
    vertical_win = vertical_check(board, playerOne, rows, columns);
    diagonal_win = diagonal_check1(board, playerOne, rows, columns);
    diagonal_win2 = diagonal_check2(board, playerOne, rows, columns);
    
		if (horizontal_win == 4 || vertical_win == 4 || diagonal_win == 4 || diagonal_win2 == 4) {        // check for any 1 of the 4 wins for player 1
			player_win(playerOne);
			again = restart(board, rows, columns);
      if (again == 1) continue;
      else break;
		}
                                            // this code block below if for player 2
		dropChoice = drop_piece(board, playerTwo, columns);
		check_board(board, rows, playerTwo, dropChoice);
    print_board(board, rows, columns);
    horizontal_win = horizontal_check(board, playerTwo, rows, columns);
    vertical_win = vertical_check(board, playerTwo,rows, columns);
    diagonal_win = diagonal_check1(board, playerTwo, rows, columns);
    diagonal_win2 = diagonal_check2(board, playerTwo, rows, columns);
    
		if(horizontal_win == 4 || vertical_win == 4 || diagonal_win == 4 || diagonal_win2 == 4) {        // check for any 1 of the 4 wins for player 2
			player_win(playerTwo);
			again = restart(board, rows, columns);
      if (again == 1) continue;
      else break;
		}
  
		full = full_board(board, columns);
		if (full == 0) {
			cout << "The board is full, it is a draw!" << endl;
			again = restart(board, rows, columns);
		}
	} while(again != 2);

  for (int i = 0; i < rows; i++) {            // free the memory - delete the board after usage
    delete [] board[i];
  }
  delete [] board;

  return 0;
}

/*************************************************************************************
 * ** Function: drop_piece()
 * ** Description: drops a particular piece (Xs and Os) in the board
 * ** Parameters: char** board, playerInfo activePlayer, int cols
 * ** Pre-conditions: takes board, the current player, and total columns in the board
 * ** Post-conditions: returns the drop choice column number entered by the user
 *************************************************************************************/
 // this function had to be more that 15 lines as I had to validate user input and repeat the process of dropping the piece in the board
int drop_piece(char** board, playerInfo activePlayer, int cols) {
  string get_num;
	int piece, dropChoice;

	do {
		cout << endl << activePlayer.playerName << "'s turn! ";
		cout << "Please enter a number: ";
   
    while (true) {
      cin >> get_num;
      piece = get_int(get_num);                // call the get_int() function which checks if user entered a valid number for the column
      if (piece == -1) {
        cout << "Invalid input! Enter whole numbers only: ";
        cin.clear();
        cin.ignore(256, '\n');
      } else {
        cin.clear();
        cin.ignore(256, '\n');
        break;
      }
    }
    dropChoice = piece;

		while (board[0][dropChoice-1] == 'X' || board[0][dropChoice-1] == 'O') {    // if the top-most part of the board (top column is full), print error message
			cout << "That row is full, please enter a new row: ";
			cin  >> dropChoice;
		}
	} while(dropChoice < 1 || dropChoice > cols);      // repeat the process whenever the user enters a number out of bounds

  return dropChoice;
}

/*******************************************************************************************
 * ** Function: check_board()
 * ** Description: checks if particular dropped location is not an X or an O
 * ** Parameters: char** board, int rows, playerInfo activePlayer, int dropChoice
 * ** Pre-conditions: takes board, the current player, and column drop choice
 * ** Post-conditions: repeats the process of continously checking the board for valid input
 *******************************************************************************************/
void check_board(char** board, int rows, playerInfo activePlayer, int dropChoice) {
  int rowIndex = rows - 1;
	int turn = 0;
  
	do {
		if (board[rowIndex][dropChoice-1] != 'X' && board[rowIndex][dropChoice-1] != 'O') {
			board[rowIndex][dropChoice-1] = activePlayer.playerID;
			turn = 1;
		}
		else --rowIndex;
	} while (turn != 1);
}

/*******************************************************************************************
 * ** Function: print_board()
 * ** Description: prints the board with correct number of rows and columns specified by user
 * ** Parameters: char** board, int row, int col
 * ** Pre-conditions: takes board, row, and column
 * ** Post-conditions: prints the board with column number at the top
 *******************************************************************************************/
void print_board(char** board, int row, int col) {
	for (int i = 0; i < col; ++i) {
		cout << "   " << i + 1 << " ";              // print column numbers at the top of the board
  }
  
	cout << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i % 2 == 0 && j % 2 == 0)                        // if number of rows and columns are even, print board with colors
				cout << "|\033[30;42m " << board[i][j] << "  ";
        //cout << "|\033[30;47m " << board[i][j] << " " << "|\033[30;0m";
			else if (i % 2 == 1 && j % 2 == 1)                  // if number of rows and columns are odd, print board with colors
				cout << "|\033[30;42m " << board[i][j] << "  ";
        //cout << "|\033[30;47m" << board[i][j] << " " << "|\033[30;0m";
			else                                                // if number of rows and columns are even and odd, print board with different colors
				cout << "|\033[44m " << board[i][j] << "  ";
			cout << "\033[0m";
		}
		cout << endl;
	}
}

/***********************************************************************************
 * ** Function: horizontal_check()
 * ** Description: checks for a horizontal win
 * ** Parameters: char** board, playerInfo activePlayer, int rows, int columns
 * ** Pre-conditions: takes board, current player, rows and columns
 * ** Post-conditions: returns win which checks for a horizontal match in the board
 **********************************************************************************/
int horizontal_check(char** board, playerInfo activePlayer, int rows, int columns) {
	char XO = activePlayer.playerID;
	int win = 0;
    
  for(int i = 0; i < rows; i++) {
    win = 0;  
    for(int j = 0; j < columns; j++) {
      if(board[i][j] == XO) {              // iterate over rows and then columns to find a horizontal match
        win++;      
        if(win == 4) {
          return win;
        }
      } else {
        win = 0;
      }
    }
  }
  
  return win;
}

/***********************************************************************************
 * ** Function: vertical_check()
 * ** Description: checks for a vertical win
 * ** Parameters: char** board, playerInfo activePlayer, int rows, int columns
 * ** Pre-conditions: takes board, current player, rows and columns
 * ** Post-conditions: returns win which checks for a vertical match in the board
 **********************************************************************************/
int vertical_check(char** board, playerInfo activePlayer, int rows, int cols) {
  char XO = activePlayer.playerID;
  int win = 0;

  for(int j = 0; j < cols; j++) {
    win = 0;
    for(int i = 0; i < rows; i++) {
      if(board[i][j] == XO) {                  // iterate over columns and then rows to find a vertical match
        win++;
        if(win == 4) {
          return win;
        }
      } else {
        win = 0;
      }
    }
  }
  
  return win;
}

/***********************************************************************************
 * ** Function: diagonal_check1()
 * ** Description: checks for a diagonal win
 * ** Parameters: char** board, playerInfo activePlayer, int rows, int cols
 * ** Pre-conditions: takes board, current player, rows and columns
 * ** Post-conditions: returns win which checks for a diagonal match in the board
 **********************************************************************************/
int diagonal_check1(char** board, playerInfo activePlayer, int rows, int cols) {
  char XO = activePlayer.playerID;
  int win = 0;
  for (int i = 0; i < rows-3; i++) {
    win = 0;
    for (int j = 0; j < cols-3; j++) {        // loop over total rows - 3 and toal cols - 3 to find exact 4 diagonal matches
      if (board[i+0][j+0] == XO && board[i+1][j+1] == XO && board[i+2][j+2] == XO && board[i+3][j+3] == XO) {
        win = 4;                            // checks from bottom left to top right of the board
        return win;
      } else win = 0;
    }
  }
  
  return win;
}

/***********************************************************************************
 * ** Function: diagonal_check2()
 * ** Description: checks for a diagonal win
 * ** Parameters: char** board, playerInfo activePlayer, int rows, int cols
 * ** Pre-conditions: takes board, current player, rows and columns
 * ** Post-conditions: returns win which checks for a diagonal match in the board
 **********************************************************************************/
int diagonal_check2(char** board, playerInfo activePlayer, int rows, int cols) {
  char XO = activePlayer.playerID;
  int win;
  for (int i = 3; i < rows; i++) {
    for (int j = 0; j < cols-3; j++) {            // loop over total rows from i = 3 and toal cols - 3 to find exact 4 diagonal matches
      if (board[i][j] == XO && board[i-1][j+1] == XO && board[i-2][j+2] == XO && board[i-3][j+3] == XO) {
        win = 4;                                  // checks from top left to bottom right of the board
        return win;
      } else win = 0;
    }
  }
  
  return win;
}

/********************************************************************
 * ** Function: full_board()
 * ** Description: checks of board is full or not
 * ** Parameters: char** board, int cols
 * ** Pre-conditions: takes board and columns
 * ** Post-conditions: returns full which places pieces in the board
 *******************************************************************/
int full_board(char** board, int cols) {
	int full = 0;
	for (int i = 1; i <= cols; ++i) {
		if (board[0][i] != 'X' || board[0][i] != 'O') {        // as long as the top column in a row is not full, increment full
      ++full;
		}
	}
 
  return full;
}

/************************************************
 * ** Function: player_win()
 * ** Description: prints the winner of the game
 * ** Parameters: playerInfo activePlayer
 * ** Pre-conditions: takes the current player
 * ** Post-conditions: outputs the winner
 ***********************************************/
void player_win(playerInfo activePlayer) {
	cout << endl << activePlayer.playerName << " Connected Four! Congratulations! You Win!" << endl;
}

/*********************************************************
 * ** Function: restart()
 * ** Description: asks users for a rematch
 * ** Parameters: char** board, int rows, int cols
 * ** Pre-conditions: takes board, rows, and columns
 * ** Post-conditions: returns user's choice for a rematch
 *********************************************************/
int restart (char** board, int rows, int cols) {
	int restart;
  string get_num;
	cout << "\n\n\nWould you like to play a rematch? Yes(1), No(2) ";
	
  while (true) {                        // error-handling which checks if the user entered a valid number for restart
    cin >> get_num;
    restart = get_int(get_num);
    if (restart == -1 || restart < 1 || restart > 2) {
      cout << "Invalid input! Enter whole numbers only: ";
      cin.clear();
      cin.ignore(256, '\n');
    } else {
      cin.clear();
      cin.ignore(256, '\n');
      break;
    }
  }

	if (restart == 1) {
		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				board[i][j] = ' ';                // print the empty board if the user wants a rematch
			}
		}
    print_board(board, rows, cols);
	} else cout << "\n\n\nGoodbye!\n\n\n" << endl;

  return restart;
}
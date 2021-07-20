#include "connect_four_header.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

struct playerInfo;

int get_int(string prompt) {
  int num = 0;
  for (int i = 0; i < prompt.length(); i++) {
    if (prompt[i] > 47 && prompt[i] <= 57) {
      num = num * 10 + (int(prompt[i] - 48));
    } else {
      return -1;
    }
  }
  return num;
}

char **create_arr(int rows, int cols) {
  char **arr = new char*[rows];
  for(int i = 0; i < rows; ++i) {
    arr[i] = new char[cols];
  }
  
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      arr[i][j] = ' ';
    }
  }
  return arr;
}

bool validate_args(int argc) {
  if (argc == 3) {
    return true;
  } else if (argc > 3) {
    cout << "You entered too many arguments.\n";
  } else {
    cout << "You entered too few arguments.\n";
  }
  return false;
}

int drop_piece(char** board, playerInfo activePlayer, int cols) {
  string get_num;
	int piece, dropChoice;

	do {
		cout << endl << endl << activePlayer.playerName << "'s turn! ";
		cout << "Please enter a number: ";
    while (true) {
      cin >> get_num;
      piece = get_int(get_num);
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

		while (board[0][dropChoice-1] == 'X' || board[0][dropChoice-1] == 'O') {
			cout << "That row is full, please enter a new row: ";
			cin  >> dropChoice;
		}
	} while(dropChoice < 1 || dropChoice > cols);

  return dropChoice;
}

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

void print_board(char** board, int row, int col) {
	for (int i = 0; i < col; ++i) {
		cout << "   " << i + 1 << " ";
  }
  /*for (int i = 0; i < col; ++i) {
    if(i < 9) {
      cout << " " << i + 1 << " ";
    } else {
      cout << " " << i + 1;
    }
  }*/
	cout << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i % 2 == 0 && j % 2 == 0)
				cout << "|\033[30;42m " << board[i][j] << "  ";
        //cout << "|\033[30;47m " << board[i][j] << " " << "|\033[30;0m";
			else if (i % 2 == 1 && j % 2 == 1)
				cout << "|\033[30;42m " << board[i][j] << "  ";
        //cout << "|\033[30;47m" << board[i][j] << " " << "|\033[30;0m";
			else
				cout << "|\033[44m " << board[i][j] << "  ";
			cout << "\033[0m";
		}
		cout << endl;
	}
}

int horizontal_check(char** board, playerInfo activePlayer, int rows, int columns) {
	char XO = activePlayer.playerID;
	int win = 0;
    
  for(int i = 0; i < rows; i++) {
    win = 0;  
    for(int j = 0; j < columns; j++) {
      if(board[i][j] == XO) {
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

int vertical_check(char** board, playerInfo activePlayer, int rows, int cols) {
  char XO = activePlayer.playerID;
  int win = 0;

  for(int j = 0; j < cols; j++) {
    win = 0;
    for(int i = 0; i < rows; i++) {
      if(board[i][j] == XO) {
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

int diagonal_check1(char** board, playerInfo activePlayer, int rows, int cols) {
  char XO = activePlayer.playerID;
  int win = 0;
  for (int i = 0; i < rows-3; i++) {
    win = 0;
    for (int j = 0; j < cols-3; j++) {
      if (board[i+0][j+0] == XO && board[i+1][j+1] == XO && board[i+2][j+2] == XO && board[i+3][j+3] == XO) {
        win = 4;
        return win;
      } else win = 0;
    }
  }
  return win;
}

int diagonal_check2(char** board, playerInfo activePlayer, int rows, int cols) {
  char XO = activePlayer.playerID;
  int win;
  for (int i = 3; i < rows; i++){
    for (int j = 0; j < cols-3; j++){
      if (board[i][j] == XO && board[i-1][j+1] == XO && board[i-2][j+2] == XO && board[i-3][j+3] == XO) {
        win = 4;
        return win;
      } else win = 0;
    }
  }
  return win;
}

int full_board(char** board, int cols) {
	int full = 0;
	for (int i = 1; i <= cols; ++i) {
		if (board[0][i] != 'X' || board[0][i] != 'O') {
      ++full;
		}
	}
  return full;
}

void player_win(playerInfo activePlayer) {
	cout << endl << activePlayer.playerName << " Connected Four! Congratulations! You Win!" << endl;
}

int restart (char** board, int rows, int cols) {
	int restart;
  string get_num;
	cout << "\nWould you like to play a rematch? Yes(1), No(2) ";
	
  while (true) {
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
				board[i][j] = ' ';
			}
		}
    print_board(board, rows, cols);
	} else cout << "\nGoodbye!\n\n\n" << endl;

  return restart;
}
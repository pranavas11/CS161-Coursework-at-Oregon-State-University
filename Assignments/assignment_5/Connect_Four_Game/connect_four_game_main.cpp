#include "connect_four_header.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

struct playerInfo;

int main(int argc, const char *argv[]) {
  playerInfo playerOne, playerTwo;
  int rows, columns;
  
  if (validate_args(argc)) {
    string rowStr(argv[1]);
    string colStr(argv[2]);
    rows = atoi(argv[1]);
    columns = atoi(argv[2]);
    while (rows > 20 || rows < 4/* || to_string(atoi(rowStr.c_str())) != rowStr*/) {
      cout << "Invalid rows! Please enter a number between 4 and 20: ";
      cin >> rowStr;
      rows = atoi(rowStr.c_str());
    }
    
    while (columns < 4 || columns > 20/* || to_string(atoi(colStr.c_str())) != colStr*/) {
      cout << "Invalid columns! Please enter a number between 4 and 20: ";
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
  
	char** board = create_arr(rows, columns);
	int dropChoice, horizontal_win, vertical_win,  diagonal_win, diagonal_win2, full, again;
  
  cout << "\nWelcome to the Game of Connect 4!!!" << endl << endl;
	cout << "Player One, please enter your name: ";
	cin >> playerOne.playerName;
	playerOne.playerID = 'X';
	cout << "Player Two, please enter your name: ";
	cin >> playerTwo.playerName;
	playerTwo.playerID = 'O';
  cout << "\n\n\n";
  
  print_board(board, rows, columns);
	do {
		dropChoice = drop_piece(board, playerOne, columns);
		check_board(board, rows, playerOne, dropChoice);
    cout << "\n";
    print_board(board, rows, columns);
    horizontal_win = horizontal_check(board, playerOne, rows, columns);
    vertical_win = vertical_check(board, playerOne, rows, columns);
    diagonal_win = diagonal_check1(board, playerOne, rows, columns);
    diagonal_win2 = diagonal_check2(board, playerOne, rows, columns);
		if (horizontal_win == 4 || vertical_win == 4 || diagonal_win == 4 || diagonal_win2 == 4) {
			player_win(playerOne);
			again = restart(board, rows, columns);
      if (again == 1) continue;
      else break;
		}

		dropChoice = drop_piece(board, playerTwo, columns);
		check_board(board, rows, playerTwo, dropChoice);
    cout << "\n";
    print_board(board, rows, columns);
    horizontal_win = horizontal_check(board, playerTwo, rows, columns);
    vertical_win = vertical_check(board, playerTwo,rows, columns);
    diagonal_win = diagonal_check1(board, playerTwo, rows, columns);
    diagonal_win2 = diagonal_check2(board, playerTwo, rows, columns);
		if(horizontal_win == 4 || vertical_win == 4 || diagonal_win == 4 || diagonal_win2 == 4) {
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

  for (int i = 0; i < rows; i++) {
    delete [] board[i];
  }
  
  delete [] board;

  return 0;
}
#include <cstdlib>
#include <string>
#pragma
using std::string;

struct playerInfo {
	char playerName[100];
	char playerID;
};

int get_int(string prompt);
char **create_arr(int rows, int cols);
bool validate_args(int argc);
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
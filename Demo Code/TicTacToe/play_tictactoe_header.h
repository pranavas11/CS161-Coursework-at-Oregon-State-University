#ifndef PLAY_TICTACTOE_HEADER_H
#define PLAY_TICTACTOE_HEADER_H

#include <string>

struct game_data {
	std::string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
	int player = 1;
	int position = 0;
};

int get_int(std::string prompt);
void introduction();
void set_position();
void update_board();
void change_player();
void take_turn();
bool filled_up();
void draw();
void end_game();
bool is_winner();

#endif
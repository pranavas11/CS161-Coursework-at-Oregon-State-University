#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include "play_tictactoe_header.h"

game_data data;

int get_int(std::string prompt) {
    int num = 0;
    for (unsigned int i = 0; i < prompt.length(); i++) {
        if (prompt[i] > 47 && prompt[i] <= 57) {               // checks if numbers are between 0-9
            num = num * 10 + (int(prompt[i] - 48));              // num = 0 * 10 + (integer value of character - 48)) to return num
        } else {
            return -1;
        }
    }
    return num;
}

void introduction() {
    std::cout << "\n\n\nPress Enter to begin!";
    std::cin.ignore();
    std::cout << "\n";

    std::cout << "===========\n";
    std::cout << "Tic-Tac-Toe\n";
    std::cout << "===========\n\n\n";
  
    std::cout << "Player 1) ✖\n";
    std::cout << "Player 2) ⊙\n\n";

    std::cout << "Here's the 3 x 3 grid:\n\n";
    std::cout << "     |     |      \n";
    std::cout << "  1  |  2  |  3   \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  4  |  5  |  6   \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  7  |  8  |  9   \n";
    std::cout << "     |     |      \n\n";
}

void draw() {
    std::cout << "     |     |      \n";
    std::cout << "  " << data.board[0] << "  |  " << data.board[1] << "  |  " << data.board[2] << "\n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  " << data.board[3] << "  |  " << data.board[4] << "  |  " << data.board[5] << "\n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  " << data.board[6] << "  |  " << data.board[7] << "  |  " << data.board[8] << "\n";
    std::cout << "     |     |      \n";
    std::cout << "\n";
}

void set_position() {
	std::string turn;

    std::cout << "Player " << data.player << "'s Turn (Enter 1-9): ";

	while (true) {
    	std::cin >> turn;
    	data.position = get_int(turn);
    	if (data.position == -1 || data.position < 1 || data.position > 9) {
      	    std::cout << "\nInvalid input! Please enter a valid number to set the position between 1 and 9: ";
      	    std::cin.clear();
      	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    	} else {
      	    std::cin.clear();
      	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      	    break;
    	}
  	}
    
    std::cout << "\n";
    
    while (data.board[data.position-1] != " ") {
        std::cout << "Oops, there's already a piece in that position!\n\n";
        std::cout << "Player " << data.player << "'s Turn (Enter 1-9): ";
        std::cin >> data.position;
        std::cout << "\n";
    }
}

void update_board() {
    if (data.player % 2 == 1) {
        data.board[data.position-1] = "✖";
    } else {
        data.board[data.position-1] = "⊙";
    }
}

void change_player() {
    if (data.player == 1) {
        data.player++;
    } else {
        data.player--;
    }
}

bool is_winner() {
    bool winner = false;
    
    // rows
    if ((data.board[0] == data.board[1]) && (data.board[1] == data.board[2]) && data.board[0] != " " && data.player == 1) {
        winner = true;
	} else if ((data.board[0] == data.board[1]) && (data.board[1] == data.board[2]) && data.board[0] != " " && data.player == 2) {
		winner = true;
    } else if ((data.board[3] == data.board[4]) && (data.board[3] == data.board[5]) && data.board[3] != " " && data.player == 1) {
        winner = true;
	} else if ((data.board[3] == data.board[4]) && (data.board[3] == data.board[5]) && data.board[3] != " " && data.player == 2) {
		winner = true;
    } else if ((data.board[6] == data.board[7]) && (data.board[6] == data.board[8]) && data.board[6] != " " && data.player == 1) {
        winner = true;
    } else if ((data.board[6] == data.board[7]) && (data.board[6] == data.board[8]) && data.board[6] != " " && data.player == 2) {
		winner = true;
	}
    
    // columns
    else if ((data.board[0] == data.board[3]) && (data.board[0] == data.board[6]) && data.board[0] != " " && data.player == 1) {
        winner = true;
	} else if ((data.board[0] == data.board[3]) && (data.board[0] == data.board[6]) && data.board[0] != " " && data.player == 2) {
		winner = true;
    } else if ((data.board[1] == data.board[4]) && (data.board[1] == data.board[7]) && data.board[1] != " " && data.player == 1) {
        winner = true;
	} else if ((data.board[1] == data.board[4]) && (data.board[1] == data.board[7]) && data.board[1] != " " && data.player == 2) {
		winner = true;
    } else if ((data.board[2] == data.board[5]) && (data.board[2] == data.board[8]) && data.board[2] != " " && data.player == 1) {
        winner = true;
    } else if ((data.board[2] == data.board[5]) && (data.board[2] == data.board[8]) && data.board[2] != " " && data.player == 2) {
		winner = true;
	}
    
    // diagonals
    else if ((data.board[0] == data.board[4]) && (data.board[0] == data.board[8]) && data.board[0] != " " && data.player == 1) {
        winner = true;
	} else if ((data.board[0] == data.board[4]) && (data.board[0] == data.board[8]) && data.board[0] != " " && data.player == 2) {
		winner = true;
    } else if ((data.board[2] == data.board[4]) && (data.board[2] == data.board[6]) && data.board[2] != " " && data.player == 1) {
        winner = true;
    } else if ((data.board[2] == data.board[4]) && (data.board[2] == data.board[6]) && data.board[2] != " " && data.player == 2) {
		winner = true;
	}
		
    return winner;
}

bool filled_up() {
    bool filled = true;
    for (int i = 0; i < 9; i++) {
        if (data.board[i] == " ") {
            filled = false;
        }
    }
    return filled;
}

void take_turn() {
    while (!is_winner() && !filled_up()) {
        set_position();
        update_board();
		if (!is_winner()) change_player();
        draw();
    }
}

void end_game() {
    if (is_winner() && data.player == 1) {
		std::cout << "\n\n\nCongratulations!!! Player 1 is the winner! Please play again!\n\n\n";
    } else if (is_winner() && data.player == 1) {
		std::cout << "\n\n\nCongratulations!!! Player 2 is the winner! Please play again!\n\n\n";
	} else if (filled_up()) {
        std::cout << "\n\n\nGame Over!!!\n\n\nThere's a tie! Please play again!\n\n\n";
    }
}
/*************************************************************************************************************
 * ** Program: twenty_one.cpp
 * ** Author: Pranav Prabhu
 * ** Date: 06/17/21
 * ** Description: This program is written to play the game of TwentyOne
 * ** Input: a player's bet against the dealer and if the player wants to keep adding number to running total
 * ** Output: outputs if player won/lost the bet or whether game was a tie
 ************************************************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

/***************************************************************************************************************
 * ** Function: get_int()
 * ** Description: takes a prompt from the user as a string literal and checks if the inputs is a valid integer
 * ** Parameters: string prompt
 * ** Pre-conditions: takes a string prompt
 * ** Post-conditions: returns the provided integer
 **************************************************************************************************************/
int get_int(string prompt) {
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

/**************************************************************
 * ** Function: game_players()
 * ** Description: asks user for numer of players for the game
 * ** Parameters: none
 * ** Pre-conditions: retrieves input for number of players
 * ** Post-conditions: returns number of players for the game
 *************************************************************/
int game_players() {
	string num_players;
	int num_of_players;

  cout << "\n\n\nHow many players do you want? ";
	while (true) {
    cin >> num_players;
    num_of_players = get_int(num_players);
    if (num_of_players == -1 || num_of_players < 1 || num_of_players > 4) {
      cout << "\nInvalid input! Please enter a valid number for the number of players you want between 1 and 4: ";
      cin.clear();
      cin.ignore(256, '\n');
    } else {
      cin.clear();
      cin.ignore(256, '\n');
      break;
    }
  }

	return num_of_players;
}

/**********************************************************************
 * ** Function: player_one_money()
 * ** Description: asks user for starting amount of money for player 1
 * ** Parameters: none
 * ** Pre-conditions: retrieves input for amount
 * ** Post-conditions: returns amount entered by player 1
 *********************************************************************/
int player_one_money() {
	string player_money;
	int money;

	cout << "\nPlayer 1, how much money are you starting with? ";
	while (true) {
    cin >> player_money;
    money = get_int(player_money);
    if (money == -1 || money < 1) {
      cout << "\nInvalid input! Please enter a valid amount: ";
      cin.clear();
      cin.ignore(256, '\n');
    } else {
      cin.clear();
      cin.ignore(256, '\n');
      break;
    }
  }
	
	return money;
}

/**********************************************************************
 * ** Function: player_two_money()
 * ** Description: asks user for starting amount of money for player 2
 * ** Parameters: none
 * ** Pre-conditions: retrieves input for amount
 * ** Post-conditions: returns amount entered by player 2
 *********************************************************************/
int player_two_money() {
	string player_money;
	int money;

	cout << "\n\n\nPlayer 2, how much money are you starting with? ";
	while (true) {
    cin >> player_money;
    money = get_int(player_money);
    if (money == -1 || money < 1) {
      cout << "\nInvalid input! Please enter a valid amount: ";
      cin.clear();
      cin.ignore(256, '\n');
    } else {
      cin.clear();
      cin.ignore(256, '\n');
      break;
    }
  }
	
	return money;
}

/**********************************************************************
 * ** Function: player_three_money()
 * ** Description: asks user for starting amount of money for player 3
 * ** Parameters: none
 * ** Pre-conditions: retrieves input for amount
 * ** Post-conditions: returns amount entered by player 3
 *********************************************************************/
int player_three_money() {
	string player_money;
	int money;

	cout << "\n\n\nPlayer 3, how much money are you starting with? ";
	while (true) {
    cin >> player_money;
    money = get_int(player_money);
    if (money == -1 || money < 1) {
      cout << "\nInvalid input! Please enter a valid amount: ";
      cin.clear();
      cin.ignore(256, '\n');
    } else {
      cin.clear();
      cin.ignore(256, '\n');
      break;
    }
  }
	
	return money;
}

/**********************************************************************
 * ** Function: player_four_money()
 * ** Description: asks user for starting amount of money for player 4
 * ** Parameters: none
 * ** Pre-conditions: retrieves input for amount
 * ** Post-conditions: returns amount entered by player 4
 *********************************************************************/
int player_four_money() {
	string player_money;
	int money;

	cout << "\n\n\nPlayer 4, how much money are you starting with? ";
	while (true) {
    cin >> player_money;
    money = get_int(player_money);
    if (money == -1 || money < 1) {
      cout << "\nInvalid input! Please enter a valid amount: ";
      cin.clear();
      cin.ignore(256, '\n');
    } else {
      cin.clear();
      cin.ignore(256, '\n');
      break;
    }
  }
	
	return money;
}

/***************************************************************************
 * ** Function: dealer_game()
 * ** Description: function which plays the game of the dealer
 * ** Parameters: none
 * ** Pre-conditions: generates random numbers and adds it to the total sum
 * ** Post-conditions: outputs if the dealer won or lost the match
 **************************************************************************/
int dealer_game() {
	int rand_num = 0, sum = 0;
	cout << "\n\n\nDealer's turn...";

	while (true) {
		rand_num = (rand() % 11) + 1;
		sum += rand_num;
		cout << "\nThe dealer gets a(n) " << rand_num << ". His running total is " << sum << ".\n";

		if (sum == 21) {
			cout << "\nThe dealer stops...\nThe dealer has 21 points. You lose!\n";
			break;
		}

		if (sum > 21) {
			cout << "\nThe dealer busts! You win!\n";
			break;
		}
	}

	return sum;
}

/**********************************************************************************************************************
 * ** Function: game()
 * ** Description: function which plays the entire game
 * ** Parameters: none
 * ** Pre-conditions: determines number of players and if the player wants to keep adding numbers to the running total
 * ** Post-conditions: outputs who won and lost the match as well as a tie
 *********************************************************************************************************************/
void game() {
	srand(time(NULL));

	int num_of_players = game_players();
	int player_one, player_two, player_three, player_four, bet = 0, rand_num = 0, sum = 0, next_turn, dealer;
	string bet_money, turn;

	if (num_of_players == 1) {
		player_one = player_one_money();
		cout << "\n\n\nPlayer 1's turn...\nPlayer 1 how much do you bet you can beat the dealer? ";
		while (true) {
    	cin >> bet_money;
    	bet = get_int(bet_money);
    	if (bet == -1 || bet < 1 || bet > player_one) {
      	cout << "\nInvalid input! Please enter a valid amount: ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		rand_num = (rand() % 11) + 1;
		sum += rand_num;
		cout << "\nPlayer 1, you got a(n) " << rand_num << ". Your running total is " << sum << ".\nDo you want another number (0-no or 1-yes)? ";
		while (true) {
    	cin >> turn;
    	next_turn = get_int(turn);
    	if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      	cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		while (true) {
			if (next_turn == 1) {
				rand_num = (rand() % 11) + 1;
				sum += rand_num;
				cout << "\nPlayer 1, you got a(n) " << rand_num << ". Your running total is " << sum << ".\n";

				if (sum < 21) {
					cout << "Do you want another number (0-no or 1-yes)? ";
					while (true) {
    				cin >> turn;
    				next_turn = get_int(turn);
    				if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      				cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      				cin.clear();
      				cin.ignore(256, '\n');
    				} else {
      				cin.clear();
      				cin.ignore(256, '\n');
      				break;
    				}
  				}
				} else if (sum == 21) {
					cout << "\nCongrats!!! You got 21 in hand. You win!\n";
					player_one += bet;
					cout << "Player 1 has " << player_one << ".\n";
					break;
				} else {
					cout << "\nYou bust! You lose!\n";
					player_one = 0;
					cout << "Player 1 has " << player_one << ".\n";
					break;
				}
			} else {
				cout << "\nYour total points are " << sum << ".\n";

				dealer = dealer_game();
				if (dealer > 21) {
					player_one += bet;
					cout << "\nPlayer 1 has " << player_one << ".\n";
				}
				if (dealer == 21) {
					player_one = 0;
					cout << "Player 1 has " << player_one << ".\n";
				}
				break;
			}

			if (sum == dealer) {
				cout << "The dealer has " << dealer << " points. Tie game!\nPlayer 1 has " << player_one << ".\n";
			}
		}
	} else if (num_of_players == 2) {
		player_one = player_one_money();
		cout << "\n\n\nPlayer 1's turn...\nPlayer 1 how much do you bet you can beat the dealer? ";
		while (true) {
    	cin >> bet_money;
    	bet = get_int(bet_money);
    	if (bet == -1 || bet < 1 || bet > player_one) {
      	cout << "\nInvalid input! Please enter a valid amount: ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		rand_num = (rand() % 11) + 1;
		sum += rand_num;
		cout << "\nPlayer 1, you got a(n) " << rand_num << ". Your running total is " << sum << ".\nDo you want another number (0-no or 1-yes)? ";
		while (true) {
    	cin >> turn;
    	next_turn = get_int(turn);
    	if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      	cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		while (true) {
			if (next_turn == 1) {
				rand_num = (rand() % 11) + 1;
				sum += rand_num;
				cout << "\nPlayer 1, you got a(n) " << rand_num << ". Your running total is " << sum << ".\n";

				if (sum < 21) {
					cout << "Do you want another number (0-no or 1-yes)? ";
					while (true) {
    				cin >> turn;
    				next_turn = get_int(turn);
    				if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      				cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      				cin.clear();
      				cin.ignore(256, '\n');
    				} else {
      				cin.clear();
      				cin.ignore(256, '\n');
      				break;
    				}
  				}
				} else if (sum == 21) {
					cout << "\nCongrats!!! You got 21 in hand. You win!\n";
					player_one += bet;
					cout << "Player 1 has " << player_one << ".\n";
					break;
				} else {
					cout << "\nYou bust! You lose!\n";
					player_one = 0;
					cout << "Player 1 has " << player_one << ".\n";
					break;
				}
			} else {
				cout << "\nYour total points are " << sum << ".\n";

				dealer = dealer_game();
				if (dealer > 21) {
					player_one += bet;
					cout << "\nPlayer 1 has " << player_one << ".\n";
				}

				if (dealer == 21) {
					player_one = 0;
					cout << "Player 1 has " << player_one << ".\n";
				}
				break;
			}

			if (sum == dealer) {
				cout << "The dealer has " << dealer << " points. Tie game!\nPlayer 1 has " << player_one << ".\n";
			}
		}

		player_two = player_two_money();
		cout << "\nPlayer 2's turn...\nPlayer 2 how much do you bet you can beat the dealer? ";
		while (true) {
    	cin >> bet_money;
    	bet = get_int(bet_money);
    	if (bet == -1 || bet < 1 || bet > player_two) {
      	cout << "\nInvalid input! Please enter a valid amount: ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		rand_num = (rand() % 11) + 1;
		sum = 0;
		sum += rand_num;
		cout << "\nPlayer 2, you got a(n) " << rand_num << ". Your running total is " << sum << ".\nDo you want another number (0-no or 1-yes)? ";
		while (true) {
    	cin >> turn;
    	next_turn = get_int(turn);
    	if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      	cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		while (true) {
			if (next_turn == 1) {
				rand_num = (rand() % 11) + 1;
				sum += rand_num;
				cout << "\nPlayer 2, you got a(n) " << rand_num << ". Your running total is " << sum << ".\n";

				if (sum < 21) {
					cout << "Do you want another number (0-no or 1-yes)? ";
					while (true) {
    				cin >> turn;
    				next_turn = get_int(turn);
    				if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      				cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      				cin.clear();
      				cin.ignore(256, '\n');
    				} else {
      				cin.clear();
      				cin.ignore(256, '\n');
      				break;
    				}
  				}
				} else if (sum == 21) {
					cout << "\nCongrats!!! You got 21 in hand. You win!\n";
					player_two += bet;
					cout << "Player 2 has " << player_two << ".\n";
					break;
				} else {
					cout << "\nYou bust! You lose!\n";
					player_two = 0;
					cout << "Player 2 has " << player_two << ".\n";
					break;
				}
			} else {
				cout << "\nYour total points are " << sum << ".\n";

				dealer = dealer_game();
				if (dealer > 21) {
					player_two += bet;
					cout << "\nPlayer 2 has " << player_two << ".\n";
				}

				if (dealer == 21) {
					player_two = 0;
					cout << "Player 2 has " << player_two << ".\n";
				}
				break;
			}

			if (sum == dealer) {
				cout << "The dealer has " << dealer << " points. Tie game!\nPlayer 2 has " << player_two << ".\n";
			}
		}
	} else if (num_of_players == 3) {
		player_one = player_one_money();
		cout << "\n\n\nPlayer 1's turn...\nPlayer 1 how much do you bet you can beat the dealer? ";
		while (true) {
    	cin >> bet_money;
    	bet = get_int(bet_money);
    	if (bet == -1 || bet < 1 || bet > player_one) {
      	cout << "\nInvalid input! Please enter a valid amount: ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		rand_num = (rand() % 11) + 1;
		sum += rand_num;
		cout << "\nPlayer 1, you got a(n) " << rand_num << ". Your running total is " << sum << ".\nDo you want another number (0-no or 1-yes)? ";
		while (true) {
    	cin >> turn;
    	next_turn = get_int(turn);
    	if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      	cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		while (true) {
			if (next_turn == 1) {
				rand_num = (rand() % 11) + 1;
				sum += rand_num;
				cout << "\nPlayer 1, you got a(n) " << rand_num << ". Your running total is " << sum << ".\n";

				if (sum < 21) {
					cout << "Do you want another number (0-no or 1-yes)? ";
					while (true) {
    				cin >> turn;
    				next_turn = get_int(turn);
    				if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      				cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      				cin.clear();
      				cin.ignore(256, '\n');
    				} else {
      				cin.clear();
      				cin.ignore(256, '\n');
      				break;
    				}
  				}
				} else if (sum == 21) {
					cout << "\nCongrats!!! You got 21 in hand. You win!\n";
					player_one += bet;
					cout << "Player 1 has " << player_one << ".\n";
					break;
				} else {
					cout << "\nYou bust! You lose!\n";
					player_one = 0;
					cout << "Player 1 has " << player_one << ".\n";
					break;
				}
			} else {
				cout << "\nYour total points are " << sum << ".\n";

				dealer = dealer_game();
				if (dealer > 21) {
					player_one += bet;
					cout << "\nPlayer 1 has " << player_one << ".\n";
				}

				if (dealer == 21) {
					player_one = 0;
					cout << "Player 1 has " << player_one << ".\n";
				}
				break;
			}

			if (sum == dealer) {
				cout << "The dealer has " << dealer << " points. Tie game!\nPlayer 1 has " << player_one << ".\n";
			}
		}

		player_two = player_two_money();
		cout << "\nPlayer 2's turn...\nPlayer 2 how much do you bet you can beat the dealer? ";
		while (true) {
    	cin >> bet_money;
    	bet = get_int(bet_money);
    	if (bet == -1 || bet < 1 || bet > player_two) {
      	cout << "\nInvalid input! Please enter a valid amount: ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		rand_num = (rand() % 11) + 1;
		sum = 0;
		sum += rand_num;
		cout << "\nPlayer 2, you got a(n) " << rand_num << ". Your running total is " << sum << ".\nDo you want another number (0-no or 1-yes)? ";
		while (true) {
    	cin >> turn;
    	next_turn = get_int(turn);
    	if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      	cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		while (true) {
			if (next_turn == 1) {
				rand_num = (rand() % 11) + 1;
				sum += rand_num;
				cout << "\nPlayer 2, you got a(n) " << rand_num << ". Your running total is " << sum << ".\n";

				if (sum < 21) {
					cout << "Do you want another number (0-no or 1-yes)? ";
					while (true) {
    				cin >> turn;
    				next_turn = get_int(turn);
    				if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      				cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      				cin.clear();
      				cin.ignore(256, '\n');
    				} else {
      				cin.clear();
      				cin.ignore(256, '\n');
      				break;
    				}
  				}
				} else if (sum == 21) {
					cout << "\nCongrats!!! You got 21 in hand. You win!\n";
					player_two += bet;
					cout << "Player 2 has " << player_two << ".\n";
					break;
				} else {
					cout << "\nYou bust! You lose!\n";
					player_two = 0;
					cout << "Player 2 has " << player_two << ".\n";
					break;
				}
			} else {
				cout << "\nYour total points are " << sum << ".\n";

				dealer = dealer_game();
				if (dealer > 21) {
					player_two += bet;
					cout << "\nPlayer 2 has " << player_two << ".\n";
				}

				if (dealer == 21) {
					player_two = 0;
					cout << "Player 2 has " << player_two << ".\n";
				}
				break;
			}

			if (sum == dealer) {
				cout << "The dealer has " << dealer << " points. Tie game!\nPlayer 2 has " << player_two << ".\n";
			}
		}

		player_three = player_three_money();
		cout << "\nPlayer 3's turn...\nPlayer 3 how much do you bet you can beat the dealer? ";
		while (true) {
    	cin >> bet_money;
    	bet = get_int(bet_money);
    	if (bet == -1 || bet < 1 || bet > player_three) {
      	cout << "\nInvalid input! Please enter a valid amount: ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		rand_num = (rand() % 11) + 1;
		sum = 0;
		sum += rand_num;
		cout << "\nPlayer 3, you got a(n) " << rand_num << ". Your running total is " << sum << ".\nDo you want another number (0-no or 1-yes)? ";
		while (true) {
    	cin >> turn;
    	next_turn = get_int(turn);
    	if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      	cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		while (true) {
			if (next_turn == 1) {
				rand_num = (rand() % 11) + 1;
				sum += rand_num;
				cout << "\nPlayer 3, you got a(n) " << rand_num << ". Your running total is " << sum << ".\n";

				if (sum < 21) {
					cout << "Do you want another number (0-no or 1-yes)? ";
					while (true) {
    				cin >> turn;
    				next_turn = get_int(turn);
    				if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      				cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      				cin.clear();
      				cin.ignore(256, '\n');
    				} else {
      				cin.clear();
      				cin.ignore(256, '\n');
      				break;
    				}
  				}
				} else if (sum == 21) {
					cout << "\nCongrats!!! You got 21 in hand. You win!\n";
					player_three += bet;
					cout << "Player 3 has " << player_three << ".\n";
					break;
				} else {
					cout << "\nYou bust! You lose!\n";
					player_three = 0;
					cout << "Player 3 has " << player_three << ".\n";
					break;
				}
			} else {
				cout << "\nYour total points are " << sum << ".\n";

				dealer = dealer_game();
				if (dealer > 21) {
					player_three += bet;
					cout << "\nPlayer 2 has " << player_three << ".\n";
				}

				if (dealer == 21) {
					player_three = 0;
					cout << "Player 2 has " << player_three << ".\n";
				}
				break;
			}

			if (sum == dealer) {
				cout << "The dealer has " << dealer << " points. Tie game!\nPlayer 3 has " << player_three << ".\n";
			}
		}
	} else {
		player_one = player_one_money();
		cout << "\n\n\nPlayer 1's turn...\nPlayer 1 how much do you bet you can beat the dealer? ";
		while (true) {
    	cin >> bet_money;
    	bet = get_int(bet_money);
    	if (bet == -1 || bet < 1 || bet > player_one) {
      	cout << "\nInvalid input! Please enter a valid amount: ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		rand_num = (rand() % 11) + 1;
		sum += rand_num;
		cout << "\nPlayer 1, you got a(n) " << rand_num << ". Your running total is " << sum << ".\nDo you want another number (0-no or 1-yes)? ";
		while (true) {
    	cin >> turn;
    	next_turn = get_int(turn);
    	if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      	cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		while (true) {
			if (next_turn == 1) {
				rand_num = (rand() % 11) + 1;
				sum += rand_num;
				cout << "\nPlayer 1, you got a(n) " << rand_num << ". Your running total is " << sum << ".\n";

				if (sum < 21) {
					cout << "Do you want another number (0-no or 1-yes)? ";
					while (true) {
    				cin >> turn;
    				next_turn = get_int(turn);
    				if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      				cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      				cin.clear();
      				cin.ignore(256, '\n');
    				} else {
      				cin.clear();
      				cin.ignore(256, '\n');
      				break;
    				}
  				}
				} else if (sum == 21) {
					cout << "\nCongrats!!! You got 21 in hand. You win!\n";
					player_one += bet;
					cout << "Player 1 has " << player_one << ".\n";
					break;
				} else {
					cout << "\nYou bust! You lose!\n";
					player_one = 0;
					cout << "Player 1 has " << player_one << ".\n";
					break;
				}
			} else {
				cout << "\nYour total points are " << sum << ".\n";

				dealer = dealer_game();
				if (dealer > 21) {
					player_one += bet;
					cout << "\nPlayer 1 has " << player_one << ".\n";
				}

				if (dealer == 21) {
					player_one = 0;
					cout << "Player 1 has " << player_one << ".\n";
				}
				break;
			}

			if (sum == dealer) {
				cout << "The dealer has " << dealer << " points. Tie game!\nPlayer 1 has " << player_one << ".\n";
			}
		}

		player_two = player_two_money();
		cout << "\nPlayer 2's turn...\nPlayer 2 how much do you bet you can beat the dealer? ";
		while (true) {
    	cin >> bet_money;
    	bet = get_int(bet_money);
    	if (bet == -1 || bet < 1 || bet > player_two) {
      	cout << "\nInvalid input! Please enter a valid amount: ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		rand_num = (rand() % 11) + 1;
		sum = 0;
		sum += rand_num;
		cout << "\nPlayer 2, you got a(n) " << rand_num << ". Your running total is " << sum << ".\nDo you want another number (0-no or 1-yes)? ";
		while (true) {
    	cin >> turn;
    	next_turn = get_int(turn);
    	if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      	cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		while (true) {
			if (next_turn == 1) {
				rand_num = (rand() % 11) + 1;
				sum += rand_num;
				cout << "\nPlayer 2, you got a(n) " << rand_num << ". Your running total is " << sum << ".\n";

				if (sum < 21) {
					cout << "Do you want another number (0-no or 1-yes)? ";
					while (true) {
    				cin >> turn;
    				next_turn = get_int(turn);
    				if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      				cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      				cin.clear();
      				cin.ignore(256, '\n');
    				} else {
      				cin.clear();
      				cin.ignore(256, '\n');
      				break;
    				}
  				}
				} else if (sum == 21) {
					cout << "\nCongrats!!! You got 21 in hand. You win!\n";
					player_two += bet;
					cout << "Player 2 has " << player_two << ".\n";
					break;
				} else {
					cout << "\nYou bust! You lose!\n";
					player_two = 0;
					cout << "Player 2 has " << player_two << ".\n";
					break;
				}
			} else {
				cout << "\nYour total points are " << sum << ".\n";

				dealer = dealer_game();
				if (dealer > 21) {
					player_two += bet;
					cout << "\nPlayer 2 has " << player_two << ".\n";
				}

				if (dealer == 21) {
					player_two = 0;
					cout << "Player 2 has " << player_two << ".\n";
				}
				break;
			}

			if (sum == dealer) {
				cout << "The dealer has " << dealer << " points. Tie game!\nPlayer 2 has " << player_two << ".\n";
			}
		}

		player_three = player_three_money();
		cout << "\nPlayer 3's turn...\nPlayer 3 how much do you bet you can beat the dealer? ";
		while (true) {
    	cin >> bet_money;
    	bet = get_int(bet_money);
    	if (bet == -1 || bet < 1 || bet > player_three) {
      	cout << "\nInvalid input! Please enter a valid amount: ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		rand_num = (rand() % 11) + 1;
		sum = 0;
		sum += rand_num;
		cout << "\nPlayer 3, you got a(n) " << rand_num << ". Your running total is " << sum << ".\nDo you want another number (0-no or 1-yes)? ";
		while (true) {
    	cin >> turn;
    	next_turn = get_int(turn);
    	if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      	cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		while (true) {
			if (next_turn == 1) {
				rand_num = (rand() % 11) + 1;
				sum += rand_num;
				cout << "\nPlayer 3, you got a(n) " << rand_num << ". Your running total is " << sum << ".\n";

				if (sum < 21) {
					cout << "Do you want another number (0-no or 1-yes)? ";
					while (true) {
    				cin >> turn;
    				next_turn = get_int(turn);
    				if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      				cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      				cin.clear();
      				cin.ignore(256, '\n');
    				} else {
      				cin.clear();
      				cin.ignore(256, '\n');
      				break;
    				}
  				}
				} else if (sum == 21) {
					cout << "\nCongrats!!! You got 21 in hand. You win!\n";
					player_three += bet;
					cout << "Player 3 has " << player_three << ".\n";
					break;
				} else {
					cout << "\nYou bust! You lose!\n";
					player_three = 0;
					cout << "Player 3 has " << player_three << ".\n";
					break;
				}
			} else {
				cout << "\nYour total points are " << sum << ".\n";

				dealer = dealer_game();
				if (dealer > 21) {
					player_three += bet;
					cout << "\nPlayer 2 has " << player_three << ".\n";
				}

				if (dealer == 21) {
					player_three = 0;
					cout << "Player 2 has " << player_three << ".\n";
				}
				break;
			}

			if (sum == dealer) {
				cout << "The dealer has " << dealer << " points. Tie game!\nPlayer 3 has " << player_three << ".\n";
			}
		}

		player_four = player_four_money();
		cout << "\nPlayer 4's turn...\nPlayer 4 how much do you bet you can beat the dealer? ";
		while (true) {
    	cin >> bet_money;
    	bet = get_int(bet_money);
    	if (bet == -1 || bet < 1 || bet > player_four) {
      	cout << "\nInvalid input! Please enter a valid amount: ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		rand_num = (rand() % 11) + 1;
		sum = 0;
		sum += rand_num;
		cout << "\nPlayer 4, you got a(n) " << rand_num << ". Your running total is " << sum << ".\nDo you want another number (0-no or 1-yes)? ";
		while (true) {
    	cin >> turn;
    	next_turn = get_int(turn);
    	if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      	cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
  	}
		
		while (true) {
			if (next_turn == 1) {
				rand_num = (rand() % 11) + 1;
				sum += rand_num;
				cout << "\nPlayer 4, you got a(n) " << rand_num << ". Your running total is " << sum << ".\n";

				if (sum < 21) {
					cout << "Do you want another number (0-no or 1-yes)? ";
					while (true) {
    				cin >> turn;
    				next_turn = get_int(turn);
    				if (next_turn == -1 || next_turn < 0 || next_turn > 1) {
      				cout << "\nInvalid input! Please select a valid option (0-no or 1-yes): ";
      				cin.clear();
      				cin.ignore(256, '\n');
    				} else {
      				cin.clear();
      				cin.ignore(256, '\n');
      				break;
    				}
  				}
				} else if (sum == 21) {
					cout << "\nCongrats!!! You got 21 in hand. You win!\n";
					player_four += bet;
					cout << "Player 4 has " << player_four << ".\n";
					break;
				} else {
					cout << "\nYou bust! You lose!\n";
					player_four = 0;
					cout << "Player 4 has " << player_four << ".\n";
					break;
				}
			} else {
				cout << "\nYour total points are " << sum << ".\n";

				dealer = dealer_game();
				if (dealer > 21) {
					player_four += bet;
					cout << "\nPlayer 4 has " << player_four << ".\n";
				}

				if (dealer == 21) {
					player_four = 0;
					cout << "Player 4 has " << player_four << ".\n";
				}
				break;
			}

			if (sum == dealer) {
				cout << "The dealer has " << dealer << " points. Tie game!\nPlayer 4 has " << player_four << ".\n";
			}
		}
	}
}

int main() {
	game();

	string play_again;
	while (true) {
		do {
			cout << "\n\n\nDo you want to play again (y/n)? ";
			cin >> play_again;
		} while (play_again != "Yes" && play_again != "yes" && play_again != "Y" && play_again != "y" && play_again != "No" && play_again != "no" && play_again != "N" && play_again != "n");

		if (play_again == "Yes" || play_again == "yes" || play_again == "Y" || play_again == "y") game();
		else {
			cout << "\n\n\nThanks for playing the Game of Twenty One! Hope you enjoyed it! Please play again!\n\n\n";
			break;
		}
	}

	return 0;
}
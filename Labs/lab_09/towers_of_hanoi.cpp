#include <iostream>
#include<cstdlib>
using namespace std;

void checkInput(){
  cin.clear();
  cin.ignore(1000, '\n');
  cout << "Invalid input! Enter a positive integer less than 100: ";
}

//        Towers of Hanoi - Method 1
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
  if (n == 1) {
    cout << "\nMove disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
    return;
  }
  towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
  cout << "\nMove disk " << n << " from rod " << from_rod << " to rod " << to_rod << "\n";
  towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

//        Towers of Hanoi - Method 2
void print_array(int b[][3]) {
  for (int rows = 0 ; rows < 3; rows++) {
    for (int pegs = 0; pegs < 3; pegs++) {
      cout << b[rows][pegs] << " ";
    }
    cout << "\n";
  }
  cout << "-------" << endl;
}

void move(int number_of_disks,int b[][3],int from_col, int to_col) {
  int low = 0;
  int max_d;
  for (max_d = 2 ; max_d >= 0 && b[max_d][from_col] != 0; max_d--)
    number_of_disks = max_d;

  for (max_d = 2; max_d >= 0; max_d--) {
    if (b[max_d][to_col] != 0) {
      continue;
    } else {
      low = max_d;
      break;
    }
  }

  b[low][to_col] = b[number_of_disks][from_col];
  b[number_of_disks][from_col] = 0;

}

// Recursive function
void towers_of_hanoi(int number_of_disks, int b[][3], int from_col, int to_col, int spare) {
  if(number_of_disks >= 1) {
    towers_of_hanoi(number_of_disks-1,b,from_col,spare,to_col);
    move(number_of_disks-1,b,from_col,to_col);
    print_array(b);
    towers_of_hanoi(number_of_disks-1,b,spare,to_col,from_col);
  }
}

int main() {
  //        Towers of Hanoi - Method 1
  int num_disks;
  cout << "\nEnter the number of disks: ";
  cin >> num_disks;
  towerOfHanoi(num_disks, 'A', 'B', 'C');

  //        Towers of Hanoi - Method 2
  string run = "Yes";
  int input = 1, num_of_disks, rows;
  while (true) {
    while (run == "Yes" || run == "yes" || run == "Y" || run == "y") {
      cout << "\nPlease enter the number of disks: ";
      cin >> num_of_disks;
	    if (cin.fail() || num_of_disks > 100 || num_of_disks < 0) {
        checkInput();
		    break;
	    }
      
      int board[num_of_disks][3], cols = 0;
      for (int rows = 0; rows < 3; rows++) {
        for(int cols = 0;cols < 3; cols++)
          board[rows][cols] = 0;
      }
      for (int rows = 0; rows < 3;rows++) {
        board[rows][cols] = rows + 1;
      }
      print_array(board);
      towers_of_hanoi(3, board, 0, 2, 1);
	    
	    cout << "\nWould you like to play again (y/n)? ";
	    cin >> run;
    }
    if (run != "Y" && run !="y") {
      cout << "\n";
      break;
    }
  }

  return 0; 
}
#include <iostream>
#include <cstdlib>
using namespace std;

int **create_arr(int rows, int cols);
void buildBoard(int** arr1, int rows);
void printArray(int** arr1, int rows);
void move(int disks, int** arr, int from_col, int to_col);
void moveDisk(int disk, int** arr2, int from_column, int to_column, int rows);
void towers(int disks, int** arr2, int from_column, int to_column, int spare, int rows);

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

int is_magic_square(int matrix[50][50], int n, int m) {
  int sum1 = 0, sum2=0;

  // finding the sum of first diagonal
  for (int i = 0; i < n; i++)
    sum1 = sum1 + matrix[i][i];
  
  // finding the sum of second diagonal
  for (int i = 0; i < n; i++)
    sum2 = sum2 + matrix[i][n - 1 - i];
  
  //checking, whether the sum of two diagonal is same or not
  if(sum1 != sum2) return 0; 
  
  // finding the sum of each row 
  for (int i = 0; i < n; i++) {
    int rowSum = 0;
    for (int j = 0; j < m; j++) 
      rowSum = rowSum + matrix[i][j]; 
          
    // checking, whether eachh row sum is equal to diagonal sum or not
    if (rowSum != sum1) return 0; 
  }
  
  // finding the sum of each column
  for (int i = 0; i < n; i++) {
    int columnSum = 0;
    for (int j = 0; j < n; j++)
      columnSum += matrix[j][i];

    // checking, whether each column sum is equal to diagonal sum or not
    if (columnSum != sum1) return 1;
  }
  return true;
}

void magic_square(int matrix[50][50]) {
  int columns, rows;
  cout<<"\n\n\nEnter the row length: ";
  cin >> rows;
  cout<<"Enter the column length: ";
  cin >> columns;

  if(columns != rows){
    cout<<"Length of row and column should be equal.\n";
    exit(0);
  }
  cout << "\nInput the element of matrix:\n";

  for(int i = 0; i < columns; i++) {
    for(int j = 0; j < rows; j++) {
      cout << "Enter element " << j+1 << ": ";
      cin>>matrix[i][j];
    }
  }

  if (is_magic_square(matrix, columns, rows)) {
    cout << "\nHooray!!! The array is Magic Square!\n\n\n"; 
  } else {
    cout << "Bummer! The array is Not a magic Square!\n\n\n";
  }
}

int main(int argc, const char *argv[]) {
  //        Towers of Hanoi - Method 1
  int num_disks;
  cout << "\nEnter the number of disks: ";
  cin >> num_disks;
  towerOfHanoi(num_disks, 'A', 'B', 'C');

  //        Towers of Hanoi - Method 2
  int number_of_disks;
  cout << "\n\n\nPlease enter the number of disks: ";
  cin >> number_of_disks;
  int rows = atoi(argv[1]);
  int columns = atoi(argv[2]);
  int **arr = create_arr(rows, columns);
  for (int row = 0; row < 3; row++) {
    for(int col = 0; col < 3; col++) {
      arr[row][col] = 0;
    }
  }
  int cols = 0;
  for (int row = 0; row < 3; row++) {
    arr[row][cols] = row + 1;
  }
  printArray(arr, rows);
  towers(number_of_disks, arr, 0, 2, 1, number_of_disks);
  
  int matrix[50][50] = {{0}};
  magic_square(matrix);

  return 0;
}

int **create_arr(int rows, int cols) {
  int **arr = new int*[rows];
  for(int i = 0; i < rows; i++) {
    arr[i] = new int[cols];
  }
  return arr;
}

void buildBoard(int** arr1, int rows){
  for (int x = 0; x < rows; x++) {
    arr1[x][0] = x+1;
	  for (int y = 1; y < 3; y++) {
      arr1[x][y] = 0;
	  }
  }
}

void printArray(int** arr1, int rows){
  for (int x = 0; x < rows; x++) {
    for (int y = 0; y < 3; y++) {
      cout << arr1[x][y] << " ";
	  }
	  cout << "\n";
  }
  cout << "---------" << "\n";
}

void move(int disks, int** arr, int from_col, int to_col) {
  int low = 0;
  int max_d;
  for (max_d = 2 ; max_d >= 0 && arr[max_d][from_col] != 0; max_d--) {
    disks = max_d;
  }
    
  for (max_d = 2; max_d >= 0; max_d--) {
    if (arr[max_d][to_col] != 0) {
      continue;
    } else {
      low = max_d;
      break;
    }
  }

  arr[low][to_col] = arr[disks][from_col];
  arr[disks][from_col] = 0;
}

void moveDisk(int disk, int** arr2, int from_column, int to_column, int rows){
  int lowest, i;
  for(i = rows-1; i >= 0 && arr2[i][from_column] != 0; i--)
    disk = i;

  for(i = rows-1; i >= 0; i--) {
    if (arr2[i][to_column] != 0) {
      return;
	  } else {
      lowest = i;
	    break;
	  }
  }

  arr2[lowest][to_column] = arr2[disk][from_column];
  arr2[disk][from_column] = 0;
}

void towers(int disks, int** arr2, int from_column, int to_column, int spare, int rows) {
  if(disks != 0) {
    towers(disks-1, arr2, from_column, to_column, spare, rows);
	  //cout << "Moving disk " << disks << " from " << from_column << " to " << to_column << endl;
	  move(disks-1, arr2, from_column, to_column);	
	  printArray(arr2, rows);
	  towers(disks-1, arr2, spare, from_column, to_column, rows);
  }
}
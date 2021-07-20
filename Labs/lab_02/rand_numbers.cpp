#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	int x;
	srand(time(NULL));
	x = rand();
	cout << "x = " << x << endl;
	srand(time(NULL));
	x = rand();
	cout << "x = " << x << endl;
	
	int rand_num = rand() % 6;
	if (rand_num == 0) {
		cout << "Bummer, I'm zero!!!\n";
	} else if (rand_num % 2 == 1) {
		cout << "I'm an odd number!\n";
	} else {
		cout << "I'm an even number!\n";
	}
	cout << rand_num << "\n";
	
	return 0;
}

#include <iostream>
using namespace std;

int main() {
	int likes_vi_editor;
	cout << "Dou you like the vi editor?" << "\n";
	cin >> likes_vi_editor;
	if (likes_vi_editor == 1) {
		cout << "You love vi!\n";
	} else if (likes_vi_editor == 0) {
		cout << "You hate vi!\n";
	} else {
		cout << "Invalid input!\n";
	}
}

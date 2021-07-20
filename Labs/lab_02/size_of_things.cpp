#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int bits;
	cout << "Please enter the number of bits: ";
	cin >> bits;

	int unsigned_binary = pow(2, bits) - 1;
	int max_signed_binary = pow(2, bits-1) - 1;
	int min_signed_binary = pow(-2, bits-1);
	cout << "Maximum value for an Unsigned Binary: " << unsigned_binary << "\n";
	cout << "Maximum value for a Signed Binary: " << max_signed_binary << "\n";
	cout << "Minimum value for a Signed Binary: " << min_signed_binary << "\n";

	int new_unsigned_binary = unsigned_binary + 1;
	int new_max_signed_binary = max_signed_binary + 1;
	int new_min_signed_binary = min_signed_binary - 1;
	cout << "The result of incrementing 1 to the  Unsigned Binary is: " << new_unsigned_binary << "\n";
	cout << "The result of incrementing 1 to the Signed Binary is: " << new_max_signed_binary << "\n";
	cout << "The result of decrementing 1 to the Signed Binary is: " << new_min_signed_binary << "\n";
}
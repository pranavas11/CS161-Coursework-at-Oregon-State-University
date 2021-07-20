#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int atoi() {
     char char_value;
     cout << "\nEnter a character to find the corresponding ASCII integer value: ";
     cin >> char_value;
     int number = (int) char_value;
     return number;
}

char itoa() {
     int int_value;
     cout << "\nEnter a number to find the corresponding ASCII character value: ";
     cin >> int_value;
     char character = (char) int_value;
     return character;
}

int main() {
     int atoi_function = atoi();
     cout << "The ASCII integer value is: " << atoi_function << "\n";
     char itoa_function = itoa();
     cout << "The ASCII character value is: " << itoa_function << "\n\n\n";

     return 0;
}

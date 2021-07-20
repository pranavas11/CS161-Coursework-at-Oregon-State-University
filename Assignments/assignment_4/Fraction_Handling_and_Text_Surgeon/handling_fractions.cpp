#include "handle_fractions.h"
#include <iostream>
#include <cstdlib>
#include <string>
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
  for (int i = 0; i < prompt.length(); i++) {
    if (prompt[i] > 47 && prompt[i] <= 57) {               // checks if numbers are between 0-9
      num = num * 10 + (int(prompt[i] - 48));              // num = 0 * 10 + (integer value of character - 48)) to return num
    } else {
      return -1;
    }
  }
  return num;
}

/*****************************************************************************************************************************
 * ** Function: numerator()
 * ** Description: takes a prompt from the user as a string literal and checks if the number is a valid integer for numerator
 * ** Parameters: none
 * ** Pre-conditions: takes a string prompt
 * ** Post-conditions: returns the a valid integer for numerator
 *****************************************************************************************************************************/
int numerator() {
  int get_num;
  string prompt;
  cout << "\nEnter your numerator: ";
  while (true) {
    cin >> prompt;
    get_num = get_int(prompt);                                  // converts the given integer stored in a string type to integer type
    if (get_num == -1) {
      cout << "Invalid input! Enter whole numbers only: ";     // check for invalid input and reprompt user
      cin.clear();
      cin.ignore(256, '\n');
    } else {
      cin.clear();
      cin.ignore(256, '\n');
      break;
    }
  }
  return get_num;
}

/*******************************************************************************************************************************
 * ** Function: denominator()
 * ** Description: takes a prompt from the user as a string literal and checks if the number is a valid integer for denominator
 * ** Parameters: none
 * ** Pre-conditions: takes a string prompt
 * ** Post-conditions: returns the a valid integer for denominator
 ******************************************************************************************************************************/
int denominator() {
  int get_num;
  string prompt;
  cout << "Enter your denominator: ";
  while (true) {
    cin >> prompt;
    get_num = get_int(prompt);                                          // converts the given integer stored in a string type to integer type
    if (get_num == -1) {
      cout << "Invalid input! Enter whole numbers only: ";              // check for invalid input and reprompt user
      cin.clear();
      cin.ignore(123, '\n');
    } else if (get_num == 0) {                                          // checks if denominator equals 0
      cout << "Invalid input! Denominator cannot be 0! Please enter again: ";
      cin.clear();
      cin.ignore(123, '\n');
    } else {
      cin.clear();
      cin.ignore(123, '\n');
      break;
    }
  }
  return get_num;
}

/*          Method 1 - Using the Iterative Method
int gcd(int num1, int num2) {  
  int remainder = 0, a, b;
  a = (num1 > num2) ? num1 : num2;
  b = (num1 < num2) ? num1 : num2;
  remainder = b;
  while (a % b != 0) {
    remainder = a % b;
    a = b;
    b = remainder;
  }
  return remainder;
}
*/

/***************************************************
 * ** Function: gcd()
 * ** Description: calculates GCD of two numbers
 * ** Parameters: int num1, int num2
 * ** Pre-conditions: takes a string prompt
 * ** Post-conditions: returns calcualated GCD value
 ***************************************************/
int gcd(int num1, int num2) {                                // Method 2 - Using the Recursive Method
  if (num2 == 0) return num1;
  return gcd(num2, num1 % num2);                  // using recursion to calculate GCD of two numbers
}

/*****************************************************************************************************
 * ** Function: to_lowest_terms()
 * ** Description: checks if denominator equals 0 and prints out the GCD of numerator and denominator
 * ** Parameters: int &numerator, int &denominator
 * ** Pre-conditions: checks if denominator is zero and calls the previous GCD function
 * ** Post-conditions: prints the calculated GCD value
 *****************************************************************************************************/
bool to_lowest_terms(int &numerator, int &denominator) {
  if (denominator == 0) return false;
  int reduce_fraction = gcd(numerator, denominator);                // call the above gcd() function for numerator and denominator
  cout << "The GCD is: " << reduce_fraction << "\n";
  return true;
}

/******************************************************************************************
 * ** Function: lowest_fraction()
 * ** Description: calculates the lowest terms of a fraction
 * ** Parameters: none
 * ** Pre-conditions: calls all of the previous functions and does the simplifying process
 * ** Post-conditions: returns the fraction in its lowest terms
 *****************************************************************************************/
void lowest_fraction() {
  int numer = numerator();
  int denom = denominator();
  bool lowest_terms = to_lowest_terms(numer, denom);
  int reduce_fraction = gcd(numer, denom);
  int divide_numerator = numer / reduce_fraction;
  int divide_denominator = denom / reduce_fraction;
  if (divide_numerator > 0 && divide_denominator < 0) {                // if numerator is postive and denominator is negative, switch signs
    divide_denominator *= -1;
    divide_numerator *= -1;
  }
  if (divide_denominator == 1 || divide_denominator == -1) {
    cout << "The lowest terms of your fraction: " << divide_numerator << "\n\n\n";
  } else  {
    cout << "The lowest terms of your fraction: " << divide_numerator << "/" << divide_denominator << "\n\n\n";
  }
}
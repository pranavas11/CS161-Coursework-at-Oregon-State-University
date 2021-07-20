/***********************************************************************************
 * ** Program: assignment3.cpp
 * ** Author: Pranav Prabhu
 * ** Date: 02/25/2021
 * ** Description: This program simplifies a fraction to its lowest terms
 * ** Input: numerator, denominator
 * ** Output: fraction in its lowest terms
 ***********************************************************************************/

#include <iostream>
#include "handle_fractions.h"
#include "text_surgeon.h"
#include <cstdlib>
#include <string>
using namespace std;

// my main() function had to be more than 15 lines because I couldn't have 2 main() functions for parts A & B as it throws me an error upon compilation
int main() {
  lowest_fraction();                        // call the lowest_fraction() function to find the lowest term of a fraction
  int repeat;
  while (true) {
    cout << "Do you want to do another conversion (0-no, 1-yes)? ";          // ask user for another conversion
    cin >> repeat;
    if (repeat == 1) {
      lowest_fraction();
    } else {
      break;
    }
  }
  cout << "\n";
  
  char sentence[1024];                        // C-Style string which stores upto 1023 characters
  int answer;
  cout << "\nEnter a sentence/paragraph: ";
  cin.ignore();
  cin.getline(sentence, 1024);

  char *str = to_lower(sentence);              // calls the to_lower() function, which turns all alphabetic characters to its lowest terms
  char *removeSpecialCharacters = purge_string(str);            // calls the purge_string() function, which removes all special characters from the sentence

  while (true) {
    cout << "\nWhat operation do you want to perform on your sentence?\n";
    cout << "1. Vowels vs. Consonants\n";
    cout << "2. Palindrome Detector\n";
    cout << "3. Words Frequency\n4. Quit\n";
    cout << "\nEnter your answer: ";
    cin >> answer;
    if (answer == 1) {
      cout << "\n";
      vowels_and_consonants(sentence);
    } else if (answer == 2) {
      cout << "\n";
      is_palindrome(removeSpecialCharacters);
    } else if (answer == 3) {
      cout << "\n";
      word_frequency();
    } else {
      break;
    }
  }
  
  delete removeSpecialCharacters;
  number_pattern_printing();
  
  return 0;
}
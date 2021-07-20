#include "helper_functions_lib.h"
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

/**************************************************************************************
 * ** Function: check_range()
 * ** Description: checks if a given number is within the lower and upper bounds
 * ** Parameters: int lower_bound, int upper_bound, int test_value
 * ** Pre-conditions: takes three integer parameters
 * ** Post-conditions: returns true/false indicating if the test value is within bounds
 **************************************************************************************/
bool check_range(int lower_bound, int upper_bound, int test_value) {
  if (test_value < lower_bound || test_value > upper_bound) {		// returns false if test value is out of bounds
    return false;
  }
  return true;
}

/***********************************************************************************
 * ** Function: is_capital()
 * ** Description: checks if alphabetic characters are uppercase
 * ** Parameters: char letter
 * ** Pre-conditions: takes a character parameter
 * ** Post-conditions: returns true/false indicating if the letter is capital or not
 ***********************************************************************************/
bool is_capital(char letter) {
  if (letter >= 65 && letter <= 90) {				// returns true if letter is capital according to ASCII table
    return true;
  }
  return false;
}

/***********************************************************************
 * ** Function: is_even()
 * ** Description: indicates if an integer is an even number
 * ** Parameters: int num
 * ** Pre-conditions: takes an integer number
 * ** Post-conditions: returns true/false to tell if the number is even
 **********************************************************************/
bool is_even(int num) {
  if (num % 2 == 0) {				// returns true if the remainder is 0 (even number)
    return true;
  }
  return false;
}

/**********************************************************************
 * ** Function: is_odd()
 * ** Description: indicates if an integer is an odd number
 * ** Parameters: int num
 * ** Pre-conditions: takes an integer number
 * ** Post-conditions: returns true/false to tell if the number is odd
 *********************************************************************/
bool is_odd(int num) {
  if (num % 2 == 1) {				// returns true if remainder is 1 (odd number)
    return true;
  }
  return false;
}

/************************************************************************************************************************************
 * ** Function: equality_test()
 * ** Description: indicates if two integers are equal
 * ** Parameters: int num1, int num2
 * ** Pre-conditions: takes two integer numbers
 * ** Post-conditions: returns a number to tell if the two numbers are equal to each other, or less than or greater than one another
 ***********************************************************************************************************************************/
int equality_test(int num1, int num2) {
  if (num1 < num2) {				// returns the corresponding integer according to the conditions
    return -1;
  } else if (num1 == num2) {
    return 0;
  } else {
    return 1;
  }
}

/***************************************************************************************************
 * ** Function: float_is_equal()
 * ** Description: indicates if two decimal values are equal to each other with a certain precision
 * ** Parameters: float num1, float num2, float precision
 * ** Pre-conditions: takes two decimal numbers
 * ** Post-conditions: returns true/false to tell if the two decimals numbers are equal
 ***************************************************************************************************/
bool float_is_equal(float num1, float num2, float precision) {
  if (fabs(num1 - num2) < precision) {		// returns true if absolute value of the difference is less than precision
    return true;
  }
  return false;
}

/****************************************************************************
 * ** Function: is_int()
 * ** Description: indicates if a given string is an integer
 * ** Parameters: string num
 * ** Pre-conditions: takes a string parameter
 * ** Post-condition: returns true/false to tell if the string is an integer
 ***************************************************************************/
bool is_int(string num) {
  for (int i = 0; i < num.length(); i++) {		// returns false if entire string is not an integer
    if (!(num[i] == '1' || num[i] == '2' || num[i] == '3' || num[i] == '4' || num[i] == '5' || num[i] == '6' || num[i] == '7' || num[i] == '8' || num[i] == '9' || num[i] == '0' || num[i] == '-')) {
      return false;
    }
  }
  return true;
}

/********************************************************************************
 * ** Function: numbers_present()
 * ** Description: indicates if a given string contains at least one number
 * ** Parameters: string sentence
 * ** Pre-conditions: takes a string parameter
 * ** Post-conditions: returns true/false to tell if the string contains a number
 ********************************************************************************/
bool numbers_present(string sentence) {
  string nums = "0123456789";
  for (int i = 0; i < sentence.length(); i++) {
    for (int j = 0; j < nums.length(); j++) {
      if (sentence[i] == nums[j]) {
        return true;			// returns true if at least character is an integer
      }
    }
  }
  return false;
}

/*********************************************************************************
 * ** Function: letters_present()
 * ** Description: indicates if a given string contains at least one letter
 * ** Parameters: string sentence
 * ** Pre-conditions: takes a string parameter
 * ** Post-conditions: returns true/false to tell if the string contains a letter
 ********************************************************************************/
bool letters_present(string sentence) {
  string uppercase_letters = "QWERTYUIOPASDFGHJKLZXCVBNM";
  string lowercase_letters = "qwertyuiopasdfghjklzxcvbnm";
  for (int i = 0; i < sentence.length(); i++) {
    for (int j = 0; j < uppercase_letters.length(); j++) {
      if (sentence[i] == uppercase_letters[j] || sentence[i] == lowercase_letters[j]) {
        return true;			// returns true if at least one alphabetic character is detected
      }
    }
  }
  return false;
}

/********************************************************************
 * ** Function: contains_sub_string()
 * ** Description: indicates if a sub-string exists in a sentence
 * ** Parameters: string sentence, string sub-string
 * ** Pre-conditions: takes two string parameters
 * ** Post-conditions: returns true/false to tell if a string exists
 *******************************************************************/
bool contains_sub_string(string sentence, string sub_string) {
  int sentence_length = sentence.length();
  int sub_string_length = sub_string.length();
  for (int i = 0; i <= sentence_length - sub_string_length; i++) {   // loops through difference in length of sentence and sub-string
    int j;
    for (j = 0; j < sub_string_length; j++) {		// loops through the length of sub-string
      if (sentence[i+j] != sub_string[j]) {		// if characters in sentence do not match that of sub-string, it exits
        break;			// if continous characters do not match, then the program exits the loop
      }
    }
    if (j == sub_string_length) {		// returns true if a sub-string match is found
      return true;
    }
  }
  return false;
}

/******************************************************************
 * ** Function: word_count()
 * ** Description: counts the number of words in a given sentence
 * ** Parameters: string sentence
 * ** Pre-conditions: takes a string parameter
 * ** Post-conditions: returns the number of words in the sentence
 *****************************************************************/
int word_count(string sentence) {
  int length = 1;
  for (int i = 0; i < sentence.length(); i++) {
    if (sentence.at(i) == ' ') {		// increases word count if a space is detected between two words
      length++;
    }
    if (sentence.at(0) == ' ') {		// word count = 0 if no words
      length -= 2;
    }
    if (sentence.at(i) == 32  && i == (sentence.length() - 1)) {
      length -= 1;	// if space at end with no characters, subtract 1 from total words detected
    }
  }
  return length;
}

/**************************************************************************
 * ** Function: to_upper()
 * ** Description: capitalizes all alphabetic characters in a given string
 * ** Parameters: string sentence
 * ** Pre-conditions: takes a string sentence
 * ** Post-conditions: returns all alphabetic letters capitalized
 *************************************************************************/
string to_upper(string sentence) {
  for (int i = 0; sentence[i] != '\0'; i++) {
    if (sentence[i] >= 'a' && sentence[i] <= 'z') {
      sentence[i] -= 32;	// subtract the ASCII value of 32 from lowercase letters to obtain corresponding uppercase letters
    }
  }
  return sentence;		// return all alphabetic characters to uppercase letters
}

/***************************************************************************
 * ** Function: to_lower()
 * ** Description: decapitalizes all alphabetic characters in a given string
 * ** Parameters: string sentence
 * ** Pre-conditions: takes a string sentence
 * ** Post-conditions: retuns all aphabetic characters decapitalized
 ***************************************************************************/
string to_lower(string sentence) {
  for (int i = 0; sentence[i] != '\0'; i++) {
    if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
      sentence[i] += 32;	// add the ASCII value of 32 to uppercase letters to obtain corresponding lowercase letters
    }
  }
  return sentence;		// return all alphabetic characters to lowercase letters
}

/***************************************************************************************************************
 * ** Function: get_int()
 * ** Description: takes a prompt from the user as a string literal and checks if the inputs is a valid integer
 * ** Parameters: string prompt
 * ** Pre-conditions: takes a string prompt
 * ** Post-conditions: returns the provided integer
 **************************************************************************************************************/
int get_int(string prompt) {
  int num = 0;  
  bool flag = false;
  for (int i = 0; i < prompt.length(); i++) {
    if (prompt[i] == '-') {
      flag = true;		// if minus sign is detected at the beginning, set flag equal to true
    } else if (prompt[i] < 48 || prompt[i] > 57) {	// if non-integer values are detected, return -1
      return -1;
    } else {
      num = num * 10 + (int(prompt[i] - 48));	// num = 0 * 10 + (integer value of character - 48)) to return num
    }			// use ASCII to check for decimal values of numeric characters
  }
  
  if (flag == true) {
    return -1 * num;		// returns a negative integer if flag is true
  }
  return num;

  /*                    Method 2
  int i = 0, num = 0;
  bool flag = false;
  while (prompt[i] != '\0') {
    if (prompt[i] == '-') {
      flag = true;
    } else if (prompt[i] < 48 || prompt[i] > 57) {
      return -1;
    } else {
      num = num * 10 + (prompt[i] - 48);
      i++;
    }
  }
  if (flag == true) {
    return -1 * num;
  }
  return num;
  */
}

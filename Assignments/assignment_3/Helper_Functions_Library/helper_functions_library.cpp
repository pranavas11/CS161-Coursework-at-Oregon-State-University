/***********************************************************************************
 * ** Program: assignment2.cpp
 * ** Author: Pranav Prabhu
 * ** Date: 02/05/2021
 * ** Description: This program is a list of helper functions (a.k.a helper functions library) which are mostly hard-coded except the last get_int() function
 * ** Input: lower_bound, upper_bound, test_value, letter, num, num1, num2, precision, setence, sub_string, prompt
 * ** Output: all of the boolean functions either return true/false, the integer functions return an integer value, string functions either capitalize or de-capitalize the entire string, and the last get_int() function returns user entered integer number
 ***********************************************************************************/

#include <iostream>
#include "helper_functions_lib.h"
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

int main() {
  bool range_check1 = check_range(0, 1000, 500);
  cout << "\nTesting check_range(\"0, 1000, 500\")...\n";
  cout << "Expected: 1 "  << "\tActual: " << range_check1;
  (range_check1 == 1) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  bool range_check2 = check_range(-100, 0, 101);
  cout << "\nTesting check_range(\"-100, 0, 101\")...\n";
  cout << "Expected: 0 "  << "\tActual: " << range_check2;
  (range_check2 == 0) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  bool capital_check1 = is_capital('P');
  cout << "\n\n\nTesting is_capital(\"P\")...\n";
  cout << "Expected: 1 "  << "\tActual: " << capital_check1;
  (capital_check1 == 1) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  bool capital_check2 = is_capital('a');
  cout << "\nTesting is_capital(\"a\")...\n";
  cout << "Expected: 0 "  << "\tActual: " << capital_check2;
  (capital_check2 == 0) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  bool even_number_check1 = is_even(300);
  cout << "\n\n\nTesting is_even(\"300\")...\n";
  cout << "Expected: 1 "  << "\tActual: " << even_number_check1;
  (even_number_check1 == 1) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  bool even_number_check2 = is_even(151);
  cout << "\nTesting is_even(\"151\")...\n";
  cout << "Expected: 0 "  << "\tActual: " << even_number_check2;
  (even_number_check2 == 0) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  bool odd_number_check1 = is_odd(1357);
  cout << "\n\n\nTesting is_odd(\"1357\")...\n";
  cout << "Expected: 1 "  << "\tActual: " << odd_number_check1;
  (odd_number_check1 == 1) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  bool odd_number_check2 = is_odd(950);
  cout << "\nTesting is_odd(\"950\")...\n";
  cout << "Expected: 0 "  << "\tActual: " << odd_number_check2;
  (odd_number_check2 == 0) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  int equal_numbers_test1 = equality_test(503, 753);
  cout << "\n\n\nTesting equality_test(\"503, 753\")...\n";
  cout << "Expected: -1 "  << "\tActual: " << equal_numbers_test1;
  (equal_numbers_test1 == -1) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  int equal_numbers_test2 = equality_test(1003, 1003);
  cout << "\nTesting equality_test(\"1003, 1003\")...\n";
  cout << "Expected: 0 "  << "\tActual: " << equal_numbers_test2;
  (equal_numbers_test2 == 0) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  int equal_numbers_test3 = equality_test(31599, 5019);
  cout << "\nTesting equality_test(\"31599, 5019\")...\n";
  cout << "Expected: 1 "  << "\tActual: " << equal_numbers_test3;
  (equal_numbers_test3 == 1) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  bool float_nums_equality_test1 = float_is_equal(5.5, 5.5, 0.01);
  cout << "\n\n\nTesting float_is_equal(\"5.5, 5.5, 0.01\")...\n";
  cout << "Expected: 1 "  << "\tActual: " << float_nums_equality_test1;
  (float_nums_equality_test1 == 1) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";
  
  bool float_nums_equality_test2 = float_is_equal(-3.142, 3.1, 0.1);
  cout << "\nTesting float_is_equal(\"-3.142, 3.1, 0.1\")...\n";
  cout << "Expected: 0 "  << "\tActual: " << float_nums_equality_test2;
  (float_nums_equality_test2 == 0) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";
  
  bool is_num1 = is_int("12345");
  cout << "\n\n\nTesting is_int(\"12345\")...\n";
  cout << "Expected: 1 "  << "\tActual: " << is_num1;
  (is_num1 == 1) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  bool is_num2 = is_int("abc500");
  cout << "\nTesting is_int(\"abc500\")...\n";
  cout << "Expected: 0 "  << "\tActual: " << is_num2;
  (is_num2 == 0) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  bool nums_present1 = numbers_present("Pranav100");
  cout << "\n\n\nTesting numbers_present(\"Pranav100\")...\n";
  cout << "Expected: 1 "  << "\tActual: " << nums_present1;
  (nums_present1 == 1) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  bool nums_present2 = numbers_present("I love C++!");
  cout << "\nTesting numbers_present(\"I love C++!\")...\n";
  cout << "Expected: 0 "  << "\tActual: " << nums_present2;
  (nums_present2 == 0) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  bool alpha_present1 = letters_present("CS161");
  cout << "\n\n\nTesting letters_present(\"CS161\")...\n";
  cout << "Expected: 1 "  << "\tActual: " << alpha_present1;
  (alpha_present1 == 1) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  bool alpha_present2 = letters_present("-100.59");
  cout << "\nTesting letters_present(\"-100.59\")...\n";
  cout << "Expected: 0 "  << "\tActual: " << alpha_present2;
  (alpha_present2 == 0) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  bool sub_string1 = contains_sub_string("I love Coding!", "Coding");
  cout << "\n\n\nTesting contains_sub_string(\"I love Coding!\", \"Coding\")...\n";
  cout << "Expected: 1 "  << "\tActual: " << sub_string1;
  (sub_string1 == 1) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  bool sub_string2 = contains_sub_string("I love Coding!", "I L Cd! 100%");
  cout << "\nTesting contains_sub_string(\"I love Coding!\", \"I L Cd! 100%\")...\n";
  cout << "Expected: 0 "  << "\tActual: " << sub_string2;
  (sub_string2 == 0) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  int count_words1 = word_count("MobaXTerm is an I.D.E for C++ Programming!");
  cout << "\n\n\nTesting word_count(\"MobaXTerm is an I.D.E for C++ Programming!\")...\n";
  cout << "Expected: 7 "  << "\tActual: " << count_words1;
  (count_words1 == 7) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";
  
  int count_words2 = word_count("GO C++ ");
  cout << "\nTesting word_count(\"GO C++ \")...\n";
  cout << "Expected: 2 "  << "\tActual: " << count_words2;
  (count_words2 == 2) ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  string upper_check1 = to_upper("C++ Syntax is very important.");
  cout << "\n\n\nTesting to_upper(\"C++ Syntax is very important.\")...\n";
  cout << "Expected: C++ SYNTAX IS VERY IMPORTANT. "  << "\tActual: " << upper_check1;
  (upper_check1 == "C++ SYNTAX IS VERY IMPORTANT.") ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  string upper_check2 = to_upper("100%");
  cout << "\nTesting to_upper(\"100%\")...\n";
  cout << "Expected: 100%! "  << "\tActual: " << upper_check2;
  (upper_check2 == "100%") ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  string lower_check1 = to_lower("Hello WORLD!");
  cout << "\n\n\nTesting to_lower(\"Hello WORLD!\")...\n";
  cout << "Expected: hello world! "  << "\tActual: " << lower_check1;
  (lower_check1 == "hello world!") ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  string lower_check2 = to_lower("$(5^3) * (0.07)");
  cout << "\nTesting to_lower(\"$(5^3) * (0.07)\")...\n";
  cout << "Expected: $(5^3) * (0.07) "  << "\tActual: " << lower_check2;
  (lower_check2 == "$(5^3) * (0.07)") ? cout << "\tPASSED!\n" : cout << "\tFAILED!\n";

  string prompt;
  cout << "\n\n\nEnter an integer: ";
  cin >> prompt;
  int get_num = get_int(prompt);
  while (get_num == -1) {			// if bad input is detected, reprompt user for input
    cout << "\nTesting get_int(" << prompt << ")...\n";
    cout << "Expected: -1 " << "\tActual: " << get_num << "\tPASSED!";
    cout << "\n\nERROR! Please enter only integers: " ;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> prompt;
    get_num = get_int(prompt);
  }
  cout << "\nTesting get_int(\"" << prompt << "\")...\n";
  int prompt_int = get_num;
  cout << "Expected: " << get_num << "\tActual: " << prompt;
  (get_num == prompt_int) ? cout << "\tPASSED!\n\n\n" : cout << "\tFAILED!\n\n\n";

  return 0;
}

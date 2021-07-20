#include "text_surgeon.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

/***************************************************************************
 * ** Function: to_lower()
 * ** Description: decapitalizes all alphabetic characters in a given string
 * ** Parameters: string sentence
 * ** Pre-conditions: takes a string sentence
 * ** Post-conditions: retuns all aphabetic characters decapitalized
 ***************************************************************************/
char* to_lower(char* sentence) {
  for (int i = 0; i < strlen(sentence); i++) {
    if (sentence[i] >= 65 && sentence[i] <= 90) {
      sentence[i] += 32;                  // add the ASCII value of 32 to uppercase letters to obtain corresponding lowercase letters
    }
  }
  return sentence;                        // return all alphabetic characters to lowercase letters
}

/******************************************************************
 * ** Function: word_count()
 * ** Description: counts the number of words in a given sentence
 * ** Parameters: string sentence
 * ** Pre-conditions: takes a string parameter
 * ** Post-conditions: returns the number of words in the sentence
 *****************************************************************/
int word_count(string sentence) {
  int number = 0, check;
  bool letter_check = false;
  for(int i = 0; i < sentence.length(); i++) {
    check = (int)sentence[i];
    if((check >= 97 && check <= 122 ) || (check >= 65 && check <= 90 )) {              // checks for alphabetic characters using ASCII values
      if (letter_check == false) {
        number++;                        // increase number count as letter_check is false
        letter_check = true;             // set letter_check equal to true as alphabetic characters are with the range
      }
    } else{
      letter_check = false;
    }
  }
  return number;
}

/***********************************************************************
 * ** Function: purge_string()
 * ** Description: removes special characters
 * ** Parameters: char *str
 * ** Pre-conditions: takes a char pointer parameter
 * ** Post-conditions: returns special characters removed from sentence
 **********************************************************************/
char *purge_string(char *str) {
  char *copy = new char[1024];                        // copy is a dynamically allocated variable on the heap, which stores an array of 1023 characters
  int counter = 0, x = 0;
    
  for (int i = 0; str[i] != '\0'; i++) {
    if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {       // if str contains alphabetic characters only, increase counter and x
      copy[x] = str[i];
      x += 1;
      counter += 1;
    }
  }
  copy[counter] = '\0';                      // set copy to a null character
  return copy;
}

/***********************************************************************
 * ** Function: vowels_and_consonants()
 * ** Description: checks if number of vowels and consonants match
 * ** Parameters: char *sentence
 * ** Pre-conditions: takes a char pointer parameter
 * ** Post-conditions: returns count of vowels and consonants
 **********************************************************************/
void vowels_and_consonants(char* sentence) {
  int vowels = 0, consonants = 0;
  for (int i = 0; sentence[i]; i++) {                              // if string contains alphabetic characters, check for vowels and consonants
    if ((sentence[i] >= 65 && sentence[i] <= 90)|| (sentence[i] >= 97 && sentence[i] <= 122)) {
      if(sentence[i] == 'a' || sentence[i] == 'e'|| sentence[i] =='i'||sentence[i] == 'o' || sentence[i] == 'u' ||sentence[i] == 'A' || sentence[i] == 'E' || sentence[i] == 'I' || sentence[i] == 'O' || sentence[i]=='U') {
        vowels++;
      } else {
        consonants++;
      }
    }
  }
  if (vowels == consonants) {
    cout << vowels << " vowels = " << consonants << " consonants.\n\n\n";
  } else {
    cout << vowels << " vowels != " << consonants << " consonants.\n\n\n";
  }
}

/************************************************************************
 * ** Function: is_palindrome()
 * ** Description: checks if given sentence is a palindrome or not
 * ** Parameters: char *str
 * ** Pre-conditions: takes a char pointer parameter
 * ** Post-conditions: outputs whether the string is a palindrome or not
 ***********************************************************************/
bool is_palindrome(char *str) {
  char *ptr, *reverse;  // take two pointers ptr and reverse
  ptr = str;

  // initialize ptr to the base address of the string and move it forward to point to the last char of the string
  while (*ptr != '\0') {
    ++ptr;
  }
  --ptr;

  // initialize reverse to the base address of the string and start moving reverse in forward direction and ptr in backward direction simultaneously until middle of the string is reached
  for (reverse = str; ptr >= reverse;) {
    if (*ptr == *reverse) {
      --ptr;
      reverse++;
    } else {
      // if at any point the character pointed by ptr and reverse does not match, then break from the loop
      break;
    } 
  }

  // check if ptr and reverse crossed each other (i.e., reverse > ptr), and if so, then the string is palindrome otherwise not
  if (reverse > ptr) {
    cout << "String is Palindrome.\n\n\n";
    return true;
  } else {
    cout << "String is not a Palindrome.\n\n\n";
    return false;
  }
}

/********************************************************************************
 * ** Function: search()
 * ** Description: checks if two sub-string words match each other
 * ** Parameters: string arr[], string s, int n
 * ** Pre-conditions: takes an arrray, string and integer variables as parameters
 * ** Post-conditions: returns the number of common word occurences
 ********************************************************************************/
int search(string arr[], string s, int n) {      // returns count of occurrences of s in arr[]
  int counter = 0;
  for(int j = 0; j < n; j++) {
    // checking if string given in query is present in the given string, and if present, increase counter
    if (s == arr[j]) {
      counter++;
    }
  }
  return counter;
}

/********************************************************************************
 * ** Function: search_queries()
 * ** Description: checks if words contained in two different arrays match
 * ** Parameters: string arr[], string q[], int n, int m
 * ** Pre-conditions: takes two arrrays and two integer variables as parameters
 * ** Post-conditions: prints the words as well as their frequencies
 ********************************************************************************/
void search_queries(string arr[], string q[], int n, int m) {
  for(int i = 0; i < m; i++) {
    cout << q[i] << " " << search(arr, q[i], n) << "\n";
  }
}

/********************************************************************************************************************************************
 * ** Function: word_frequency()
 * ** Description: counts the frequency of words the user searches for
 * ** Parameters: none
 * ** Pre-conditions: loops the larger sentence array first and loops through the smaller sub-string array and finds the frequencies of words
 * ** Post-conditions: prints the words as well as their frequencies
 ********************************************************************************************************************************************/
 // word_frequency() had to be more than 15 lines as I wasn't able to split this into two void functions easily (I couldn't break it up into two functions and if did, it threw me a lot of errors as I had already 2 functions that I'm calling - search() and search_queries())
void word_frequency() {
  char sentence[1024];                                // C-Style string which stores upto 1023 characters
  int current_word = 0;
  string temp;
  int num_words;
  
  cout << "\nEnter a string: ";
  cin.ignore(123, '\n');
  cin.getline(sentence, sizeof(sentence));              // obtains user input; sizeof() calcualtes bytes in a char data type
  char *sent = to_lower(sentence);                      // sent points to calling to_lower() function on sentence
  int wc = word_count(sent);
  string *str_arr = new string[wc + 1];                // new string array dynamicaly allocated, which stops at a null terminator
  
  for (int i = 0; i < strlen(sent); i++) {
    if (sent[i] != ' ') {                              // if there are no spaces, add words to temp
      temp += sent[i];
    } else {
      str_arr[current_word] = purge_string(((char *)temp.c_str()));      // call purge_string() function and cast temp a char data type
      temp = "";
      current_word++;
    }
  }
  
  char *str_array = purge_string(((char *)temp.c_str()));    // call purge_string() function and cast temp a char data type; assign it to a new char array
  str_arr[current_word] = str_array;
  cout << "Enter the number of words you want to search for: ";
  cin >> num_words;
  cin.ignore(1024, '\n');
  string *arr = new string[num_words];
  
  for (int i = 0; i < num_words; i++) {                  // store user input words into a smaller array
    cout << "Enter word " << i + 1 << ": ";
    cin >> arr[i];
  }
  
  //int string_array_size = sizeof(str_arr) / sizeof(str_arr[0]);
  int string_array_size = wc;                                          // this is number of words in the larger array
  //int num_words_size = sizeof(arr) / sizeof(arr[0]);
  search_queries(str_arr, arr, string_array_size, num_words);             // call search_queries() function passing larger and smaller arrays, larger array size, and total number of words in the array
  
  delete [] str_arr;
  delete [] arr;
  delete str_array;
}

/********************************************************************************************************************************************
 * ** Function: number_pattern_printing()
 * ** Description: prints number patterns specified by the number of rows
 * ** Parameters: none
 * ** Pre-conditions: loops to prints n number of rows with spaces and numbers
 * ** Post-conditions: outputs numbers in a rhombus-shape pattern
 ********************************************************************************************************************************************/
// number_pattern_printing had to be more than 15 lines as I wasn't able to split this into two void functions easily (I couldn't break it up into two functions and if did, it threw me a lot of errors)
void number_pattern_printing() {
  int n, x, y, k;
  cout << "\nEnter the number of rows: ";
  while (true) {                                // error handling which checks for odd number of rows
    cin >> n;
    if ((!cin) || (n % 2 == 0) || (n <= 0)) {
      cout << "Invalid input! Enter odd numbers only: ";
      cin.clear();
      cin.ignore(256, '\n');
    } else break;
  }
  if (n % 2 == 1) {                  // if rows are odd, divide by 2 (int type) and add 1 to print the correct number of rows
    n = (n / 2) + 1;
  }
  for(x = 1; x <= n; x++) {            // loops from 1 to number of rows
    for(y = x; y < n; y++) {            // for n rows, prints spaces
      cout << " ";                      // prints spaces for rhombus shape pattern
    }
    for(k = 1; k < (x*2); k++) {        // prints numbers for n rows with beginning and ending numbers in a row are odd
      cout << k;
    }
    cout << "\n";
  }
  for(x = n-1; x >= 1; x--) {            // decrement after hitting the max number for number of rows
    for(y = n; y >  x; y--) {            // for n rows, prints spaces
      cout << " ";                       // prints spaces for rhombus shape pattern
    }
    for(k = 1; k < (x*2); k++) {          // prints numbers for n rows with beginning and ending numbers in a row are odd
      cout << k;
    }
    cout << "\n";
  }
}
#include <iostream>
#include <string>
using namespace std;

void get_string(string *);
void set_replace_string(string, string *);
int get_search_replace(char, string, string &);

void dynamic_memory1(int *pointerVar, int newVar) {
  pointerVar = new int;
  *pointerVar = newVar;
  cout << "Your entered number was replaced with: " << newVar << ".\n";
  delete pointerVar;
}

void dynamic_memory2(void) {
  int *pointInt;
  float *pointFloat;
  pointInt = new int;
  pointFloat = new float;

  int num1;
  float num2;
  cout << "\n\n\nEnter an integer: ";
  cin >> num1;
  cout << "Enter a float: ";
  cin >> num2;
  
  *pointInt = num1;
  *pointFloat = num2;

  cout << "Entered integer is: " << *pointInt << endl;
  cout << "Entered float is: " << *pointFloat << endl;

  // deallocate the memory
  delete pointInt;
  delete pointFloat;
}

void dynamic_memory3() {
  int num;
  float *ptr;
  cout << "\n\n\nEnter total number of students: ";
  cin >> num;
    
  // memory allocation of num number of floats
  ptr = new float[num];

  cout << "\nEnter GPA of students:" << endl;
  for (int i = 0; i < num; ++i) {
    cout << "Student" << i + 1 << ": ";
    cin >> *(ptr + i);
  }

  cout << "\nDisplaying GPA of students:" << endl;
  for (int i = 0; i < num; ++i) {
    cout << "Student" << i + 1 << ": " << *(ptr + i) << "\n";
  }

  // ptr memory is released
  delete[] ptr;
}

int main() {
  string sentence;
  cout << "\nEnter a string: ";
  getline(cin, sentence);
  cout << "You entered: ";
  get_string(&sentence);

  string str = sentence;
  set_replace_string(sentence, &str);

  char ch;
  cout << "\nEnter a character to replace all of the dashes with: ";
  cin >> ch;
  int replaced_string = get_search_replace(ch, sentence, str);

  int num1, num2;
  cout << "\n\n\nEnter a number: ";
  cin >> num1;
  cout << "Enter the number to be replaced it with: ";
  cin >> num2;
  dynamic_memory1(&num1, num2);

  dynamic_memory2();

  dynamic_memory3();

  return 0;
}

void get_string(string *sentence) {
  cout << *sentence;
}

void set_replace_string(string sentence, string *modified_string) {
  for (int i = 0; i < sentence.length(); i++) {
    if (sentence.at(i) == ' ') {
      (*modified_string).at(i) = '-';
    }
  }
  cout << "\nReplace with dashes (value of copy): " << *modified_string;
}

int get_search_replace(char ch, string str, string &replace) {
  int count = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str.at(i) == ' ') {
      replace[i] = ' ';
    } else if (str.at(i) == ch) {
      replace.at(i) = ch;
      count += 1;
    } else {
      replace[i] = '-';
    }
  }
  cout << "New string: " << replace << "\n";
  cout << "The number of times " << ch << " appears is: " << count << ".\n";
  return count;
}

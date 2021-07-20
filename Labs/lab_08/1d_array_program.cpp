#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void print_sentence() {
  char sentence[1000];
  int words;
  cout << "\nEnter a sentence: ";
  cin.getline(sentence, sizeof(sentence));
  if (cin.fail()) {
    cin.ignore(256, '\n'); //get rid of everything leftover
    cin.clear(); //reset the failbit for the next cin
  }
  cout << "You entered: " << sentence << "\n";
}

void display_words() {
  int words, words_needed;
  cout << "\n\n\nEnter the number of words you want: ";
  cin >> words;
  string sentence[words];
  cout << "\nEnter the array elements:\n";
  cin.ignore();
  for (int i = 0; i < words; i++) {
    cout << "Word " << i + 1 << ": ";
    getline(cin, sentence[i]);
  }
  cout << "\nEnter the number of words you would like to search for: ";
  cin >> words_needed;
  for (int j = 0; j < words_needed; j++) {
    cout << "The words are: \nWord " << j + 1 << ": " << sentence[j] << "\n";
  }
}

void display_numbers() {
  int n, i, id;
  cout << "\n\n\nEnter size of array: ";
  cin >> n;
  int array[n];         //declaring array with size
  cout << "\nEnter array elements:\n";
  for (i = 0; i < n; i++) {
    cout << "Number " << i + 1 << ": ";
    cin >> array[i];
  }
  cout << "\nEnter index of the array: ";
  cin >> id;
  cout << "Value at index " << id << " is " << array[id] << "\n\n\n";
}

int main() {
  print_sentence();
  display_words();
  display_numbers();
}
#include <iostream>
#include <string>
#include <sys/time.h>
#include <cstdlib>
using namespace std;

/*
1) If an ampersand (&) is passed into the parameters like the void function above, it still swaps the functions and works exactly the same as without the ampersand.

2)When using pointers in the function prototype, it prints out the memory address of the stored variables. Then, you need to use pointers for every time you use sen1 and sen2 in the body of the function. When calling it the function from main(), you would need to use the ampersand (&) to print the memory address.
*/

/*
void swap_sentence(string &sen1, string &sen2) {
  // with the ampersand, it still works the same

  string temp = sen1;
  sen1 = sen2;
  sen2 = temp;

  cout << "In swap function ..." << endl;
  cout << "Sentence 1: " << sen1 << endl;
  cout << "Sentence 2: " << sen2 << endl;
}
*/

void swap_sentence(string *sen1, string *sen2) {
  string temp = *sen1;
  *sen1 = *sen2;
  *sen2 = temp;

  cout << "In swap function ..." << endl;
  cout << "Sentence 1: " << sen1 << endl;
  cout << "Sentence 2: " << sen2 << endl;
}

int factorial(int n);

//Method 1 - Fibonacci Sequence for nth term Using Iteration
int fib_iter(int n) {
  int f0 = 0, f1 = 1, sum;
  if (n == 0) {
    return f0;
  } else if (n == 1) {
    return f1;
  } else {
    for (int i = 2; i <= n; i++) {
      sum = f0 + f1;
      f0 = f1;
      f1 = sum;
    }
    return sum;
  }
}

//Method 2 - Fibonacci Sequence for nth term Using Recursion
int fib_recurs(int n) {
  int f0 = 0, f1 = 1;
  if (n == 0) {
    return f0;
  } else if (n == 1) {
    return f1;
  } else {
    return fib_recurs(n-1) + fib_recurs(n-2);
  }
}

//Method 1 - Fibonacci Sequence Using Iteration
void fib_sequence1(int &num) {
  int  f0 = 0, f1 = 1, next_term;
  for (int i = 0; i < num; ++i) {     // or i++
    if (i == 0) {
      cout << f0 << " ";
      continue;
    }
    if (i == 1) {
      cout << f1 << " ";
      continue;
    }
    next_term = f0 + f1;
    f0 = f1;
    f1 = next_term;
    cout << next_term << " ";
  }
}

//Method 2 - Fibonacci Sequence Using Recursion
int fib_sequence2(int num) {
  if (num == 0 || num == 1) {
    return num;
  } else {
    return fib_sequence2(num - 1) + fib_sequence2(num - 2);
  }
}

int main() {
  typedef struct timeval time;
  time stop, start;
  gettimeofday(&start, NULL);

  //Time your iterative and recursive functions here.
  string sentence1, sentence2;
  cout << "\nEnter sentence 1: ";
  getline (cin, sentence1);
  cout << "Enter sentence 2: ";
  getline (cin, sentence2);
  swap_sentence(&sentence1, &sentence2);
  cout << "In main function ..." << endl;
  cout << "sentence1: " << sentence1 << endl;
  cout << "sentence2: " << sentence2 << endl;

  int n;
  cout << "\n\n\nEnter a positive integer to find the factorial: ";
  cin >> n;
  cout << "Factorial of " << n << " is " << factorial(n) << "\n";

  int fib;
  cout << "\n\n\nEnter a postive number to find the fibonacci number: ";
  cin >> fib;
  cout << "F" << fib << " = " << fib_iter(fib) << "\n";

  int fib_recursive;
  cout << "\n\nEnter a postive number to find the fibonacci number: ";
  cin >> fib_recursive;
  cout << "F" << fib_recursive << " = " << fib_recurs(fib_recursive) << "\n";

  int numOfTerms;
  cout << "\n\n\nEnter the number of terms: ";
  cin >> numOfTerms;
  cout << "Fibonacci Sequence: ";
  fib_sequence1(numOfTerms);

  int numberOfTerms, i = 0;
  cout << "\n\nEnter the number of terms: ";
  cin >> numberOfTerms;
  cout << "Fibonacci Sequence: ";
  while (i < numberOfTerms) {
    cout << " " << fib_sequence2(i);
    i++;
  }

  gettimeofday(&stop, NULL);
  if(stop.tv_sec > start.tv_sec) {
    cout << "\n\n\nSeconds: " << stop.tv_sec-start.tv_sec << endl;
  } else {
    cout << "\n\n\nMicro: " << stop.tv_usec-start.tv_usec << endl;
  }
  cout << "\n";
  return 0;
}

int factorial(int n) {
  //int factorial = 1;
  if (n == 1) {
    return 1;
  } else {
    /* for (int i = 1; i <= n; i++) {     Method 1
      factorial = factorial * i;
    }
    return factorial; */
    return n * factorial (n - 1);     // Method 2
  }
}

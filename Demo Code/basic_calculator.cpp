#include <iostream>
#include <string>

int main() {
  float value_1 = 51.0;
  int value_2 = 19;
  char value_3 = 9;
  std::string value_4("Let's do some mathematical operations!");
  
  std::cout << "\n" << value_4 << "\n\n\n";
  float var1, var2;
  std::cout << "Enter two numbers to be multiplied.\n";
  std::cout << "Please input the first number: ";
  std::cin >> var1;
  std::cout << "Please input the second number: ";
  std::cin >> var2;
  std::cout << "Multiplication Result: ";
  std::cout << var1 * var2 << "\n\n\n"; 
  
  std::cout << "\n";
  std::cout << "Enter two numbers to be added.\n";
  int num1, num2;
  std::cout << "Please enter the first number: ";
  std::cin >> num1;
  std::cout << "Please enter the second number: ";
  std::cin >> num2;
  std::cout << "Addition result: " << num1 + num2 << "\n\n\n";
  
  std::cout << "Enter two numbers to be modulo'd.\n";
  int num3, num4;
  std::cout << "Please enter the first number: ";
  std::cin >> num3;
  std::cout << "Please enter the second number: ";
  std::cin >> num4;
  std::cout << "Modulo result: " << (num3 % num4) << "\n\n\n";

  std::cout << "Enter two numbers to be divided.\n";
  int num5, num6;
  std::cout << "Please enter the first number: ";
  std::cin >> num5;
  std::cout << "Please enter the second number: ";
  std::cin >> num6;
  std::cout << "Division result: " << (num5 / num6) << "\n\n\n";

  std::cout << "Enter two numbers to be subtracted.\n";
  int num7, num8;
  std::cout << "Please enter the first number: ";
  std::cin >> num7;
  std::cout << "Please enter the second number: ";
  std::cin >> num8;
  std::cout << "Subtraction result: " << (num7 - num8) << "\n\n\n";
}
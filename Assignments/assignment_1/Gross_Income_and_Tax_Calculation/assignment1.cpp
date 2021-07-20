/*************************************************************************************
 *	Program: assignment1.cpp
 *	Author: Pranav Prabhu
 *	Date: 01/14/2021
 *	Description: This program allows a car sales person o calculate his Gross Income and the Taxes he/she need to pay based on his/her annual salary, profit, deduction, tax year, and state.
 *	Input: monthly salary, experience months, car cost, cars sold, number of misconducts, tax year, tax state
 *	Output: gross income, tax needed to pay, remaining balance
 **************************************************************************************/

#include <iostream>						// include all required libraries
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int annual_salary() {			// this function calculates the person's annual salary based on their monthly salary and number of months worked
  cout << "\nWelcome! This program will calculate your Gross Income and the Taxes you need to pay!\n\n\n";

  int monthly_salary;
  int experience_months;

  cout << "Enter your monthly salary: ";
  cin >> monthly_salary;
  while (!cin || monthly_salary < 500) {	// continously asks to enter monthly salary if there is no input, includes alphabets, or if it is less than $500
    cout << "ERROR! Please enter a number (above $500): " ;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> monthly_salary;
  }
  
  cout << "Enter number of months you worked in the past year: ";
  cin >> experience_months;
  while (!cin || experience_months < 1 || experience_months > 12) {   // continously asks to enter number of months if no input, includes alphabets, or out of range
    cout << "ERROR! Please enter the number of months between 1 and 12: " ;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> experience_months;
  }

  int annual_salary = monthly_salary * experience_months;
  cout << "Your annual salary is: $";
  
  return annual_salary;						// returns the calculated annual salary to the user
}

int profit() {							// this function calculates the person's profit
  srand(time(NULL));						// seeds the random number generator
  int sold_cars;
  int car_cost;

  cout << "Enter the cost of the car: $";
  cin >> car_cost;
  cout << "Enter number of cars you’ve sold in the past year: ";
  cin >> sold_cars;
  float avg_selling_price = car_cost + ((((rand() % 6) / 100.0) + 0.05) * car_cost);			// randomly generates a number that is 5-10% above car cost
  //float avg_selling_price = 38000;
  int profit = sold_cars * (avg_selling_price - car_cost);
  cout << "Profit: $";
  return profit;						// returns the calculated profit to the user
}

int deduction() {						// this function calculates the person's deduction based on their misconducts
  double misconducts;
  int deduction;
  cout << "Enter number of misconducts observed in the past year: ";
  cin >> misconducts;
  
  while(misconducts != static_cast< int >(misconducts)) {			// continously asks the user to input a whole number if a decimal valus is detected
    cout << "ERROR! Please enter a whole number for the number of misconducts: ";
    cin.clear();
    cin.ignore(256, '\n');
    cin >> misconducts;
  }
  
  if (misconducts == 0) {
    deduction = 0;
  } else {
    deduction = 100 * pow(2, misconducts - 1);
  }

  cout << "Deduction: $";
  return deduction;						// returns the calculated deduction amount to the user
}

int gross_income(int salary, int profit, int deduction) {			// this function calculates gross income based on salry, profit, and deduction
  double income = salary + (0.02 * profit) - deduction;
  return income;						// retuns the calculated gross income to the user
}

int calculate_taxes(int income) {				// this function calculates the taxes based on income (parameter)
  int tax_year;
  char state;
  int tax = 0;

  cout << "Which tax year are you in (enter 1 for 2017, 2 for 2018): ";
  cin >> tax_year;

  if (tax_year == 1) {						// first condition for tax year which checks if it equals 2017
    cout << "Which state are you in (enter A, B, or C): ";
    cin >> state;
    if (state == 'A'|| state == 'a') {				// first condition inside 2017 tax year which checks for state 'A'
      tax = 0.06 * income;
    } else if (state == 'B' || state == 'b') {			// second condition which checks for state 'B' to calculate tax
      if (income < 2000) {
        tax += 0;
      } else if (income >= 2000 && income <= 10000) {
        tax += 100;
      } else {
        tax += ((income - 10000) * 0.10) + 100;
      }
    } else if (state == 'C' || state == 'c') {			// third condition which checks for state 'C' to calculate tax
      int tax1 = tax;
      if (income >= 0 && income <= 3500) {
        tax += 0.05 * income;
      } else if (income > 3500 && income <= 9000) {
        tax += ((income - 3500) * 0.07) + 175;
      } else if (income > 9000 && income <= 125000) {
        tax += ((income - 9000) * 0.09) + 560;
      } else {
        tax += ((income - 125000) * 0.099) + 11000;
      }
    } else {
      cout << "Invalid state! Please retry!";
    }
  } else if (tax_year == 2) {					// second condition which checks for the tax year 2018
    cout << "You have selected 2018 as your tax year.\n";
    cout << "Which state are you in (enter A, B, or C): ";
    cin >> state;
    if (state == 'A'|| state == 'a') {				// first condition inside 2018 tax year which checks for state 'A'
      tax = 0.08 * income;
    } else if (state == 'B' || state == 'b') {			// second condition which checks for state 'B'
      if (income < 2500) {
        tax += 0;
      } else if (income >= 2500 && income <= 10000) {
        tax += 115;
      } else {
        tax += ((income - 10000) * 0.105) + 115;
      }
    } else if (state == 'C' || state == 'c') {			// third condition which checks for state 'C'
      if (income >= 0 && income <= 3450) {
        tax += 0.05 * income;
      } else if (income > 3450 && income <= 8700) {
        tax += ((income - 3450) * 0.07) + 172.5;
      } else if (income > 8700 && income <= 125000) {
        tax += ((income - 9000) * 0.09) + 540;
      } else {
        tax += ((income - 125000) * 0.099) + 11007;
      }
    } else {
      cout << "Invalid state! Please retry!";			// if bad input for state, throws error
    }
  } else {
    cout << "Invalid tax year! Please retry!";			// if bad input for year, throws error
  }

  return tax;							// returns the calculated tax value to the user
}

int main() {								// this is the main function where we call all the previous functions to produce output
  int salary = annual_salary();						// stores the returned value from annual salary function into a variable
  cout << salary << "\n\n\n";
  int proft = profit();							// stores the returned value from profit function into a variable
  cout << proft << "\n\n\n";
  int deduct = deduction();						// stores the returned value from deduction function into a variable
  cout << deduct << "\n\n\n";
  int income = gross_income(salary, proft, deduct);			// calculates gross income based on salary, profit, and deduction functions (parameters)
  int calc_tax = calculate_taxes(income);				// calculates tax based on gross income of the person
  int balance = income - calc_tax;					// calculates the remaining balance
  cout << "\n\n\nThe gross income is: $" << income << "\n";
  cout << "The tax you need to pay is: $" << calc_tax << "\n";
  cout << "Remaining: $" << balance << "\n\n\n";
  
  return 0;
}

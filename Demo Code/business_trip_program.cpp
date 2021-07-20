/***********************************************************************************************************************************
 * ** Program: business_trip_program.cpp
 * ** Author: Pranav Prabhu
 * ** Date: 1 March 2021
 * ** Description: calculates total expense and total reimbursement by a company to a businessman on an enterprise trip
 * ** Input: days on trip, departure time on first day of trip, arrival time on final day of trip, and prices of individual expenses
 * ** Output: total expense and total reimbursement from company
 **********************************************************************************************************************************/

#include <iostream>         // cin, cout, endl
#include <cstdlib>          // atoi, atof
#include <string>           // strings
#include <cmath>            // max, min
using namespace std;

bool isInteger(string str);         //determine whether or not input string is an integer

bool isDouble(string str);          // determine whether or not input string is a double

int getUserInteger(string msg, int lcon, int ucon);         //obtain an integer from the user

double getUserDouble(string msg, double lcon, double ucon);         // obtain a double from the user

int getArrivalTime(int days_of_trip, int departure_time);   // filters input of arrival time if it is on the same day as the departure time

void update_total(double &total_expense, double &total_reimbursement, double expense_to_add, double reimbursement_to_add);  // update total_expense and total_reimbursement

void cartaxi_fee(int days_of_trip, double &total_expense, double &total_reimbursement); // update total_expense and total_reimbursement with car fees

void hotel_fee(int days_of_trip, double &total_expense, double &total_reimbursement);   // update total_expense and total_reimbursement with hotel fees

void meal_fee(int days_of_trip, double departure_time, double arrival_time, double &meal_expense, double &meal_reimbursement); // calculate the total meal expense and meal reimbursement

int main() {
    bool again;         //whether or not user wants to run the program again
    do {
        double total_expense = 0;
        double total_reimbursement = 0;
        double total_meals = 0;
        double total_meal_reimbursement = 0;

        //total number of days of trip
        int days_of_trip = getUserInteger("Enter the number of days on your trip: ", 1, 14);
        cout << "\n";

        //departure time on first day and arrival time on last day
        int departure_time = getUserInteger("Enter your departure time (just the hour) on the first day in 24-hour format (0 for midnight, 23 for 11 pm): ", 0, 23);
        int arrival_time = getArrivalTime(days_of_trip, departure_time);
        cout << "\n";

        //airfare
        double total_airfare = getUserDouble("Enter total amount of airfare, in $: ", 0, 10000);
        update_total(total_expense, total_reimbursement, total_airfare, total_airfare);

        //seminar fees
        double total_seminar = getUserDouble("Enter the total cost of seminar fees, in $: ", 0, 100);
        update_total(total_expense, total_reimbursement, total_seminar, total_seminar);
        cout << "\n";

        //car and taxi fees
        cartaxi_fee(days_of_trip, total_expense, total_reimbursement);

        //hotel fees
        hotel_fee(days_of_trip, total_expense, total_reimbursement);

        //meal fees
        meal_fee(days_of_trip, departure_time, arrival_time, total_meals, total_meal_reimbursement);
        update_total(total_expense, total_reimbursement, total_meals, total_meal_reimbursement);

        cout << "Your total expense for this trip is: $" << total_expense << endl;
        cout << "Your total reimbursement for this trip is: $" << total_reimbursement << endl;
        cout << "You need to pay: $" << total_expense - total_reimbursement << endl;

        again = getUserInteger("Do you want to perform another calculation (0-no or 1-yes)? ", 0, 1);
    } while (again);

    return 0;
}

/***************************************************************************************
 * ** Function: isInteger
 * ** Description: returns true if the input string is parsable into an integer
 * ** Parameters: string str
 * ** Pre-conditions: takes string "str" to parse it into an integer
 * ** Post-conditions: determines whether or not the string is parsable into an integer
 **************************************************************************************/
bool isInteger (string str) {
    bool number = false; 

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '+' || str[i] == '-') {
            if (i > 0) return false;            // if a + or - is detected beyond the first index return false
        }
        else if (str[i] >= '0' && str[i] <= '9') number = true;         // if a number is detected, write that down
        else return false;          // if any other character is detected, return false
    }

    if (number) return true;
    return false;                   // catches edge cases like strings of length 0
}

/**************************************************************************************
 * ** Function: isDouble
 * ** Description: returns true if the input string is parsable into a double
 * ** Parameters: string str
 * ** Pre-conditions: takes string "str" to parse it into a double
 * ** Post-conditions: determines whether or not the string is parsable into an integer
 **************************************************************************************/ 
bool isDouble (string str) {
    bool number = false;
    int decimalpoint = 0;           // decimal point counter

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '+' || str[i] == '-') {
            if (i > 0) return false;            // if a + or - is detected beyond the first index return false
        }
        else if (str[i] == '.') {
            if (++decimalpoint > 1) return false;           // iterate decimal point by 1, then if it is larger than 1 return false
            number = false;         // set number to false because the most recent character is not a number
        }
        else if (str[i] >= '0' && str[i] <= '9') number = true;         // if a number is detected, write that down
        else return false;          // if any character that is not +, -, or a numeral is detected, return false
    }

    if (number) return true;
    return false;           // catches edge cases like strings of length 0
}

/**************************************************************************************************************************************************
 * ** Function: getUserInteger
 * ** Description: reads input from the user as a string, verifies that it is an integer within a certain range, and then returns it as an integer
 * ** Parameters:
 *      1. msg - a mesasge to be printed to the console to prompt the user for input
 *      2. lcon - lower bound for the double's acceptable value
 *      3. ucon - upper bound for the double's acceptable value
 * ** Pre-conditions: obtains an integer from the user
 * ** Post-conditions: returns valid integer from the user
 *************************************************************************************************************************************************/
int getUserInteger (string msg, int lcon, int ucon) {
    string in;          // input string
    int out;            // output int
    bool good;          // boolean that will be true if input string is good for output

    do {
        do {
            cout << msg;
            cin >> in;

            good = isInteger(in);           // good is true if a string is a parsable integer
            if (!good) cout << "Invalid input! Please enter an integer." << endl;
        } while (!good);            // making sure input string is an integer

        out = atoi(in.c_str());         // turning input string into integer

        good = (!(out < lcon || out > ucon));           // good is true if an integer is within constraints
        if (!good) cout << "Invalid input! Please enter a number within [" << lcon << "," << ucon << "]." << endl;
    } while (!good);            // making sure output integer is within the constraints

    return out;
}

/**********************************************************************************************************************************************
 * ** Function: getUserDouble
 * ** Description: reads input from the user as a string, verifies that it is a double within a certain range, and then returns it as a double
 * ** Parameters:
 *      1. msg - a mesasge to be printed to the console to prompt the user for input
 *      2. lcon - lower bound for the double's acceptable value
 *      3. ucon - upper bound for the double's acceptable value
 * ** Pre-conditions: the program wants to obtain a double from the user
 * ** Post-conditions: the program will have obtained a double from the user
 *********************************************************************************************************************************************/
double getUserDouble (string msg, double lcon, double ucon) {
    string in;          // input string
    double out;         // output double
    bool good;          // boolean that will be true if input string is good for output

    do {
        do {
            cout << msg;
            cin >> in;

            good = isDouble(in);            // good is true if a string is a parsable double
            if (!good) cout << "Invalid input! Please enter a double." << endl;
        } while (!good);            // making sure input string is a double

        out = atof(in.c_str());         // turning input string into double

        good = (!(out < lcon || out > ucon));           // good is true if a double is within constraints
        if (!good) cout << "Invalid input! Please enter a number within [" << lcon << ", " << ucon << "]." << endl;
    } while (!good);            // making sure output double is within the constraints

    return out;
}

/***********************************************************************************************************************************************
 * ** Function: getArrivalTime
 * ** Description: determines if there is only one day in the trip the arrival time is not before the departure time
 * ** Parameters:
 * ** Pre-conditions: days of trip and departure time have both previously been initialized and accepts input of the arrival time from the user
 * ** Post-conditions: the arrival time will have been entered by the user, and it will make logical sense
 **********************************************************************************************************************************************/
int getArrivalTime(int days_of_trip,int departure_time) {
    string msg = "Enter the arrival time (just the hour) on the final day in 24-hour format (0 for midnight, 23 for 11 pm): ";
    if (days_of_trip < 2) return getUserInteger(msg,departure_time, 23);
    return getUserInteger(msg, 0, 23);
}

/***********************************************************************************************************************************************************
 * ** Function: update_total
 * ** Description: updates the total expense and total reimbursement values
 * ** Parameters: double &total_expense, double &total_reimbursement, double expense_to_add, double reimbursement_to_add
 * ** Pre-conditions: total expense, total reimbursement, and the expense to add have previously been initialized; reimbursement to add has been calculated
 * ** Post-conditions: the total expense and total reimbursement will be updated with the expense to add and the reimbursement to add
 **********************************************************************************************************************************************************/
void update_total (double &total_expense, double &total_reimbursement, double expense_to_add, double reimbursement_to_add) {
    total_expense += expense_to_add;
    total_reimbursement += reimbursement_to_add;
}

/************************************************************************************************************************************************
 * ** Function: cartaxi_fee
 * ** Description: does multiple things:
 *       1. accepts from the user whether or not the user used a rental car or a taxi
 *       2. accepts from the user the total rental car/taxi fees for each day
 *       3. updates the total expense and reimbursement totals given that information
 * ** Parameters: int days_of_trip, double &total_expense, double &total_reimbursement
 * ** Pre-conditions: total expense, total reimbursement, and days of trip have all previously been initialized
 * ** Post-conditions: the rental car/taxi fees and reimbursements for each day will have been added to the total expense and total reimbursement
 ************************************************************************************************************************************************/
void cartaxi_fee (int days_of_trip, double &total_expense, double &total_reimbursement) {
    if (!getUserInteger("Option 0: rent a car; option 1: use a taxi during your trip -> Enter 0 or 1: ", 0, 1)) {         // car fee
        double total_rentalgas = getUserDouble("Enter your total car rental fee, including gas fee, in $: ", 0, 1000000);
        update_total(total_expense,total_reimbursement,total_rentalgas,total_rentalgas);
        cout << "\n";

        // for each day of the trip, ask for the parking fee, then update the total expense and reimbursement
        for (int i = 0; i < days_of_trip; i++) {
            cout << "Enter parking fee for day " << i + 1; 
            double parking_fee = getUserDouble(", in $: ", 0, 100);
            update_total(total_expense, total_reimbursement, parking_fee, min(parking_fee, 6.0));
        }
    }
    else {          // taxi fee
        // for each day of the trip, ask for the taxi fee, then update the total expense and reimbursement
        for (int i = 0; i < days_of_trip; i++) {
            cout << "Enter taxi fee for day " << i + 1;
            double taxi_fee = getUserDouble(", in $: ",0,1000);
            update_total(total_expense,total_reimbursement,taxi_fee,min(taxi_fee,10.0));
        }
    }

    cout << "\n";
}

/********************************************************************************************************************************************************
 * ** Function: hotel_fee
 * ** Description: accepts the hotel expenses for each night from the user and updates the total expense and reimbursement values given that information
 * ** Parameters: int days_of_trip, double &total_expense, double &total_reimbursement
 * ** Pre-conditions: total expense, total reimbursement, and days of trip have all previously been initialized
 * ** Post-conditions: the hotel fees and reimbursements for each night will have been added to the total expense and total reimbursement
 *******************************************************************************************************************************************************/
void hotel_fee (int days_of_trip, double &total_expense, double &total_reimbursement) {
    // for each day of the trip (except the last one), ask for the hotel fee, then update the total expense and reimbursement
    for (int i = 0; i < days_of_trip - 1; i++) {
        cout << "Enter hotel fee for night " << i + 1;
        double hotel_fee = getUserDouble(", in $: ",0,1000);
        update_total(total_expense,total_reimbursement,hotel_fee,min(hotel_fee,90.0));
    }
    cout << "\n";
}

/**************************************************************************************************************************************************
 * ** Function: meal_fee
 * ** Description: calculates total meal expense and meal reimbursement by asking the user for the cost of each meal each day
 * ** Parameters: int days_of_trip, double departure_time, double arrival_time, double &meal_expense, double &meal_reimbursement
 * ** Pre-conditions: days of trip, departure time, arrival time, meal expense, and meal reimbursement have all been previously initialized
 * ** Post-conditions: the meal expense and meal reimbursement totals will have been updated with the appropriate values for each meal on each day
 *************************************************************************************************************************************************/
void meal_fee (int days_of_trip, double departure_time, double arrival_time, double &meal_expense, double &meal_reimbursement) {
    for (int i = 0; i < days_of_trip; i++) {
        cout << "Day " << i + 1 << "," << endl;

        /********************************************************************************************
         * Breakfast fee is only asked for if both of the following conditions are true:
         * 1. the day is not day one, or the departure time on day 1 is at or before 7:00
         * 2. the day is not the final day, or the arrival time on the final day is at or after 8:00
         *******************************************************************************************/
        if ((i != 0 || departure_time <= 7) && (i != days_of_trip - 1 || arrival_time >= 8)) {
            double breakfast_fee = getUserDouble("Enter breakfast fee, in $: ", 0, 100);
            meal_expense += breakfast_fee;
            meal_reimbursement += min(breakfast_fee,9.0);
        }
        else cout << "Your breakfast for day " << i + 1 << " is not allowed for reimbursement." << endl;
        
        /*********************************************************************************************
         * Lunch fee is only asked for if both of the following conditions are true:
         * 1. the day is not day one, or the departure time on day 1 is at or before 12:00
         * 2. the day is not the final day, or the arrival time on the final day is at or after 13:00
         ********************************************************************************************/
        if ((i != 0 || departure_time <= 12) && (i != days_of_trip - 1 || arrival_time >= 13)) {
            double lunch_fee = getUserDouble("Enter lunch fee, in $: ", 0, 100);
            meal_expense += lunch_fee;
            meal_reimbursement += min(lunch_fee, 12.0);
        }
        else cout << "Your lunch for day " << i + 1 << " is not allowed for reimbursement." << endl;

        /*********************************************************************************************
         * Dinner fee is only asked for if both of the following conditions are true:
         * 1. the day is not day one, or the departure time on day 1 is at or before 18:00
         * 2. the day is not the final day, or the arrival time on the final day is at or after 19:00
         ********************************************************************************************/
        if ((i != 0 || departure_time <= 18) && (i != days_of_trip - 1 || arrival_time >= 19)) {
            double dinner_fee = getUserDouble("Enter dinner fee, in $: ", 0, 100);
            meal_expense += dinner_fee;
            meal_reimbursement += min(dinner_fee, 16.0);
        }
        else cout << "Your dinner for day " << i + 1 << " is not allowed for reimbursement." << endl;

        cout << "\n";
    }
}
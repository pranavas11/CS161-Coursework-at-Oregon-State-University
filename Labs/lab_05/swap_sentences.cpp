#include <iostream>
#include <string>
using namespace std;

void swap_sentence(string &sen1, string &sen2) {
  string temp = sen1;
  sen1 = sen2;
  sen2 = temp;
}

int main() {
  while (true) {
    double one_liter_to_gallons = 0.264179;
    float carALiters, carBLiters;
    float carAMiles, carBMiles;
    
    cout << "\n\n\nEnter the number of liters of gasoline consumed by Car A: ";
    cin >> carALiters;
    cout << "Enter the number of liters of gasoline consumed by Car B: ";
    cin >> carBLiters;

    double carAGallons = carALiters * one_liter_to_gallons;
    double carBGallons = carBLiters * one_liter_to_gallons;

    cout << "\n\n\nEnter the number of miles traveled by Car A: ";
    cin >> carAMiles;
    cout << "Enter the number of miles traveled by Car B: ";
    cin >> carBMiles;

    double carA_MPG = carAMiles / carAGallons;
    double carB_MPG = carBMiles / carAGallons;

    cout << "\n\n\nCar A traveled " << carA_MPG << "mpg.\n";
    cout << "Car B traveled " << carB_MPG << "mpg.\n";

    if (carA_MPG > carB_MPG) {
      cout << "\n\n\nCar A has the best fuel efficiency.\n";
    } else {
      cout << "\n\n\nCar B has the best fuel efficiency.\n";
    }

    char repeat_calculation;
    cout << "\n\n\nDo you want to repeat this calculation (y/n)? ";
    cin >> repeat_calculation;
    if (repeat_calculation == 'N' || repeat_calculation == 'n') {
      cout << "\a";
      break;
    }
  }

  string sentence1, sentence2;
  cout << "\n\n\n";
  cout << "Enter sentence 1: ";
  cin.ignore();
  getline(cin, sentence1);
  cout << "Enter sentence 2: ";
  cin.ignore();
  getline(cin, sentence2);
  swap_sentence(sentence1, sentence2);
  
  cout << "The swapped first sentence is: " << sentence1 << "\n";
  cout << "The swapped second sentence is: " << sentence2 << "\n";

  return 0;
}
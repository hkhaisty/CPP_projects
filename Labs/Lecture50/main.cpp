#include <iostream>

using namespace std;

int main() {

    const double pricePerRoom {32.50};
    const double salesTax {0.06};
    const int estimateExpiry{30}; //days

    cout << "Hello, welcome to Harry's Capet Cleaning Service" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Price per room: $" << pricePerRoom << endl;
    cout << "How many rooms would you like cleaned?" << endl;


    int numberOfRooms;
    cin >> numberOfRooms;

    cout << "\nThe amount for " << numberOfRooms << " rooms is $" << numberOfRooms * pricePerRoom;
    cout << "\nTax: $" << pricePerRoom * numberOfRooms * salesTax << endl;

    cout << "=============================================" << endl;

    cout << "Total estimate: $" << (pricePerRoom * numberOfRooms) + (pricePerRoom * numberOfRooms * salesTax) << endl;
    cout << "This estimate is valid for " << estimateExpiry << " days.";

    return 0;
}
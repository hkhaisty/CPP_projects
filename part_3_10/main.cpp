#include <iostream>
#include <math.h>
#include<iomanip>
#include "methods.h"

using namespace std;

int main() {
    mixed_number_operations first_input_value, second_input_value;

    //prompts user to enter integer part of rational number
    cout << "Enter integer part of first normal number: ";
    cin >> first_input_value.regular_number;

    //prompts user to enter integer part of complex number (minus i)
    cout << "Enter integer value of complex number(*not* including the letter i): ";
    cin >> first_input_value.complex_number;

    //prompts user to enter integer part of second rational number
    cout << "Enter integer part of second normal number: ";
    cin >> second_input_value.regular_number;

    //prompts uer to enter integer part of second complex number (minus i)
    cout << "Enter integer part of second complex number (*not* including the letter i): ";
    cin >> second_input_value.complex_number;

    //calls printing method to display results of method calls.
    first_input_value.printing_results(first_input_value, second_input_value);
}
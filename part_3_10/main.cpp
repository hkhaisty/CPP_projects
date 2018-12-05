#include <iostream>
#include <math.h>
#include<iomanip>
#include "methods.h"

using namespace std;

int main() {
    mixed_number_operations first_input_value, second_input_value, result;

    cout << "Enter integer part of first normal number: ";
    cin >> first_input_value.regular_number;

    cout << "Enter integer value of complex number(*not* including the letter i): ";
    cin >> first_input_value.complex_number;


    cout << "Enter integer part of second normal number: ";
    cin >> second_input_value.regular_number;

    cout << "Enter integer part of second complex number (*not* including the letter i): ";
    cin >> second_input_value.complex_number;

    result.printing_results(first_input_value, second_input_value, result);
    
}
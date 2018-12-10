#include <iostream>
#include "methods.h"

using namespace std;

//generic template
template<typename GenericType>

GenericType max_value(const GenericType &value1, const GenericType &value2);

int main() {

    //declare and initialize different number variable types
    int first_integer = 444, second_integer = 808;
    double first_double = 86705.3, second_double = 6789.822;

    //declare and initialize non-number variable types to pass into generic
    char first_character = 'h', second_character = 'i';
    string first_string = "hello", second_string = "world";

    //calls generic max_value with previously initialized values
    cout << max_value(first_integer, second_integer) << endl;
    cout << max_value(first_double, second_double) << endl;

    //calls generic max_value with previous initialized characters/strings
    cout << max_value(first_character, second_character) << endl;
    cout << max_value(first_string, second_string) << endl;
}



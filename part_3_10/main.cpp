#include <iostream>
#include<math.h>
#include<iomanip>

using namespace std;

class complex {
public :
    float regular_number, complex_number;

    void printNumber() {
        if (complex_number > 0) {
            cout << regular_number << "+" << complex_number << "i";
        } else {
            cout <<  regular_number << "" << complex_number << "i";
        }

    }

    void add_numbers(complex first, complex second) {
        regular_number = first.regular_number + second.regular_number;
        complex_number = first.complex_number + second.complex_number;
        if (complex_number > 0) {
            cout << regular_number << "+" << complex_number << "i";
        } else {
            cout <<  regular_number << "" << complex_number << "i";
        }

    }

    void subtract_numbers(complex one, complex two) {
        regular_number = one.regular_number - two.regular_number;
        complex_number = one.complex_number - two.complex_number;
        if (complex_number > 0) {
            cout << setprecision(2);
            cout << "Difference of the complex number is " << regular_number << "+" << complex_number << "i";
        } else {
            cout << setprecision(2);
            cout << "Difference of the complex number is " << regular_number << complex_number << "i";
        }
    }

    void multiply_numbers(complex one, complex two) {
        regular_number = one.regular_number * two.regular_number;
        complex_number = one.complex_number * two.complex_number;
        if (complex_number > 0) {
            cout << "Multiplication of the complex number is " << regular_number << "+" << complex_number << "i";
        } else {
            cout << "Multiplication of the complex number is " << regular_number << "" << complex_number << "i";
        }
    }

    void divide_numbers(complex one, complex two) {
        if (two.regular_number == 0 || two.complex_number == 0) {
            cout << "Sorry division by 0 is not possible";
        } else {
            regular_number = one.regular_number / two.regular_number;
            complex_number = one.complex_number / two.complex_number;
            if (complex_number > 0) {
                cout << "Division of the complex number is " << regular_number << "+" << complex_number << "i";
            } else {
                cout << "Division of the complex number is " << regular_number << "" << complex_number << "i";
            }
        }
    }
};

int main() {
    complex first, second, result;

    cout << "Enter real part of first complex number: ";
    cin >> first.regular_number;

    cout << "Enter integer of first complex number(*not* including the letter i): ";
    cin >> first.complex_number;

    cout << "Enter integer part of second complex number: ";
    cin >> second.regular_number;

    cout << "Enter integer part of second complex number (*not* including the letter i): ";
    cin >> second.complex_number;

    cout << endl << "The first complex number is ";
    first.printNumber();

    cout << endl << "The second complex number is ";
    second.printNumber();

    cout << endl << "The sum of the complex number is ";
    result.add_numbers(first, second);

    result.multiply_numbers(first, second);
    cout << endl << endl;

    result.subtract_numbers(first, second);
    cout << endl << endl;

    result.divide_numbers(first, second);
}
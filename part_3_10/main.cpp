#include <iostream>
#include<math.h>
#include<iomanip>

using namespace std;

class complex {
public :
    float a, b;

    void printNumber() {
        if (b > 0) {
            cout << "complex number is " << a << "+" << b << "i";
        } else {
            cout << "complex number is " << a << "" << b << "i";
        }

    }

    void sumNumbers(complex one, complex two) {
        a = one.a + two.a;
        b = one.b + two.b;
        if (b > 0) {
            cout << "Sum of the complex number is " << a << "+" << b << "i";
        } else {
            cout << "Sum of the complex number is " << a << "" << b << "i";
        }

    }

    void subtractNumbers(complex one, complex two) {
        a = one.a - two.a;
        b = one.b - two.b;
        if (b > 0) {
            cout << setprecision(2);
            cout << "Difference of the complex number is " << a << "+" << b << "i";
        } else {
            cout << setprecision(2);
            cout << "Difference of the complex number is " << a << b << "i";
        }
    }

    void multiplyNumbers(complex one, complex two) {
        a = one.a * two.a;
        b = one.b * two.b;
        if (b > 0) {
            cout << "Multiplication of the complex number is " << a << "+" << b << "i";
        } else {
            cout << "Multiplication of the complex number is " << a << "" << b << "i";
        }
    }

    void divideNumbers(complex one, complex two) {
        if (two.a == 0 || two.b == 0) {
            cout << "Sorry division by 0 is not possible";
        } else {
            a = one.a / two.a;
            b = one.b / two.b;
            if (b > 0) {
                cout << "Division of the complex number is " << a << "+" << b << "i";
            } else {
                cout << "Division of the complex number is " << a << "" << b << "i";
            }
        }
    }
};

int main() {
    complex first, second, result;

    cout << "Enter real part of first complex number: ";
    cin >> first.a;
    cout << "Enter imaginary part of first complex number: ";
    cin >> first.b;

    cout << "Enter real part of second complex number: ";
    cin >> second.a;
    cout << "Enter imaginary part of second complex number: ";
    cin >> second.b;

    cout << endl << "First ";
    first.printNumber();

    cout << endl << "Second ";
    second.printNumber();

    cout << endl;
    cout << endl;

    result.sumNumbers(first, second);
    cout << endl << endl;

    result.multiplyNumbers(first, second);
    cout << endl << endl;

    result.subtractNumbers(first, second);
    cout << endl << endl;

    result.divideNumbers(first, second);

}
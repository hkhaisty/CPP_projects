using namespace std;

class mixed_number_operations {

public :
    float regular_number, complex_number;

    void printNumber() {
        if (complex_number > 0) {
            cout << regular_number << "+" << complex_number << "i";
        } else {
            cout << regular_number << "" << complex_number << "i";
        }
    }

    void add_numbers(mixed_number_operations first, mixed_number_operations second) {
        regular_number = first.regular_number + second.regular_number;
        complex_number = first.complex_number + second.complex_number;
        if (complex_number > 0) {
            cout << regular_number << "+" << complex_number << "i";
        } else {
            cout << regular_number << "" << complex_number << "i";
        }
    }

    void subtract_numbers(mixed_number_operations one, mixed_number_operations two) {
        regular_number = one.regular_number - two.regular_number;
        complex_number = one.complex_number - two.complex_number;
        if (complex_number > 0) {
            cout << setprecision(2);
            cout << regular_number << "+" << complex_number << "i";
        } else {
            cout << setprecision(2);
            cout << regular_number << complex_number << "i";
        }
    }

    void multiply_numbers(mixed_number_operations one, mixed_number_operations two) {
        regular_number = one.regular_number * two.regular_number;
        complex_number = one.complex_number * two.complex_number;
        if (complex_number > 0) {
            cout << regular_number << "+" << complex_number << "i";
        } else {
            cout << regular_number << "" << complex_number << "i";
        }
    }

    void divide_numbers(mixed_number_operations one, mixed_number_operations two) {
        if (two.regular_number == 0 || two.complex_number == 0) {
            cout << "Sorry division by 0 is not possible";
        } else {
            regular_number = one.regular_number / two.regular_number;
            complex_number = one.complex_number / two.complex_number;
            if (complex_number > 0) {
                cout << regular_number << "+" << complex_number << "i";
            } else {
                cout << regular_number << "" << complex_number << "i";
            }
        }
    }

    void printing_results(mixed_number_operations first_value, mixed_number_operations second_value, mixed_number_operations result) {

        cout << endl << "1. The FIRST complex number is: ";
        first_value.
                printNumber();

        cout << endl << "2. The SECOND complex number is: ";
        second_value.
                printNumber();

        cout << endl << "3. The SUM of the complex numbers is: ";
        result.
                add_numbers(first_value, second_value);

        cout << endl << "4. The MULTIPLICATION of the complex numbers is: ";
        result.
                multiply_numbers(first_value, second_value);

        cout << endl << "5. The SUBTRACTION of the complex number is: ";
        result.
                subtract_numbers(first_value, second_value);

        cout << endl << "6. The DIVISION of the complex numbers is: ";
        result.
                divide_numbers(first_value, second_value);

        cout << endl;
    }
};

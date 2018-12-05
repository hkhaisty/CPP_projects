#include <iostream>
#include <array>

using namespace std;

void disjoint(int array[]) {

}

int main() {

    int array_size_1;
    int array_size_2;
    int myarray[0];

    cout << "Enter an array size: ";
    cin >> array_size_1;

    int first_array[array_size_1];
    int user_input;

    for (int i = 0; i < array_size_1; i++) {
        cout << array_size_1 - i << " spaces left. Enter a value: ";
        cin >> user_input;
        first_array[i] = user_input;
    }

    cout << "Your first set is now complete! Let's do another, shall we? \n";
    cout << "Enter an array size: ";

    cin >> array_size_2;
    cout << endl;

    int second_array[array_size_2];

    for (int i = 0; i < array_size_2; i++) {
        cout << array_size_2 - i << " spaces left. Enter a value: ";
        cin >> user_input;
        second_array[i] = user_input;
    }

    for (int i = 0; i <= array_size_1; i++) {
        cout << first_array[i] << " ";
    }

    for (int i = 0; i <= array_size_2; i++) {
        cout << second_array[i] << " ";
    }
}
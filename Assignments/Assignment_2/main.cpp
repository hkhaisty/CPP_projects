#include <iostream>

using namespace std;

//make the type long long to accomodate the large factorial values
long long factorial(long long n) {
    //the factorial value only goes to 1, if it were multiplied by 0 then the whole value would be 0
    if (n > 1)
        //recursively decrement the value of n and multiply
        return n * factorial(n - 1);
    else
        //if the input value is 1 or less, return just the value "1"
        return 1;
}

int main() {
    //declare user input as type long long
    long long user_input;

    //prompt user to input value
    cout << "Enter an integer: ";
    //take in user input value
    cin >> user_input;

    //print out recursive call to factorial method
    cout << factorial(user_input) << endl;
}
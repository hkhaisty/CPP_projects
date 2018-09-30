#include <iostream>

using namespace std;

//works similarly to the factorial method
int sum(int n) {
    //n must be above 0, otherwise the loop will continue negatively forever
    if (n > 0)
        return n + sum(n - 1);

        //if n is less than or equal to 0, return the value 0.
        // if you return 1, then 1 will be added to the final sum value
    else
        return 0;
}

int main() {
    //declare user input
    int user_input = 0;

    //prompt user input
    cout << "Enter an integer: ";
    //accept user input and initialize user input value
    cin >> user_input;

    //call recursive function with user input value
    cout << sum(user_input);
}
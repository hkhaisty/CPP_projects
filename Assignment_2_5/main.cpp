#include <iostream>

using namespace std;

string reverse_string(string input, string reverse, int n) {
    //base case, return empty string
    if (n == 0)
        return "";

    //reverse elements, append individual elements to new string
    return reverse += input.back() + reverse_string(input.substr(0, n - 1), reverse, n - 1);
}

int main() {
    //declare user input
    string user_input;

    //prompt user for input
    cout << "Enter a string: ";
    //accept user input
    cin >> user_input;

    //print out the reverse of the string by calling recursive function
    cout << reverse_string(user_input, "", user_input.length()) << endl;
}
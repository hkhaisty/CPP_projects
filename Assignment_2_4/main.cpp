#include <iostream>

using namespace std;

//return boolean value to user to show if palindrome value is true or not
bool is_palindrome(const string &str, int first_value, int last_value) {
    //if first and last values left are equal, return true
    if (first_value >= last_value)
        return true;
    //if the first and last values left are not equal, return false
    if (str[first_value] != str[last_value])
        return false;
    //increment first value and decrement last value to evaluate against eachother
    return is_palindrome(str, ++first_value, --last_value);
}

int main() {
    //declare user input value
    string user_string;

    //prompt user to enter a string
    cout << "enter a string: ";
    //initialize user input value
    cin >> user_string;

    //print output based on returned value from recursive function
    if (is_palindrome(user_string, 0, user_string.length() - 1) == 1)
        cout << user_string << " is a palindrome.";
    else
        cout << user_string << " is not a palindrome";
}
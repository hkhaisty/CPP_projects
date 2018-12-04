#include <iostream>

using namespace std;

//have this method changed to void, since we are printing within the method
void reverse(string list[], int size) {
    //hard-coded value persists from original code
    string result[6];
    //this for loop replaces each index value of result with the opposite value
    for (int i = 0, j = size - 1; i < size; i++, j--)
        result[j] = list[i];

    //this for loop I wrote iterates through the array, printing each value followed by a space
    for (int j = 0; j < 6; j++)
        cout << result[j] << " ";
}

//changed the value type from int to string
void printArray(string list[], int size) {
    //this code still has its original functionality
    for (int i = 0; i < size; i++)
        cout << list[i] << " ";
}

int main() {
    //changed list array types to string values instead of integers
    //now this code works with not just numbers, but strings and characters too
    //integer values can be parsed out of the array
    string list[] = {"1", "2", "3", "4", "5", "6"};
    printArray(list, 6);
    cout << endl;
    //regular method call instead of assigning value to p
    reverse(list, 6);
    cout << endl;
}
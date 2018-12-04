#include <iostream>
using namespace std;

int main()
{
    int count = 5;
    int* pCount = &count;

    cout << "The value that is stored: " << count << endl;
    cout << "The value in memory that count is stored: " << &count << endl;
    cout << "Another value in memory that count is stored: " << pCount << endl;
    cout << "Calling the value at the location using an asterisk: " << *pCount << endl;
}
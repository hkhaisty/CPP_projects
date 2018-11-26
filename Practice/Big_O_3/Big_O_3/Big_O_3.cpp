// Big_O_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int gcd(int m, int n)
{
	if (m % n == 0)
		return n;
	else
		return gcd(n, m % n);
}

int main()
{
	int user_input1;
	int user_input2;

	cout << "Enter your larger integer: ";
	cin >> user_input1;

	cout << "Enter your next, smaller integer: ";
	cin >> user_input2;
    
	cout << gcd(user_input1, user_input2);

	cin.get(); 
	cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

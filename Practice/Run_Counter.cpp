// Big_o_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	int sum = 0;

	cout << "Enter a positive integer: ";
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n * n; j++)
			sum++;

	cout << "I ran " << sum << " times!" << endl;
	cout << "Press 'ENTER' to exit.";
	cin.get();
	cin.get();
}


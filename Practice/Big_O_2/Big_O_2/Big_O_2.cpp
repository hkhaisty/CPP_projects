// Big_O_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;
int counter = 0;

long fib(long index)
{

	if (index == 0) {
		counter++;
		return 0;
	}
	else if (index == 1) {
		counter++;
		return 1;
	}
	else {
		counter++;
		return fib(index - 1) + fib(index - 2);
	}
}

int main()
{
	long fib_index;
	cout << "Enter an integer: ";
	cin >> fib_index;

	cout << "the value at place " << fib_index << " is: " << fib(fib_index) << endl;
	cout << "the value of cycles is: " << counter; 

	cin.get();
	cin.get();
}




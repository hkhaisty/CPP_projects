// Big_O_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

long fib(long index)
{
	if (index == 0) // Base case
		return 0;
	else if (index == 1) // Base case
		return 1;
	else  // Reduction and recursive calls
		return fib(index-1) + fib(index-2);
}


int main()
{
	long fib_index = 1000000000;
	cout << fib(fib_index);

	cin.get();
	cin.get();
}




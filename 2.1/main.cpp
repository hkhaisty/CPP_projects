///////////////// Program 2.1
#include <iostream>
using namespace std;

const int SIZE = 4;


void printArray(int list[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << list[i] <<  " ";
    }
	cout << "\n";
}

void reverse(const int list[], int newList[], int size)
{
    for (int i = 0, j = size - 1; i < size; i++, j--)
    {
        newList[j] = list[i];
    }
}

void p(int list[], int arraySize)
{
    list[0] = {arraySize};
}

int main()
{
    SIZE;
    int newList[SIZE];
    int numbers[] = {1, 4, 3, 6, 8};
    p(numbers, 5);
    printArray(numbers, 5);
    reverse(numbers, newList, SIZE);
    printArray(newList, SIZE);

    return 0;
}



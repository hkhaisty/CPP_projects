#include <iostream>
using namespace std;
//this code works as intended, so I made no modifications
int* reverse(const int* list, int size)
{
    int* result = new int[size];
    for (int i = 0, j = size - 1; i < size; i++, j--)
    {
        result[j] = list[i];
    }
    return result;
}
void printArray(const int* list, int size)
{
    for (int i = 0; i < size; i++)
        cout << list[i] << " ";
}
int main()
{
    int list[] = {1, 2, 3, 4, 5, 6};
    printArray(list, 6);
    cout << endl;
    int* p = reverse(list, 6);
    printArray(p, 6);
    cout << endl;
    return 0;
}
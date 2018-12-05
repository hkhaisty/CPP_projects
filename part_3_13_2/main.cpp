#include <iostream>
using namespace std;

//set constant integer as sentinal value 1000
static const int N = 1000;

//struct SinglyLinkedList
//{
//    for (i = 2; i < N; i++)
//};


int main()
{





    //initialize array
    int i, a[N];

    //loop through array starting with the 2nd element
    for (i = 2; i < N; i++) a[i] = 1;

    //loop through array
    for (i = 2; i < N; i++)
        if (a[i])
            //set int j to int i value, multiply j by i until it reaches 1000, set element at i*j to 0
            for (int j = i; j*i < N; j++) a[i*j] = 0;
    //loop through populated array
    for (i = 2; i < N; i++)
        if (a[i]) cout << " " << i;
    cout << endl;
}
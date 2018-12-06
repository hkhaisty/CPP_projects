#include <iostream>

using namespace std;

int main()
{
    int i;
    const int N = 9, M = 5;

    //declare array of constant value 9
    int nodes[N];

    //populate array
    for (i = 0; i < N; i++)
    {
        nodes[i] = i + 1;
    }

    //declare index as 8, and array size to be 9
    int index = N - 1, arr_size = N;

    //set conditional for while loop to hinge on array size
    while (arr_size > 1)
    {
        //set conditional for for loop, iterate and compare index to array size
        for (i = 1; i < M; i++)
        {
            index++;
            if (index >= arr_size)
            {
                index = 0;
            }
        }

        //declare and initialize start to index value + 1
        int start = index + 1;
        if (start == arr_size)
        {
            start = 0;
        }

        //set conditional for swapping ndoes
        for (i = start; i < arr_size - 1; i++)
        {
            //invoke swap function for node at i and node at i+1
            swap(nodes[i], nodes[i + 1]);
        }

        //decrement array size
        arr_size -= 1;
    }

    //print head value of array
    cout << nodes[0] << endl;
}
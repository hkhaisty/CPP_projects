#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include "methods.h"
using namespace std;

typedef chrono::high_resolution_clock Clock;

int main() {


    //include standard clock
    auto start_bubble_sort = Clock::now();


    //read in .csv file
    //implement bubble_sort here
    auto end_bubble_sort = Clock::now();


    //include standard clock end
    //calculate runtime for bubble sort

    //double bubbble_sort_runtime = (double)(end_bubble_sort - start_bubble_sort);

    cout << "Bubble sort runtime: " << chrono::duration_cast<chrono::nanoseconds>(end_bubble_sort - start_bubble_sort).count() << " nanoseconds." << endl;

    //include standard clock
    //read in .csv file again

    //implement merge sort here

    //include standard clock end
    //end clock time

    cout << "the runtime for bubble sort is : [add bubble sort time]\n";
    cout << "the runtime for merge sort is: [add merge sort time]";

}
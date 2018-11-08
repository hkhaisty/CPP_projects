#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include "methods.h"
using namespace std;

typedef chrono::high_resolution_clock Clock;


int main() {


   //start chrono clock and save time
    auto start_bubble_sort = Clock::now();
    //parse CSV to make array
    void parseCSV();
    //implement bubble sort method
    void bubble_sort();
    //end chrono clock and save time
    auto end_bubble_sort = Clock::now();

    //start chrono merge clock
    auto start_merge_sort = Clock::now();
    //parse CSV to make array
    void parseCSV();
    //implement merge sort algorithm
    void merge_sort();
    //end chrono clock and save time
    auto end_merge_sort = Clock::now();

    //start chrono clock and save time
    auto start_quick_sort = Clock::now();
    //parse CSV for array
    void parseCSV();
    //implement quick sort array
    void quick_sort();
    //end clock and save time
    auto end_quick_sort = Clock::now();

    //print out end time minus start time to calculate nanoseconds taken to run
    cout << "Bubble sort runtime: " << chrono::duration_cast<chrono::nanoseconds>(end_bubble_sort - start_bubble_sort).count() << " nanoseconds.\n" << endl;
    cout << "Merge sort runtime: " << chrono::duration_cast<chrono::nanoseconds>(end_merge_sort - start_merge_sort).count() << " nanoseconds.\n" << endl;
    cout << "Quick sort runtime: " << chrono::duration_cast<chrono::nanoseconds>(end_quick_sort - start_quick_sort).count() << " nanoseconds.\n" << endl;
}
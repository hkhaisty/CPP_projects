#include <iostream>
#include <algorithm>
#include <ctime>
#include "array_generator.h"
#include <chrono>
#include "methods.h"
using namespace std;

typedef chrono::high_resolution_clock Clock;

const int array_size1 = 20;
int array_1[array_size1];

const int array_size2 = 1000;
int array_2[array_size2];

const int array_size3 = 100000;
int array_3[array_size3];

int main() {

    int first_array[20] = random_array_1();
    int second_array[array_size2] = random_array_2;
    int third_array[array_size3] = random_array_3();

    //start chrono clock and save time
    auto start_bubble_sort = Clock::now();
    void bubble_sort(first_array);
    //end chrono clock and save time
    auto end_bubble_sort = Clock::now();




    //print out end time minus start time to calculate nanoseconds taken to run
    cout << "Bubble sort runtime: " << chrono::duration_cast<chrono::nanoseconds>(end_bubble_sort - start_bubble_sort).count() << " nanoseconds.\n" << endl;
    // cout << "Merge sort runtime: " << chrono::duration_cast<chrono::nanoseconds>(end_merge_sort - start_merge_sort).count() << " nanoseconds.\n" << endl;
    //cout << "Quick sort runtime: " << chrono::duration_cast<chrono::nanoseconds>(end_quick_sort - start_quick_sort).count() << " nanoseconds.\n" << endl;
}
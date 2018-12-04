#include <iostream>
#include <algorithm>
#include <ctime>
#include "array_generator.h"
#include <chrono>
#include "methods.h"
using namespace std;

typedef chrono::high_resolution_clock Clock;



int main() {

    int first_array[20] = random_array_1();
    int second_array[array_size2] = random_array_2;
    int third_array[array_size3] = random_array_3();

   //start chrono clock and save time
    auto start_bubble_sort = Clock::now();
    static void bubble_sort(first_array);
    //end chrono clock and save time
    auto end_bubble_sort = Clock::now();




    //print out end time minus start time to calculate nanoseconds taken to run
    cout << "Bubble sort runtime: " << chrono::duration_cast<chrono::nanoseconds>(end_bubble_sort - start_bubble_sort).count() << " nanoseconds.\n" << endl;
   // cout << "Merge sort runtime: " << chrono::duration_cast<chrono::nanoseconds>(end_merge_sort - start_merge_sort).count() << " nanoseconds.\n" << endl;
    //cout << "Quick sort runtime: " << chrono::duration_cast<chrono::nanoseconds>(end_quick_sort - start_quick_sort).count() << " nanoseconds.\n" << endl;
}
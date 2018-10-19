#include <iostream>
#include <chrono>
#include <numeric>
#include <vector>

using namespace std;
static const int N = 1000;

int main() {
    for (auto size = 1ull; size < 1000000000ull; size *= 100) {
        // record start time
        auto start = std::chrono::system_clock::now();
        int i;
        char a[N];
        for (int i = 2; i < N; i++) a[i] = 1;
        for (i = 2; i < N; i++)
            if (a[i])
                for (int j = i; j * i < N; j++) a[i * j] = 0;

        auto start_2 = std::chrono::system_clock::now();

        // record end times
        auto end = std::chrono::system_clock::now();
        auto end_2 = std::chrono::system_clock::now();

        //calculate differences in time
        std::chrono::duration<double> diff = end - start;
        std::chrono::duration<double> diff_2 = end_2 - start_2;

        //print out differences
        std::cout << "First 2 For Loops:  " << size << " ints : " << diff.count() << " s\n";
        std::cout << "Third For Loop:  " << size << " ints : " << diff_2.count() << "s\n";
    }
}
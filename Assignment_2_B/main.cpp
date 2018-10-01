#include <iostream>
#include <chrono>

using namespace std;

long sum;

long iterative_sum(int n) {
    for (int i = 0; i < n; ++i)
        sum += i;
}

long recursive_sum(int n) {
    if (n > 0)
        n + recursive_sum(n - 1);
}

int main() {
    int user_input = 0;
    typedef std::ratio<1l, 1000000000000l> pico;

    cout << "Enter an integer: ";
    cin >> user_input;

    auto start = chrono::steady_clock::now();
    iterative_sum(user_input);
    auto end = chrono::steady_clock::now();

    chrono::duration<double, std::pico> elapsed_time = (end - start);
    cout << elapsed_time.count() << " picoseconds" << endl;

    start = chrono::steady_clock::now();
    recursive_sum(user_input);
    end = chrono::steady_clock::now();

    chrono::duration<double, std::pico> elapsed_time_2 = (end - start);
    cout << elapsed_time_2.count() << " picoseconds";
}

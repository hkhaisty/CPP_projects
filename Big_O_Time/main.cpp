#include <iostream>
#include <time.h>
#include <chrono>

using namespace std;

// problem b method
long fib(long index) {
    if (index == 0)
        return 0;
    else if (index == 1)
        return 1;
    else
        return fib(index - 1) + fib(index - 2);
}

// includes for loops from problem a in a method
void for_loops_a(int n_a, int sum_a) {
    for (int i = 0; i < n_a; i++)
        for (int j = 0; j < n_a * n_a; j++)
            sum_a++;
}

// problem c method
int greatest_common_denominator(int m, int n) {
    if (m % n == 0)
        return n;
    else
        return greatest_common_denominator(n, m % n);
}

int main() {
    // problem a code

    int main_method_n_for_problem_a = 1000;
    int sum_of_a_preacher_man = 0;

    while (main_method_n_for_problem_a != 0) {

        auto start = std::chrono::system_clock::now();
        cout << "Enter an integer: ";
        cin >> main_method_n_for_problem_a;

        for_loops_a(main_method_n_for_problem_a, sum_of_a_preacher_man);

        auto end = std::chrono::system_clock::now();
        auto elapsed = end - start;

        std::cout << elapsed.count() << '\n';
    }

    cin.get();
    cin.get();

    // problem b code

    // problem c code

    // problem d code
    int main_method_n_for_problem_d;
    int sum_of_cycles_problem_d = 0;

    for (int i = 0; i < main_method_n_for_problem_d; i++)
        for (int j = 0; j < i * i; j++)
            for (int k = 0; k < j; k++)
                sum_of_cycles_problem_d++;

    // problem e code
    int main_method_n_for_problem_e;
    int sum_of_cycles_problem_e;

    for (int i = 1; i < main_method_n_for_problem_e; i++)
        for (int j = 1; j < i * i; j++)
            if (j % i == 0)
                for (int k = 0; k < j; k++)
                    sum_of_cycles_problem_e++;


}
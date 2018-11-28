#include <iostream>
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

void for_loops_d(int n_d, int sum_d) {
    for (int i = 0; i < n_d; i++)
        for (int j = 0; j < i * i; j++)
            for (int k = 0; k < j; k++)
                sum_d++;
}

void for_loops_e(int n_e, int sum_e) {
    for (int i = 1; i < n_e; i++)
        for (int j = 1; j < i * i; j++)
            if (j % i == 0)
                for (int k = 0; k < j; k++)
                    sum_e++;
}

// problem c method
int greatest_common_denominator(int m, int n) {
    if (m % n == 0)
        return n;
    else
        return greatest_common_denominator(n, m % n);
}

int main() {

    // problem a code*****************************************************************

    cout << "Hi there, Harriet here. Here is problem a\n";
    int main_method_n_for_problem_a = 1000;
    int sum_of_a_preacher_man = 0;

    while (main_method_n_for_problem_a != 0) {

        //prompt user to enter integer
        cout << "Enter an integer, enter 0 to exit: ";
        cin >> main_method_n_for_problem_a;

        //start the high resolution clock
        auto start = std::chrono::high_resolution_clock::now();

        //function call to prewritten for loops for question a
        for_loops_a(main_method_n_for_problem_a, sum_of_a_preacher_man);

        //end the high resolution clock
        auto end = std::chrono::high_resolution_clock::now();

        //subtract initial value from final clock value
        auto elapsed = (end - start);
        auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        std::cout << "This loop took " << elapsed.count() << " microseconds, "
                  << "or " << int_ms.count() << " whole milliseconds to run.\n";
    }

    // problem b code*****************************************************************

    // problem c code*****************************************************************

    // problem d code*****************************************************************
    int main_method_n_for_problem_d;
    int sum_of_cycles_problem_d = 0;

    cout << "Welcome to problem d!\n";

    while (main_method_n_for_problem_d != 0) {

        cout << "Enter an integer, enter 0 to exit: ";
        cin >> main_method_n_for_problem_d;
        auto start = std::chrono::high_resolution_clock::now();
        for_loops_d(main_method_n_for_problem_d, sum_of_cycles_problem_d);
        auto end = std::chrono::high_resolution_clock::now();

        auto elapsed = (end - start);
        auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        std::cout << "This loop took  " << elapsed.count() << " microseconds, or " << int_ms.count()
                  << " whole milliseconds to run. \n";
    }

    // problem e code*****************************************************************
    int main_method_n_for_problem_e;
    int sum_of_cycles_problem_e;

    cout << "This is the beginning of problem e. The final problem.\n";

    while (main_method_n_for_problem_e != 0) {
        cout << "Enter an integer, enter 0 to exit: ";
        cin >> main_method_n_for_problem_e;

        auto start = std::chrono::high_resolution_clock::now();

        for_loops_e(main_method_n_for_problem_e, sum_of_cycles_problem_e);

        auto end = std::chrono::high_resolution_clock::now();

        auto elapsed = (end - start);

        auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        std::cout << "This loop took " << elapsed.count() << " microseconds, or " << int_ms.count() << " whole milliseconds to run. \n";
    }

    cout << "\nOur revels have now ended.";
}
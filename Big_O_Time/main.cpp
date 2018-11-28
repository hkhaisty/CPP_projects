#include <iostream>
#include <time.h>

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

float make_a_clock(time_t t, int NA, int SUMA) {

    t = clock();

    for_loops_a(NA, SUMA);

    printf("It took me %d clicks (%f seconds).\n", t, ((float) t) / CLOCKS_PER_SEC);

}

// problem c method
int gcd(int m, int n) {
    if (m % n == 0)
        return n;
    else
        return gcd(n, m % n);
}

int main() {
    // problem a code

    int NA = 1000;
    int SUMA = 0;

    while (NA != 0) {
        time_t t;
        cout << "Enter an integer: ";
        cin >> NA;

        make_a_clock(t, NA, SUMA);
    }

    cin.get();
    cin.get();

    // problem b code

    // problem c code

    // problem d code
    int n_d;
    int sum_d = 0;

    for (int i = 0; i < n_d; i++)
        for (int j = 0; j < i * i; j++)
            for (int k = 0; k < j; k++)
                sum_d++;

    // problem e code
    int n_e;
    int sum_e;

    for (int i = 1; i < n_e; i++)
        for (int j = 1; j < i * i; j++)
            if (j % i == 0)
                for (int k = 0; k < j; k++)
                    sum_e++;


}
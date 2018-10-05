#include <array>
#include <iostream>

static const int N = 1000;
using namespace std;

int main() {
    int i, a[N];

    for (i = 2; i < N; i++) {
        a[i] = 1;
    }

    for (i = 2; i < N; i++) {
        if (a[i]) {
            for (int j = i; j * i < N; j++) {
                a[i * j] = 0;
            }
        }
    }

    int count = 0;
    for (i = 2; i < N; i++) {
        if (a[i]) {
            printf("%-5d", i);
            count++;
        }
        if (count / 10 == 1) {
            cout << endl;
            count = 0;
        }
    }

    cout << endl;
}



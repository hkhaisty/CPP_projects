#include <iostream>

using namespace std;

int fibbonacci_sequence(int n) {

    //declares and initializes num1 and num2 values to 0 and 1 so that program doesn't hang
    int num1 = 0, num2 = 1;

    //stops loop if n is smaller than threshold
    if (n < 1)
        return n;

    //loops through to user input value
    for (int i = 1; i < n; i++) {
        //prints value
        printf("%d", num2, " ");
        //sets next to sum of first two integers, per the fibonacci sequence
        int next = num1 + num2;
        //sets smaller num1 to larger num2
        num1 = num2;
        //sets num2 to larger number
        num2 = next;
    }
}

int main() {

    //declares integer N
    int N;

    //prompts user to set integer N to value
    cout << "Enter an integer value: ";
    //sets integer N to user value
    cin >> N;

    //prints out call to fibonacci sequence
    cout << fibbonacci_sequence(N);
}
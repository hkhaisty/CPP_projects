#include <iostream>
using namespace std;

//recursive function
int n_sum(int n) {

    //checks to see if number is equal to 0
    if (n != 0)
        return n + n_sum(n - 1);
    //if n is 0, just return 0
    else
        return n;
}

int main() {

    //declares int N
    int N;
    //prompts user to initialize int N
    cout << "Enter an integer number: ";

    //accepts user value for int N
    cin >> N;

    //prints out call to recursive function n_sum
    cout << n_sum(N) << endl;
}


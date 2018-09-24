#include <iostream>

using namespace std;

int main() {
    //remove constant from integers so they are malleable.
    //remove *'s and &'s so that value is not accessing actual location
    //initializes num1, num2, and num3 to 1, 2, and 3
    int num1 = 1, num2 = 2, num3 = 3;

    //sets p1, p2, and p3 to initialized values of num1, num2, and num3
    int p1 = num1;
    int p2 = num2;
    int p3 = num3;

    //sets num1, num2, and num3 to 11, 22, and 33 respectively
    num1 = 11;
    num2 = 22;
    num3 = 33;

    //prints out values of num1, num2, and num3 with a space between the values
    cout << num1 << " " << num2 << " " << num3 << endl;

    //prints out p1, p2, and p3, which are the original values of num1, num2, and num3. Twice.
    cout << p1 << " " << p2 << " " << p3 << endl;
    cout << p1 << " " << p2 << " " << p3 << endl;

    //sets each value to the next one, so p1 and p3 end up being the same number.
    p1 = p2;
    p2 = p3;
    p3 = p1;

    //prints num1, num2, and num3, which haven't changed since the last printout.
    cout << num1 << " " << num2 << " " << num3 << endl;

    //prints out newly assigned values of p1, p2, and p3
    cout << p1 << " " << p2 << " " << p3 << endl;
    cout << p1 << " " << p2 << " " << p3 << endl;

    //sets p2 to 22
    p2 = 22;

    //sets p1 to 22
    p1 = p2;

    //sets p2 to 2
    p2 = p3;

    //sets p3 to 22
    p3 = p1;

    //prints num1, num2, and num3, which haven't changed since the last printout.
    cout << num1 << " " << num2 << " " << num3 << endl;

    //prints out 22, 2, and 22, The newly assigned values of p1, p2, and p3
    cout << p1 << " " << p2 << " " << p3 << endl;

    //prints it out again
    cout << p1 << " " << p2 << " " << p3 << endl;
}

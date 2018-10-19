#include <iostream>
using namespace std;
int main() {
    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;
    int count_3 = 0;

    int user_input;

    while (user_input != 9) {
        cin >> user_input;
        if (user_input == 0){
            count_0++;
        }
        else if(user_input == 1){
            count_1++;
        }
        else if(user_input == 2){
            count_2++;
        }
        else if(user_input == 3) {
            count_3++;
        }
    }
    cout << " # of 0's: " << count_0;
    cout << ", # of 1's: " << count_1;
    cout << ", # of 2's: " << count_2;
    cout << ", # of 3's: " << count_3;
}
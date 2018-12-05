#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_methods(vector<int> vector_1, int user_int) {
    //call built-in make_heap function using beginning and end of vector
    make_heap(vector_1.begin(), vector_1.end());
    //call front value of heap and print
    cout << "\n1. First max heap: " << vector_1.front() << "\n";

    //pop front value of heap to get rid of old max value
    pop_heap(vector_1.begin(), vector_1.end());
    vector_1.pop_back();
    cout << "\n2. Second max heap (after pop): " << vector_1.front() << "\n";

    //prompt user to enter value to push onto heap
    cout << "\n3. Enter a value to push onto heap: ";
    cin >> user_int;
    vector_1.push_back(user_int);
    push_heap(vector_1.begin(), vector_1.end());

    //print out new value after last push
    cout << "\n4. New max heap after push: " << vector_1.front() << "\n";

    //call sorting function for heap
    sort_heap(vector_1.begin(), vector_1.end());
    cout << "\n5. Final sorted heap (ascending order): ";

    //prints formatted list of sorted heap
    for (unsigned i = 0; i < vector_1.size(); i++)
        cout << ' ' << vector_1[i];

    sort_heap(vector_1.end(), vector_1.begin());
    cout << "\n6. Final sorted heap (descending order): ";

    for (unsigned i = vector_1.size(); i > 0; i--)
        cout << ' '  << vector_1[i];

    cout << '\n';
}

int main() {
    int user_integer;
    int array_size;

    //accepts user input to make array size
    cout << "Please indicate size of array: ";
    cin >> array_size;

    //declares and initializes array with user-defined size
    int my_ints[array_size];

    //loops through adding user values to array
    for (int i = 0; i <= array_size; i++) {

        //prompts user to enter integer value to populate array
        cout << "Please enter integer value at place " << i << ":";
        //accepts user integer
        cin >> user_integer;
        //places input at index in array
        my_ints[i] = user_integer;
    }

    //declare and initialize int vector
    std::vector<int> vector(my_ints, my_ints + 5);

    //call print methods logic
    print_methods(vector, user_integer);
}
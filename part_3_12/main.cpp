//deque Demo
#include <iostream>
#include <list>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

//creates standard template
template<class T>

void printDeque(const deque<T> &lst, string s) {
    //prints formatting for output
    cout << s << ": ";
    //calls generic template type at first index
    typename deque<T>::const_iterator i = lst.begin();
    //iterates through templated input
    for (; i != lst.end(); i++)
        //outputs addressed value
        cout << *i << ' ';
    cout << endl;
}

int main() {
    //call template
    deque<int> dq1;

    //push value 1 to front of deque {1}
    dq1.push_front(1);

    //push value 2 to front of deque {2, 1}
    dq1.push_front(2);

    //push value 3 to back of deque {2, 1, 3}
    dq1.push_back(3);

    //push value 4 to back of deque {2, 1, 3, 4}
    dq1.push_back(4);

    //prints out deque so far and "dql" identifier
    printDeque(dq1, "dq1");

    //calls generic template type with int
    deque<int> dq2(dq1.begin() + 1, dq1.end() - 1);

    //sets value at index 1 to 5
    dq1[1] = 5;

    //erases value at beginning of deque
    dq1.erase(dq1.begin());

    //adds new elements at specified positions
    dq1.insert(dq1.end() - 1, 2, 6);

    //calls sort function for deque
    sort(dq1.begin(), dq1.end());

    //calls generic template with type int
    deque<int> dq3;

    //resizes dq3 so that it contains the number of elements in dq1 and dq2 combined
    dq3.resize(dq1.size() + dq2.size());

    //merges all three dq's together
    merge(dq1.begin(), dq1.end(), dq2.begin(), dq2.end(), dq3.begin());

    //prints values of deques
    printDeque(dq1, "dq1");
    printDeque(dq2, "dq2");
    printDeque(dq3, "dq3");
    return 0;
}
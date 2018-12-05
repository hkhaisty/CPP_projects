#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

//generic template
template<class T>
//vod return method that takes in generic template type and string val
void printList(const list<T> &lst, string s) {
    //prints title of list
    cout << s << ":  ";
    //loops through to print contents of list
    for (typename list<T>::const_iterator i = lst.begin(); i != lst.end(); i++)
        //formats to include space in list
        cout << *i << ' ';
    //ends line
    cout << endl;
}

int main() {
    //declare lst1 with no values
    list<int> lst1;

    //print empty lst1
    printList(lst1, "lst1");

    //call template and populate with 3 value 7's
    list<int> lst2(3, 7);

    //print contents of lst2
    printList(lst2, "lst2");

    //loop through 5 times to populate lst1
    for (int j = 1; j <= 5; j++)
        //push back iterated values onto lst1
        lst1.push_back(j);

    //call template to make list of type int
    list<int>::iterator i1 = lst1.begin(), i2 = i1, i3;

    //increment i2
    i2++;
    i2++;
    i2++;

    //call template to make lst3, increment add value of i2 i1
    list<int> lst3(++i1, i2);

    //print contents of lst3
    printList(lst3, "lst3");

    //call template to create lst4
    list<int> lst4(lst1);

    //print contents of lst4
    printList(lst4, "lst4");

    //set i1 to first value in lst4
    i1 = lst4.begin();

    //transfers elements from lst2 into position in lst4
    lst4.splice(++i1, lst2);

    //print contents of lst2
    printList(lst2, "lst2");

    //print new contents of lst4
    printList(lst4, "lst4");

    //set lst2 to lst1
    lst2 = lst1;

    //print contents of lst2
    printList(lst2, "lst2");

    //set value of i2 to fist value in lst2
    i2 = lst2.begin();

    //transfers element from lst2 into lst4 at between posititon i1 and i2+1
    lst4.splice(i1, lst2, ++i2);

    //print contents of lst2
    printList(lst2, "lst2");

    //print contents of lst4
    printList(lst4, "lst4");

    //set i2 to element at beginning of lst2
    i2 = lst2.begin();

    //set i3 to val i2
    i3 = i2;

    //transfer elements from lst2 into lst4
    lst4.splice(i1, lst2, i2, ++i3);

    //print contents of lst2
    printList(lst2, "lst2");

    //print contents of lst4
    printList(lst4, "lst4");

    //remove elements of value 1 from lst4
    lst4.remove(1);

    //print contents of lst4
    printList(lst4, "lst4");

    //implement sorting algorithm for lst4
    lst4.sort();

    //print contents of lst4
    printList(lst4, "lst4");

    //remove consecutive duplicates in lst4
    lst4.unique();

    //print contents of lst4
    printList(lst4, "lst4");

    //merge contents of lst1 and lst2
    lst1.merge(lst2);

    //print contents of lst1
    printList(lst1, "lst1");

    //print empty lst2
    printList(lst2, "lst2");

    //reverse conents of lst3
    lst3.reverse();

    //print new order of lst3
    printList(lst3, "lst3");

    //reverse contents of lst4
    lst4.reverse();

    //print contents of lst4
    printList(lst4, "lst4");

    //merge lst3 with lst4
    lst3.merge(lst4, greater<int>());

    //print new contents of lst3
    printList(lst3, "lst3");

    //print new emprty contents of lst4
    printList(lst4, "lst4");

    //remove all elements from lst3 that are not equal to 3
    lst3.remove_if(bind2nd(not_equal_to<int>(), 3));

    //print contents of lst3
    printList(lst3, "lst3");

    //check for uniqueness
    lst3.unique(not_equal_to<int>());

    //print contents of lst3
    printList(lst3, "lst3");
    return 0;
}
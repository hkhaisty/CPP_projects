// constructing vectors
#include <iostream>
#include <vector>

//assign, at, back, begin, capacity, clear, empty, end, erase, front insert, max_size, =, [], pop_back, push_back, size.

int main() {
    // constructors used in the same order as described above:
    std::vector<int> first;                                // empty vector of ints
    std::vector<int> second(4, 100);                       // four ints with value 100
    std::vector<int> third(second.begin(), second.end());  // iterating through second
    std::vector<int> fourth(third);                       // a copy of third

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16, 2, 77, 29};

    std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
    std::cout << "The contents of FIFTH are:";
    for (int &it : fifth)
        std::cout << ' ' << it;
    std::cout << '\n';

    std::cout << "The contents of FOURTH are:";
    for (int &it : fourth)
        std::cout << ' ' << it;
    std::cout << '\n';

    std::cout << "The contents of THIRD are:";
    for (int &it : third)
        std::cout << ' ' << it;
    std::cout << '\n';

    std::cout << "The contents of SECOND are:";
    for (int &it : second)
        std::cout << ' ' << it;
    std::cout << '\n';

    std::cout << "The contents of FIRST are:";
    for (int &it : first)
        std::cout << ' ' << it;
    std::cout << '\n';

    return 0;
} 
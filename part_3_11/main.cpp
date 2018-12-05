#include <iostream>
#include <array>
#include <vector>

using namespace std;
bool isEqual = true;

void union_operator(std::vector<int> first, std::vector<int> second){
    for (int i = 0; i < first.size(); i++){
        for (int j = 0; j < second.size(); j++){
            if (first.at(i) != second.at(j))
            {
                isEqual == false;
            }
        }
    }
    cout << isEqual;
}

int main() {

    std::vector<int> vector_1;
    std::vector<int> vector_2;
    int input= -1;

    cout << "We're going to populate our first list: \n";
    while (input != 0) {
        cout << "Enter an integer: ";
        cin >> input;
        vector_1.push_back(input);
    }

    input = -1;

    cout << "Now we're going to populate out second list: ";
    while (input != 0) {
        cout << "Enter an integer: ";
        cin >> input;
        vector_2.push_back(input);
    }

    union_operator(vector_1, vector_2);
}
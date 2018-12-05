#include <iostream>
#include <array>
#include <vector>

using namespace std;

void union_operator(std::vector<int> first, std::vector<int> second) {
    std::vector<int> mega_vector;

    for (int i = 0; i < first.size(); i++) {
        mega_vector.push_back(first[i]);

        for (int j = 0; j < second.size(); j++) {
            if (second[j] == first[i])
                second.erase(second.begin() + j);
        }
    }

    for (int k = 0; k < second.size(); k++)
        mega_vector.push_back(second[k]);

    for (int l = 0; l < mega_vector.size(); l++)
        cout << mega_vector[l] << " ";
}

void intersection_operator(std::vector<int> first, std::vector<int> second) {
    std::vector<int> micro_vector;

    for (int i = 0; i < first.size(); i++) {
        for (int j = 0; j < second.size(); j++) {
            if (second[j] == first[i]) {
                micro_vector.push_back(second[j]);
            }
        }
    }

    for (int m = 0; m < micro_vector.size(); ++m) {
        cout << micro_vector[m] << " ";
    }
}

void minus_operator(std::vector<int> first, std::vector<int> second) {
    for (int i = 0; i < first.size(); i++)
        for (int j = 0; j < second.size(); j++)
            if (second[j] == first[i])
                first.erase(first.begin() + i);

    for (int k = 0; k < first.size(); k++) {
        cout << first[k] << " ";
    }
}

void delta_operator(std::vector<int> first, std::vector<int> second) {
    std::vector<int> vector_nonoverlapping;

    for (int i = 0; i < first.size(); i++) {
        for (int j = 0; j < second.size(); j++) {
            if (second[j] == first[i]) {
                first.erase(first.begin() + i);
                second.erase(second.begin() + j);
            }
        }
    }

    for (int k = 0; k < first.size(); k++)
        vector_nonoverlapping.push_back(first[k]);
    for (int l = 0; l < second.size(); ++l)
        vector_nonoverlapping.push_back(second[l]);

    for (int m = 0; m < vector_nonoverlapping.size(); m++)
        cout << vector_nonoverlapping[m] << " ";
}

int main() {

    std::vector<int> vector_1;
    std::vector<int> vector_2;

    int input = -1;

    cout << "We're going to populate our first list: \n";
    while (true) {
        cout << "Enter an integer: ";
        cin >> input;

        if (input == 0)
            break;
        else
            vector_1.push_back(input);
    }

    input = -1;

    cout << "Now we're going to populate out second list: ";
    while (true) {

        cout << "Enter an integer: ";
        cin >> input;

        if (input == 0)
            break;

        else
            vector_2.push_back(input);
    }

    cout << "1. The UNION of these sets is: ";
    union_operator(vector_1, vector_2);

    cout << "\n2. The INTERSECTION of these sets is: ";
    intersection_operator(vector_1, vector_2);

    cout << "\n3. The SUBTRACTION of these sets is: ";
    minus_operator(vector_1, vector_2);

    cout << "\n4. The DELTA of these sets is: ";
    delta_operator(vector_1, vector_2);
}
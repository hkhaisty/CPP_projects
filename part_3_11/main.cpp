#include <iostream>
#include <array>
#include <vector>

using namespace std;

//method to set union of two sets
void union_operator(std::vector<int> first, std::vector<int> second) {
    std::vector<int> mega_vector;

    //loops through and populates larger vector with elements from vector 1
    for (int i = 0; i < first.size(); i++) {
        mega_vector.push_back(first[i]);

        //loops through and determines if any elements from second vector duplicate first vector
        for (int j = 0; j < second.size(); j++) {
            if (second[j] == first[i])
                //erases duplicate elements
                second.erase(second.begin() + j);
        }
    }

    //adds resized vector to mega vector
    for (int k = 0; k < second.size(); k++)
        mega_vector.push_back(second[k]);

    //prints contents of mega vector
    for (int l = 0; l < mega_vector.size(); l++)
        cout << mega_vector[l] << " ";
}

//method to determine intersection of two sets
void intersection_operator(std::vector<int> first, std::vector<int> second) {
    std::vector<int> micro_vector;

    //loops through first vector
    for (int i = 0; i < first.size(); i++) {
        //loops through second vector and identifies duplicates
        for (int j = 0; j < second.size(); j++) {
            if (second[j] == first[i]) {
                //adds duplicates to micro vector
                micro_vector.push_back(second[j]);
            }
        }
    }

    //prints contents of micro vector
    for (int m = 0; m < micro_vector.size(); ++m) {
        cout << micro_vector[m] << " ";
    }
}

//method to determine difference of two sets
void minus_operator(std::vector<int> first, std::vector<int> second) {
    //loops through first set
    for (int i = 0; i < first.size(); i++)
        //loops through second set
        for (int j = 0; j < second.size(); j++)
            //erases elements that overlap from sets
            if (second[j] == first[i])
                first.erase(first.begin() + i);

    //prints newly resized first array
    for (int k = 0; k < first.size(); k++) {
        cout << first[k] << " ";
    }
}

//method to determine change in two sets
void delta_operator(std::vector<int> first, std::vector<int> second) {
    std::vector<int> vector_nonoverlapping;

    //loops through first vector
    for (int i = 0; i < first.size(); i++) {
        //loops through second vector
        for (int j = 0; j < second.size(); j++) {
            //erases duplicates from both lists
            if (second[j] == first[i]) {
                first.erase(first.begin() + i);
                second.erase(second.begin() + j);
            }
        }
    }

    //adds nonoverlapping elements from first vector to list
    for (int k = 0; k < first.size(); k++)
        vector_nonoverlapping.push_back(first[k]);
    //adds nonoverlapping elements from second vector to list
    for (int l = 0; l < second.size(); ++l)
        vector_nonoverlapping.push_back(second[l]);
    //prints final list
    for (int m = 0; m < vector_nonoverlapping.size(); m++)
        cout << vector_nonoverlapping[m] << " ";
}

int main() {

    //declare two vector variables
    std::vector<int> vector_1;
    std::vector<int> vector_2;

    //sentinal value for user input
    int input = -1;

    //print message to console to prompt user to populate list
    cout << "We're going to populate our first list, press 0 to complete list: \n";

    //set condition for loop
    while (true) {
        //prompt user for input
        cout << "Enter an integer: ";
        //accept user input
        cin >> input;

        //set condition for break
        if (input == 0)
            break;
        //else continue looping
        else
            vector_1.push_back(input);
    }

    //reset sentinal value since input will be set to 0
    input = -1;

    //prompt user for second set of values
    cout << "Now we're going to populate out second list, press 0 to complete list: ";

    //set condition for loop
    while (true) {

        //prompt user for input
        cout << "Enter an integer: ";
        //accept user input
        cin >> input;

        //set condition for break
        if (input == 0)
            break;
        //else continue looping
        else
            vector_2.push_back(input);
    }

    //print format for union method
    cout << "1. The UNION of these sets is: ";
    //call union subroutine
    union_operator(vector_1, vector_2);

    //print format for intersection method
    cout << "\n2. The INTERSECTION of these sets is: ";
    //call intersection subroutine
    intersection_operator(vector_1, vector_2);

    //print format for subtraction method
    cout << "\n3. The SUBTRACTION of these sets is: ";
    //call minus subroutine
    minus_operator(vector_1, vector_2);

    //print format for delta method
    cout << "\n4. The DELTA of these sets is: ";
    //call delta subroutine
    delta_operator(vector_1, vector_2);
}
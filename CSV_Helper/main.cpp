#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream myfile;
    myfile.open("example.csv");

    for (int i = 1; i < 20; i ++){
        myfile << rand() % 100 << "\n";
    }
    myfile.close();
}
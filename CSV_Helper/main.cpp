#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream myfile;
    myfile.open("example.csv");
    myfile << "This is the first cell in the first column\n";
    myfile << "a,b,c, \n";
    myfile << "c,s,v, \n";
    myfile << "1,2,3.456\n";
    myfile << "semi;color";
    myfile.close();
}
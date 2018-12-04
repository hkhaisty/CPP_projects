#include <iostream>
using namespace std;

//this generic template allows the user to put in any two value types and it will still compare them
template <typename GenericType>
GenericType maxValue(const GenericType& value1, const GenericType& value2)
{
    if(value1 > value2)
        return value1;
    else
        return value2;
}

//this double-centered compare method only evaluates the difference between two doubles
double maxValue(const double& value1, const double& value2)
{
    if (value1 > value2)
        return value1;
    else
        return value2;
}

//this int-centered method only compares the difference between two integer values
int maxValue(const int& value1, const int& value2){
    if (value1 > value2)
        return  value1;
    else
        return value2;
}

//this main feeds in a series of different values
int main() {
    int i = 5, j = 6, k, z, y;
    long l = 10, m = 5, n;
    //this calls the templat of type generic
    k = maxValue<double>(i, j);
    //this calls the double method
    z = maxValue(i, j);
    //this calls the integer method by casting the values of i and j to type int
    y = maxValue<int>(i, j);

    //all three results are standardized
    cout << "Generic Type Result: " <<k << endl;
    cout << "Double Method Result: " << z << endl;
    cout << "Integer Method Result: " << y << endl;
}
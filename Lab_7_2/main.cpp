#include <iostream>
using namespace std;

template <typename GenericType>
GenericType maxValue(const GenericType& value1, const GenericType& value2)
{
    if(value1 > value2)
        return value1;
    else
        return value2;
}

double maxValue(const double& value1, const double& value2)
{
    if (value1 > value2)
        return value1;
    else
        return value2;
}

int maxValue(const int& value1, const int& value2){
    if (value1 > value2)
        return  value1;
    else
        return value2;
}

int main() {
    int i = 5, j = 6, k, z, y;
    long l = 10, m = 5, n;
    k = maxValue<double>(i, j);
    z = maxValue(i, j);
    y = maxValue<int>(i, j);
    cout << k << endl;
    cout << z << endl;
    cout << y << endl;
}
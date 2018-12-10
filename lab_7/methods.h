#include <iostream>

using namespace std;

//creates generic type template to accept all kinds of values
template<typename GenericType>
GenericType max_value(const GenericType &value1, const GenericType &value2) {
    if (value1 > value2)
        return value1;
    else
        return value2;
}

//overloaded method accepts input of integer value
int max_value(const int &value1, const int &value2) {
    if (value1 > value2)
        return value1;
    else
        return value2;
}

//overloaded method accepts input of double value
double max_value(const double &value1, const double &value2) {
    if (value1 > value2)
        return value1;
    else
        return value2;
}

//overloaded method accepts input of char value
char max_value(const char &value1, const char &value2) {
    if (value1 > value2)
        return value1;
    else
        return value2;
}

//overloaded method accepts input of string value
string max_value(const string &value1, const string &value2){
    if (value1 > value2)
        return value1;
    else
        return value2;
}


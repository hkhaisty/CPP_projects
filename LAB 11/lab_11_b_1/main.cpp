#include <iostream>
#include <queue>

using namespace std;


struct CustomCompare
{
    bool operator()(const int& lhs, const int& rhs)
    {
        return lhs < rhs;
    }
};

int main() {


    priority_queue <int, vector<int>, CustomCompare>pq;

}
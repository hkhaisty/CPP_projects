// Lab 6 Program 
#include <iostream>

using namespace std;

class node
{
    //declare and initialize variables as public
public:
    //node* uses the dereference operator to access the variable it points to directly
    int item; node* next;
    //makes public method node and accepts integer value and direct value at node*
    node(int x, node* t)
    //sets item to integer value and next to direct value
    { item = x; next = t; }
};

    //defines the type of the value node as the direct value referenced at *link
typedef node *link;

int main()
    //declares i, N, and M. Initializes N and M to 100000 and 10, respectively.
{ int i, N = 1000000, M = 10;
    //declare and initialize link t to values passed into node, t implements next
    link t = new node(1, 0); t->next = t;
    //sets value of x to ref value at t
    link x = t;
    //for the declared value of N, set x to the implemented value of N, which is set to
    //node that is fed in the values "i" and "t"
    for (i = 2; i <= N; i++)
        x = (x->next = new node(i, t));
    //before x meets the conditional value of x->next
    while (x != x->next)
    {
        for (i = 1; i < M; i++) x = x->next;
        x->next = x->next->next;
    }
    //print out implemented item value called by object x
    cout << x->item << endl;
}


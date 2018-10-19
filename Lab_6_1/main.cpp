// Lab 6 Program 
#include <iostream>

using namespace std;

class node
{
public:

    int item; node* next;
    node(int x, node* t)
    { item = x; next = t; }
};

typedef node *link;

int main()
{ int i, N = 1000000, M = 10;
    link t = new node(1, 0); t->next = t;
    link x = t;
    for (i = 2; i <= N; i++)
        x = (x->next = new node(i, t));
    while (x != x->next)
    {
        for (i = 1; i < M; i++) x = x->next;
        x->next = x->next->next;
    }
    cout << x->item << endl;
}


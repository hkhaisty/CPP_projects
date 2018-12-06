#include <iostream>

using namespace std;

//create node struct
struct node {
    int val;
    //point to next value
    node *next;

    //call node function and pass int val
    node(int val) {
        //initialize val
        this->val = val;
        //remove addressed data from next
        this->next = nullptr;
    }
};

//declare constant integer N
static const int N = 1000;

int main() {
    int i;
    //address head of node with new node of val 0
    node *head(new node(0)), *current(head);
    //set next node to next val
    current->next = new node(0);
    current = current->next;
    //populate list
    for (i = 2; i < N; i++) {
        current->next = new node(1);
        current = current->next;
    }

    //set current to two nodes down
    current = head->next->next;
    for (i = 2; i < N; i++) {
        //set conditional
        if (current->val) {
            for (int j = i; j * i < N; j++) {
                node *temp(head);
                for (int k = 0; k < j * i; k++) {
                    temp = temp->next;
                }
                temp->val = 0;
            }
        }
        current = current->next;
    }

    //move down list
    current = head->next->next;
    for (i = 2; i < N; i++) {
        //print output
        if (current->val) {
            cout << i << " ";
        }
        current = current->next;
    }
    cout << endl;
}
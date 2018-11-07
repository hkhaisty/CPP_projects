///Binary Tree
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

        int main()
        {
            BinaryTree < string > tree1;
            tree1.insert("George");
            tree1.insert("Michael");
            tree1.insert("Tom");
            tree1.insert("Adam");
            tree1.insert("Jones");
            tree1.insert("Peter");
            tree1.insert("Daniel");
            cout << "Inorder (sorted): ";
            tree1.inorder();
            cout << "\nPostorder: ";
            tree1.postorder();
            cout << "\nPreorder: ";
            tree1.preorder();
            cout << "\nThe number of nodes is " << tree1.getSize();
            int numbers[] =
                    {
                            2, 4, 3, 1, 8, 5, 6, 7
                    };
            BinaryTree < int > tree2(numbers, 8);
            cout << "\nInorder (sorted): ";
            tree2.inorder();
            cout << "\nsearch 2 " << tree2.search(2) << endl;
            cout << "\nsearch 99 " << tree2.search(99) << endl;
            cout << "\nsearch 8 " << tree2.search(8) << endl;
            return 0;
        }
//
// Created by harri on 11/5/2018.
//

#include <stdlib.h>
namespace tree {
    template<typename T>
    class TreeNode {
    public:
        T element; //
        TreeNode<T> *left; //
        TreeNode<T> *right; //
        TreeNode() //
        {
            left = NULL;
            right = NULL;
        }

        TreeNode(T element) // Constructor
        {
            this->element = element;
            left = NULL;
            right = NULL;
        }
    };
}
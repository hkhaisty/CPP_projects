//
// Created by harri on 11/5/2018.
//

#include "BinaryTree.h"
#include <cmath>
#include <stdlib.h>

template < typename T >
BinaryTree < T >::BinaryTree()
{
    root = NULL;
    size = 0;
}
template < typename T >
BinaryTree < T >::BinaryTree(T elements[], int arraySize)
{
    root = NULL;
    size = 0;
    for (int i = 0; i < arraySize; i++)
    {
        insert(elements[i]);
    }
}
template < typename T >
bool BinaryTree < T >::insert(T element)
{
    if (root == NULL)
        root = new TreeNode < T > (element); // Create a new root
    else
    {
        // Locate the parent node
        TreeNode < T > * parent = NULL;
        {
            if (root == NULL) return;
            postorder(root->left);
            postorder(root->right);
            cout << root->element << " ";
        }
/* */
        template < typename T >
        void BinaryTree < T >::preorder()
        {
            preorder(root);
        }
/* */
        template < typename T >
        void BinaryTree < T >::preorder(TreeNode < T > * root)
        {
            if (root == NULL) return;
            cout << root->element << " ";
            preorder(root->left);
            preorder(root->right);
        }
/**/
        template < typename T >
        int BinaryTree < T >::getSize()
        {
            return size;
        }
        template < typename T >
        bool BinaryTree < T >::search(T element)
        {
            return search(element, root);
        }
        template < typename T >
        bool BinaryTree < T >::search(T element, TreeNode < T > * root)
        {
            if (root == NULL)
                return false;
            else if (root->element == element)
                return true;
            else if (root->element > element)
                return search(element, root->right);
            else
                return search(element, root->left);
        }
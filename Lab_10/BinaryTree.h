//
// Created by harri on 11/5/2018.
//

#ifndef LAB_10_BINARYTREE_H
#define LAB_10_BINARYTREE_H

template < typename T >
class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(T elements[], int arraySize);
    bool insert(T element);
    void inorder();
    void preorder();
    void postorder();
    int getSize();
    bool search(T element);
    void breadthFirstTraversal();
    int depth();
private:
    TreeNode < T > * root;
    int size;
    void inorder(TreeNode < T > * root);
    void postorder(TreeNode < T > * root);
    void preorder(TreeNode < T > * root);
    bool search(T element, TreeNode < T > * root);
    int depth(TreeNode<T> * root);
};



#endif //LAB_10_BINARYTREE_H

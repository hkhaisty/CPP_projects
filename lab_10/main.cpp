#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

template<typename T>

class TreeNode {
public:
    T element;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode<T> *next;

    TreeNode() {
        left = NULL;
        next = NULL;
    }

    TreeNode(T element) { // Constructor
        this->element = element;
        left = NULL;
        right = NULL;
    }
};

template<typename T>
class BinaryTree {
public:
    BinaryTree();

    BinaryTree(T elements[], int array_size);

    bool insert(T element);

    void inorder();

    void preorder();

    void postorder();

    int get_size();

    bool search(T element);

    void breadth_first_traversal();

    int depth();

private:
    TreeNode<T> *root;
    int size;

    void inorder(TreeNode<T> *root);

    void postorder(TreeNode<T> *root);

    void preorder(TreeNode<T> *root);

    bool search(T element, TreeNode<T> *root);

    int depth(TreeNode<T> *element);

    void print_level_order(TreeNode<T> *root);

    void print_node_at_level(TreeNode<T> *root, int lvl);
};

//method for getting height of tree
template<typename T>
int BinaryTree<T>::depth() {
    return depth(root);
}

//method for performing breadth first traversal
template<typename T>
void BinaryTree<T>::breadth_first_traversal() {
    print_level_order(root);
}

//method for printing level order of the tree
template<typename T>
void BinaryTree<T>::print_level_order(TreeNode<T> *root) {
    int height = depth(root);
    int i;
    for (i = 1; i <= height; i++)
        print_node_at_level(root, i);
}

//printing nodes at a level
template<typename T>
void BinaryTree<T>::print_node_at_level(TreeNode<T> *root, int lvl) {
    if (root == NULL)
        return;
    if (lvl == 1)
        cout << " " << root->element;
    else if (lvl > 1) {
        print_node_at_level(root->left, lvl - 1);
        print_node_at_level(root->right, lvl - 1);
    }
}

//method for computing depth
template<typename T>
int BinaryTree<T>::depth(TreeNode<T> *element) {
    if (element == NULL)
        return 0;
    else {
        int left_depth = depth(element->left);
        int right_depth = depth(element->right);

        // use the larger one
        if (left_depth > right_depth)
            return (left_depth + 1);
        else
            return (right_depth + 1);
    }
}

template<typename T>
BinaryTree<T>::BinaryTree() {
    root = NULL;
    size = 0;
}

template<typename T>
BinaryTree<T>::BinaryTree(T elements[], int array_size) {
    root = NULL;
    size = 0;
    for (int i = 0; i < array_size; i++) {
        insert(elements[i]);
    }
}

template<typename T>
bool BinaryTree<T>::insert(T element) {
    if (root == NULL)
        root = new TreeNode<T>(element); // Create a new root
    else {

        // Locate the parent node
        TreeNode<T> *parent = NULL;
        TreeNode<T> *current = root;
        while (current != NULL)
            if (element < current->element) {
                parent = current;
                current = current->left;
            } else if (element > current->element) {
                parent = current;
                current = current->right;
            } else
                return false; //Duplicate node not inserted

        //Create the new node and attach it to the parent node
        if (element < parent->element)
            parent->left = new TreeNode<T>(element);
        else
            parent->right = new TreeNode<T>(element);
    }
    size++;
    return true; //Element inserted
}

//template for inorder traversal
template<typename T>
void BinaryTree<T>::inorder() {
    inorder(root);
}

//adds inorder traversal to form a subtree
template<typename T>
void BinaryTree<T>::inorder(TreeNode<T> *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->element << " ";
    inorder(root->right);
}

//adds postorder traversal
template<typename T>
void BinaryTree<T>::postorder() {
    postorder(root);
}

//adds postorder traversals to form a subtree
template<typename T>
void BinaryTree<T>::postorder(TreeNode<T> *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->element << " ";
}

template<typename T>
void BinaryTree<T>::preorder() {
    preorder(root);
}

template<typename T>
void BinaryTree<T>::preorder(TreeNode<T> *root) {
    if (root == NULL) return;
    cout << root->element << " ";
    preorder(root->left);
    preorder(root->right);
}


template<typename T>
int BinaryTree<T>::get_size() {
    return size;
}

//adds function to find height of tree
template<typename T>
bool BinaryTree<T>::search(T element) {
    return search(element, root);
}

//adds function to find height of tree
template<typename T>
bool BinaryTree<T>::search(T element, TreeNode<T> *root) {
    if (root == NULL)
        return false;
    else if (root->element == element)
        return true;
    else if (root->element > element)
        return search(element, root->right);
    else
        return search(element, root->left);
}

int main() {
    BinaryTree<string> tree_1;
    tree_1.insert("George");
    tree_1.insert("Michael");
    tree_1.insert("Tom");
    tree_1.insert("Adam");
    tree_1.insert("Jones");
    tree_1.insert("Peter");
    tree_1.insert("Daniel");

    cout << "Inorder (sorted): ";
    tree_1.inorder();
    cout << endl;

    cout << "\nPostorder: ";
    tree_1.postorder();
    cout << endl;

    cout << "\nPreorder: ";
    tree_1.preorder();
    cout << endl;

    cout << "\nThe number of nodes is " << tree_1.get_size();
    cout << endl;

    int numbers[] = {
            2, 4, 3, 1, 8, 5, 6, 7
    };
    BinaryTree<int> tree_2(numbers, 8);
    cout << "\nInorder (sorted): ";
    tree_2.inorder();

    cout << "\n\nsearch 2: " << tree_2.search(2) << endl;
    cout << "search 99: " << tree_2.search(99) << endl;
    cout << "search 8: " << tree_2.search(8) << endl;

    //breadth-first traversal function
    cout << "\nBreadth-first traversal: ";
    tree_2.breadth_first_traversal();
    cout << endl;

    //function for height of tree
    cout << "\nHeight: " << tree_2.depth();
    cout << endl;
}
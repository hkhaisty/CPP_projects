//
// Created by hkhai on 12/12/2018.
//

#ifndef LAB_10_METHODS_H
#define LAB_10_METHODS_H

class TreeNode{

public:
    T element;
    TreeNode < T > * left;
    TreeNode < T > * right;
    TreeNode <T> * next;

    TreeNode() {
        left = NULL;
        next = NULL;
    }

    TreeNode(T element){ // Constructor
        this->element = element;
        left = NULL;
        right = NULL;
    }
};

template <typename T>



template < typename T > class BinaryTree{
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
    void printLvlOrdr(TreeNode < T > * root);
    void printGvnLvl(TreeNode < T > * root, int lvl);
};

// method to get the height of the tree
template < typename T > int BinaryTree < T >::depth(){
    return depth(root);
}

// method to perfrom breadth first traversal
template < typename T > void BinaryTree < T >::breadthFirstTraversal(){
    printLvlOrdr(root);
}

// method to print level order of the tree
template < typename T > void BinaryTree < T >::printLvlOrdr(TreeNode < T > * root){
    int height = depth(root);
    int ilp;
    for (ilp = 1; ilp <= height; ilp++)
        printGvnLvl(root, ilp);
}

/* Print nodes at a given level */
template < typename T > void BinaryTree < T >::printGvnLvl(TreeNode < T > * root, int lvl){
    if (root == NULL)
        return;
    if (lvl == 1)
        cout << " " << root->element;
    else if (lvl > 1){
        printGvnLvl(root->left, lvl - 1);
        printGvnLvl(root->right, lvl - 1);
    }
}

// method to compute depth
template < typename T > int BinaryTree < T >::depth(TreeNode < T > * elmnt){
    if (elmnt == NULL)
        return 0;
    else{
        int lftDepth = depth(elmnt->left);
        int rgtDepth = depth(elmnt->right);

        // use the larger one
        if (lftDepth > rgtDepth)
            return(lftDepth + 1);
        else
            return(rgtDepth + 1);
    }
}

template < typename T > BinaryTree < T >::BinaryTree(){
    root = NULL;
    size = 0;
}

template < typename T > BinaryTree < T >::BinaryTree(T elements[], int arraySize){
    root = NULL;
    size = 0;
    for (int i = 0; i < arraySize; i++){
        insert(elements[i]);
    }
}

template < typename T > bool BinaryTree < T >::insert(T element){
    if (root == NULL)
        root = new TreeNode < T >(element); // Create a new root
    else{

        // Locate the parent node
        TreeNode < T > * parent = NULL;
        TreeNode < T > * current = root;
        while (current != NULL)
            if (element < current->element){
                parent = current;
                current = current->left;
            }
            else if (element > current->element){
                parent = current;
                current = current->right;
            }
            else
                return false; //Duplicate node not inserted

        //Create the new node and attach it to the parent node
        if (element < parent->element)
            parent->left = new TreeNode < T >(element);
        else
            parent->right = new TreeNode < T >(element);
    }
    size++;
    return true; //Element inserted
}

/*B. Inorder traversal */
template < typename T > void BinaryTree < T >::inorder(){
    inorder(root);
}

/*B. Inorder traversal from a subtree */
template < typename T > void BinaryTree < T >::inorder(TreeNode < T > * root){
    if (root == NULL) return;
    inorder(root->left);
    cout << root->element << " ";
    inorder(root->right);
}

/*B. Postorder traversal */
template < typename T > void BinaryTree < T >::postorder(){
    postorder(root);
}

/*B. Inorder traversal from a subtree */
template < typename T > void BinaryTree < T >::postorder(TreeNode < T > * root){
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->element << " ";
}

template < typename T > void BinaryTree < T >::preorder(){
    preorder(root);
}

template < typename T > void BinaryTree < T >::preorder(TreeNode < T > * root){
    if (root == NULL) return;
    cout << root->element << " ";
    preorder(root->left);
    preorder(root->right);
}


template < typename T > int BinaryTree < T >::getSize(){
    return size;
}

//C. Add a function to find the height of a tree.
template < typename T > bool BinaryTree < T >::search(T element){
    return search(element, root);
}

//C. Add a function to find the height of a tree.
template < typename T > bool BinaryTree < T >::search(T element, TreeNode < T > * root){
    if (root == NULL)
        return false;
    else if (root->element == element)
        return true;
    else if (root->element > element)
        return search(element, root->right);
    else
        return search(element, root->left);
}


#endif //LAB_10_METHODS_H

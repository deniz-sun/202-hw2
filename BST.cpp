/**
* Title : Binary Search Trees
* Author : Deniz Sun
* ID: 22003981
* Section : 1
* Assignment : 2
* Description : the binary search tree class for all operations
*/

#include "BST.h"
// Default constructor
BST::BST() : root(NULL) {
}
// Protected constructor
BST::BST(TreeNode *nodePtr) : root(nodePtr) {
}
//destructor
BST::~BST() {
    destroyTree(root);
}
//destructs the tree by deleting left and right children recursively
void BST::destroyTree(TreeNode *& treePtr) {

    if (treePtr != nullptr){
        destroyTree(treePtr->left);
        destroyTree(treePtr->right);
        delete treePtr;
        treePtr = nullptr;
    }
}
//main insert function to call when inserting a new item
void BST::insert(int key) {
    insert(key, root);

}
//helper insert function to call. it recursively finds the position to insert the data at
void BST::insert(const int key, TreeNode *&node){
    //base case if there is no node
    if (node == nullptr)
        node = new TreeNode(key, nullptr, nullptr);
    else{
        if (key < node->data)
            insert(key, node->left);
        else
            insert(key, node->right);
    }
}
//main delete function to call when deleting an item
void BST::deleteKey(int key) {
    deleteKey(key, root);
}
//helper delete function to call, recursively goes through the left and right subtrees and
void BST::deleteKey(int key, TreeNode *&node ){
    int replacementItem;
    //base case if the BST is empty
    if (node == nullptr)
        return;
    else if (key < node->data)
        deleteKey(key, node->left);
    else if (key > node->data)
        deleteKey(key, node->right);
    else{
        //there are no children
        if(node->right == nullptr && node->left == nullptr){
            delete node;
            node = nullptr;
        }
        //it has one child at left
        else if (node->right == nullptr){
            TreeNode *temp = node;
            node = node ->left;
            temp->left = nullptr;
            delete temp;
        }
        //it has one child at right
        else if (node->left == nullptr){
            TreeNode *temp = node;
            node = node->right;
            temp->right = nullptr;
            delete temp;
        }
        //it has 2 children
        else {
            processLeftmost(node->right,replacementItem);
            node->data = replacementItem;
        }
    }
}
// main function to get the height of a tree
// height(T) = 1 + max{height(T1),height(T2),...,height(Tk)}
int BST::getHeight() {
    return getHeight(root);
}
// helper function to calculate the height through the given node
int BST::getHeight(TreeNode *node) {
    if (node == nullptr)
        return 0;
    else
        return (1+ max(getHeight(node->right), getHeight(node->left)));
}
// main function to call for the median of a tree
double BST::medianOfBST() {
    double median = 0.0;
    if (root == nullptr)
        return 0.0;
    int numOfNodes = countNumberOfNodes(root);
    if (numOfNodes == 1)
        return double(root->data);
    else if (numOfNodes % 2 == 1)
        return medianCheck(root, (numOfNodes / 2) + 1);
    else
        return (medianCheck(root, numOfNodes / 2) + medianCheck(root, (numOfNodes / 2) + 1)) / 2;

}
// main function for range search function, checks if a node is between a and b
void BST::rangeSearch(int a, int b) {
    rangeSearch(a, b, root);
}
// counts the number of nodes in a tree
int BST::countNumberOfNodes(TreeNode *&node){
    //base case if there are no nodes
    if (node == nullptr)
        return 0;
    //keep incrementing until there are no nodes left
    return 1 + countNumberOfNodes(node->left) + countNumberOfNodes(node->right);
}
// main function for getting the total node count of a tree
int BST::getNodeCount(){
    return countNumberOfNodes(root);
}
// helper function for calculating the median of a tree
double BST::medianCheck(TreeNode *node, int index){
    int count;
    if (node == nullptr)
        return 0.0;
    //count the left children
    count = countNumberOfNodes(node->left);
    //if there's only one node, that is the median
    if (index == count + 1)
        return node->data;
    else if (count >= index)
        return medianCheck(node->left, index);
    else{
        index = index - (count + 1);
        return medianCheck(node->right, index);
    }
}
// helper range search that checks if the node is between a and b
void BST::rangeSearch(int a, int b, TreeNode *node){
    //base case if no nodes
    if (node == nullptr)
        return;
    //if it's in range for data > a, traverse the leftmost nodes
    if (node->data >= a)
        rangeSearch(a, b, node->left);
    //if the node is between a and b, print its data
    if (node->data <= b && node->data >= a)
        cout << node->data << "  ";
    //if it's in range for data < b, traverse the right subtree nodes
    if (node->data < b)
        rangeSearch(a, b, node->right);
}
// finds the leftmost node of the tree
void BST::processLeftmost(TreeNode *&nodePtr, int &treeItem){

    if (nodePtr->left == nullptr) {
        //the successor
        treeItem = nodePtr->data;
        TreeNode *delPtr = nodePtr;
        nodePtr = nodePtr->right;
        delPtr->right = nullptr; // defense
        delete delPtr;
    }
    else
        //recursive on left node
        processLeftmost(nodePtr->left, treeItem);
}

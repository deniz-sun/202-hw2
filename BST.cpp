/**
* Title : Binary Search Trees
* Author : Deniz Sun
* ID: 22003981
* Section : 1
* Assignment : 2
* Description :
 *
 *
*/


#include "BST.h"

// Default constructor
BST::BST() : root(NULL) {

}


// Protected constructor
BST::BST(TreeNode *nodePtr) : root(nodePtr) {

}

/**
// Constructor
BST::BST(const int& rootItem) {
    root = new TreeNode(rootItem, NULL, NULL);
}

// Constructor
BST::BST(const int& rootItem,
                       BST& leftTree, BST& rightTree) {
    root = new TreeNode(rootItem, NULL, NULL);
    attachLeftSubtree(leftTree);
    attachRightSubtree(rightTree);
}

void BST::attachLeftSubtree(BST& leftTree) {
    // Assertion: nonempty tree; no left child
    if (!isEmpty() && (root->left == NULL)) {
        root->left = leftTree.root;
        leftTree.root = NULL
    }
}

void BST::attachRightSubtree(BST& rightTree) {
    // Left as an exercise
}
// Copy constructor
BST::BST(const BST& tree) {
    copyTree(tree.root, root);
}


// Uses preorder traversal for the copy operation
// (Visits first the node and then the left and right children)
void BST::copyTree(TreeNode *treePtr, TreeNode *& newTreePtr) const {

    if (treePtr != NULL) {		// copy node
        newTreePtr = new TreeNode(treePtr->data, NULL, NULL);
        copyTree(treePtr->left, newTreePtr->left);
        copyTree(treePtr->right, newTreePtr->right);
    }
    else
        newTreePtr = NULL;	// copy empty tree
}

*/

BST::~BST() {
    destroyTree(root);
}
void BST::destroyTree(TreeNode *& treePtr) {

    if (treePtr != nullptr){
        destroyTree(treePtr->left);
        destroyTree(treePtr->right);
        delete treePtr;
        treePtr = nullptr;
    }
}
void BST::insert(int key) {
    insert(key, root);

}
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

void BST::deleteKey(int key) {
    deleteKey(key, root);
}
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
// height(T) = 1 + max{height(T1),height(T2),...,height(Tk)}
int BST::getHeight() {
    getHeight(root);
}
int BST::getHeight(TreeNode *node) {
    if (node == nullptr)
        return 0;
    else
        return (1+ max(getHeight(node->right), getHeight(node->left)));
}

double BST::medianOfBST() {
    double median = 0.0;
    int index = 0;
    int *arr = new int[getNodeCount()];
    getMedian(arr, root, index, median);
    return median;
}

void BST::rangeSearch(int a, int b) {
    rangeSearch(a, b, root);
}

int BST::countNumberOfNodes(TreeNode *&node){
    //base case if there are no nodes
    if (node == nullptr)
        return 0;
    //keep incrementing until there are no nodes left
    return 1 + countNumberOfNodes(node->left) + countNumberOfNodes(node->right);
}
int BST::getNodeCount(){
    return countNumberOfNodes(root);
}

void BST::fillArray(int *arr, TreeNode *&node, int &index){
    if (node == nullptr)
        return;
    fillArray(arr, node->left, index);
    arr[index + 1] = node->data;
    fillArray(arr, node->right, index);
}
void BST::getMedian(int *arr, TreeNode *&node, int &index, double &median){
    int arraySize = countNumberOfNodes(root) - 1;
    fillArray(arr, node, index);
    if (arraySize % 2 == 0)
        median = (arr[arraySize/2] + arr[arraySize/2] + 1) / 2;
    else
        median = arr[(arraySize+1) / 2];

}

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

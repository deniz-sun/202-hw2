/**
* Title : Binary Search Trees
* Author : Deniz Sun
* ID: 22003981
* Section : 1
* Assignment : 2
* Description : header file for the BST class
*/

#include <iostream>
#include "TreeNode.h"

using namespace std;

class BST {
public:
    BST();

    BST(TreeNode *nodePtr);

    ~BST();
    void insert(int key);
    void deleteKey(int key);
    int getHeight();
    double medianOfBST();
    void rangeSearch(int a, int b);

    void insert(int key, TreeNode *&node);
    void deleteKey(int key, TreeNode *&node);


    TreeNode *root;

    int getHeight(TreeNode *node);
    int countNumberOfNodes(TreeNode *&node);
    int getNodeCount();
    void destroyTree(TreeNode *&treePtr);
    void rangeSearch(int a, int b, TreeNode *node);
    void processLeftmost(TreeNode *&nodePtr, int &treeItem);
    double medianCheck(TreeNode *node, int index);

};

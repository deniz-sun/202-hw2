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


#ifndef INC_202_HW2_BST_H
#define INC_202_HW2_BST_H
#include <iostream>
#include "TreeNode.h"

using namespace std;

class BST {
public:
    BST();
    ~BST();
    void insert(int key);
    void deleteKey(int key);
    int getHeight();
    double medianOfBST();
    void rangeSearch(int a, int b);

    void insert(const int key, TreeNode *&node);
    void deleteKey(int key, TreeNode *&root);



    TreeNode *root;
};


#endif //INC_202_HW2_BST_H

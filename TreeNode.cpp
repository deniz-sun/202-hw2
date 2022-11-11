/**
* Title : Binary Search Trees
* Author : Deniz Sun
* ID: 22003981
* Section : 1
* Assignment : 2
* Description : The tree node for binary search tree
*/


#include "TreeNode.h"
//default constructor for tree nodes
TreeNode::TreeNode() {

}
// constructor for tree nodes that initialize the data and the left, right children
TreeNode::TreeNode(const int &data, TreeNode *left, TreeNode *right) {
    this->data = data;
    this->left = left;
    this->right = right;
}

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


#ifndef INC_202_HW2_TREENODE_H
#define INC_202_HW2_TREENODE_H


class TreeNode {
public:
    TreeNode();
    TreeNode(const int& data, TreeNode *left, TreeNode *right);

    int data;
    TreeNode *right;
    TreeNode *left;



};


#endif //INC_202_HW2_TREENODE_H

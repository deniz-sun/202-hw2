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

}
void BST::deleteKey(int key, TreeNode *&root ){
    //base case if the BST is empty
    if (root == nullptr)
        return;
    else if (key < root->data)
        deleteKey(key, root->left);
    else if (key > root->data)
        deleteKey(key, root->right);
    else{
        //there are no children
        if(root->right == nullptr && root->left == nullptr){
            delete root;
            root = nullptr;
        }
        //it has one child at left
        else if (root->right == nullptr){

        }

        //it has one child at right
        else if (root->left == nullptr){

        }
    }

}
int BST::getHeight() {
    return 0;
}

double BST::medianOfBST() {
    return 0;
}

void BST::rangeSearch(int a, int b) {

}

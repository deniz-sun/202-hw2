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

#include <iostream>
#include "BST.h"
#include "analysis.h"


int main() {

    BST tree;
    tree.insert(30);
    tree.insert(40);
    tree.insert(35);
    tree.insert(20);
    tree.insert(50);
    tree.insert(45);
    tree.insert(10);
    tree.insert(25);
    tree.insert(5);
    tree.insert(15);

    cout << "The height of the tree:\t" << tree.getHeight() << endl;

    tree.deleteKey(35);
    tree.deleteKey(40);

    cout << "The median of the tree:\n" << tree.medianOfBST() << endl;

    tree.rangeSearch(5,43);

    heightAnalysis();


    return 0;
}

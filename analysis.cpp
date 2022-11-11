/**
* Title : Binary Search Trees
* Author : Deniz Sun
* ID: 22003981
* Section : 1
* Assignment : 2
* Description : analysis class with the heightAnalysis function
*/

#include "analysis.h"
#include "BST.h"
void heightAnalysis() {

    BST tree;
    int size = 30000;
    int array[size];

    //outputs the result of analysis
    cout << "\nPart f - Analysis of BST height - part 1\n" <<
            "-----------------------------------------\n" <<
            "Tree Size \tTree Height\n" <<
            "-----------------------------------------" << endl;

    //create random integers and insert them into the tree
    for (int i = 0; i < size; ++i) {
        array[i] =  rand() % size + 1;
        tree.insert(array[i]);

        //print the node count and height at each 1500 insertion
        if ((i + 1) % 1500 == 0)
            cout << tree.getNodeCount() << "\t\t" << tree.getHeight() << endl;
    }
    //shuffle array by traversing and changing items at an index
    int temp;
    for (int i = size - 1; i > 0; i--) {
        int random = rand() % i;
        temp = array[i];
        array[i] = array[random];
        array[random] = temp;
    }

    //outputs the results after the array is shuffled
    cout << "\nPart f - Analysis of BST height - part 2\n" <<
         "-----------------------------------------\n" <<
         "Tree Size \tTree Height\n" <<
         "-----------------------------------------" << endl;
    for (int i = 0; i < size; ++i) {
        tree.deleteKey(array[i]);
        if ((i + 1) % 1500 == 0)
            cout << tree.getNodeCount() << "\t\t" << tree.getHeight() << endl;
    }
}

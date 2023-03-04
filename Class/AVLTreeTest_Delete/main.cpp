/* 
 * Modified:  from http://www.sanfoundry.com/cpp-program-implement-avl-trees/
 * Created on December 10, 2021, 9:14 PM
 * Purpose:  Example of using rotations to balance a tree
 */

//System Libraries
#include<iostream>
#include<algorithm>
using namespace std;
 
//User Libraries
#include "AVLTree.h"

//Global Constants

//Function Prototypes
void menu();

//Execution Begins Here!
int main(){
    int choice, item;
    AVLTree avl;
    avl.root = avl.insert(avl.root, 8);
    avl.root = avl.insert(avl.root, 4);
    avl.root = avl.insert(avl.root, 12);
    avl.root = avl.insert(avl.root, 2);
    avl.root = avl.insert(avl.root, 6);
    avl.root = avl.insert(avl.root, 10);
    avl.root = avl.insert(avl.root, 14);
    avl.root = avl.insert(avl.root, 1);
    avl.root = avl.insert(avl.root, 3);
    avl.root = avl.insert(avl.root, 5);
    avl.root = avl.insert(avl.root, 7);
    avl.root = avl.insert(avl.root, 9);
    avl.root = avl.insert(avl.root, 11);
    avl.root = avl.insert(avl.root, 13);
    avl.root = avl.insert(avl.root, 15);
    cout<<"In-order Traversal before Deletion:"<<endl;
    avl.inorder(avl.root);
    avl.deleteBNT(avl.root,1);
    avl.deleteBNT(avl.root,4);
    avl.deleteBNT(avl.root,12);
    avl.deleteBNT(avl.root,8);
    cout<<endl<<"In-order Traversal after Deletion:"<<endl;
    avl.inorder(avl.root);
    
    //Exit stage right!
    return 0;
}
/* 
 * Modified:  from http://www.sanfoundry.com/cpp-program-implement-avl-trees/
 * Created on May 23, 2021, 9:14 PM
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
    do{
        menu();
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to be inserted: ";cin>>item;
                avl.root = avl.insert(avl.root, item);break;
            case 2:
                if (avl.root == NULL){cout<<"Tree is Empty"<<endl;continue;}
                cout<<"Balanced AVL Tree:"<<endl;avl.display(avl.root,1);break;
            case 3:
                cout<<"In-order Traversal:"<<endl;avl.inorder(avl.root);
                cout<<endl;break;
            case 4:
                cout<<"Pre-order Traversal:"<<endl;avl.preorder(avl.root);
                cout<<endl;break;
            case 5:
                cout<<"Post-order Traversal:"<<endl;avl.postorder(avl.root);    
                cout<<endl;break;
            default:
                cout<<"Exit Program"<<endl;
        }
    }while(choice>=0&&choice<=5);
    
    //Exit stage right!
    return 0;
}

void menu(){
    cout<<"\n---------------------"<<endl;
    cout<<"AVL Tree Implementation"<<endl;
    cout<<"\n---------------------"<<endl;
    cout<<"1.Insert Element into the tree"<<endl;
    cout<<"2.Display Balanced AVL Tree"<<endl;
    cout<<"3.InOrder traversal"<<endl;
    cout<<"4.PreOrder traversal"<<endl;
    cout<<"5.PostOrder traversal"<<endl;
    cout<<"6.Exit"<<endl;
    cout<<"Enter your Choice: ";
}
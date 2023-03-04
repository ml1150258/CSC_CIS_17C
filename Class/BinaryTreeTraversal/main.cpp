/* 
 * Author: Dr. Mark E. Lehr
 * Created on May 16, 2021, 3:50 PM
 */
// C++ program for different tree traversals

#include <iostream>
using namespace std;
 
//User Library
#include "node.h"

//Prototypes
node * newNode(int);
void prntPst(node*);    //Post order left-right-root
void prntIn(node*);     //left-root-right
void prntPre(node*);    //root-left-right
void prntLev(node*);    //Output the Print Level
void prntLev(node*,int);//Output the Print Level
int  height(node*);     //Find the height of the tree
 
/* Driver program to test above functions*/
int main(){
    node *root                = newNode(8);
    root->left                = newNode(4);
    root->right               = newNode(12);
    root->left->left          = newNode(2);
    root->left->right         = newNode(6);
    root->right->left         = newNode(10);
    root->right->right        = newNode(14);
    root->left->left->left    = newNode(1);
    root->left->left->right   = newNode(3);
    root->left->right->left   = newNode(5);
    root->left->right->right  = newNode(7);     
    root->right->left->left   = newNode(9);
    root->right->left->right  = newNode(11);
    root->right->right->left  = newNode(13);
    root->right->right->right = newNode(15);     

    cout<<endl<<"Preorder traversal of binary tree is "<<endl;
    prntPre(root);

    cout<<endl<<"Inorder traversal of binary tree is "<<endl;
    prntIn(root);  

    cout<<endl<<"Postorder traversal of binary tree is "<<endl;
    prntPst(root);

    cout<<endl<<"Level Order traversal of binary tree is"<<endl;  
    prntLev(root);

    //Exit stage right!
    return 0;
}

//Helper function that allocates a new node with the
//given data and NULL left and right pointers.
node* newNode(int data){
     node *n;
     n=new node;
     n->data = data;
     n->left = NULL;
     n->right = NULL;
     return n;
}
 
//Given a binary tree, print its nodes according to the
//"bottom-up" postorder traversal.
void prntPst(node* node){
     if (node == NULL)return;
     // first recur on left subtree
     prntPst(node->left);
     // then recur on right subtree
     prntPst(node->right);
     // now deal with the node
     cout<<node->data<<" ";
}
 
//Given a binary tree, print its nodes in inorder
void prntIn(node* node){
     if (node == NULL)return;
     /* first recur on left child */
     prntIn(node->left);
     /* then print the data of node */
     cout<<node->data<<" ";  
     /* now recur on right child */
     prntIn(node->right);
}
 
//Given a binary tree, print its nodes in preorder
void prntPre(node* node){
     if (node == NULL)return;
     /* first print data of node */
     cout<<node->data<<" ";  
     /* then recur on left subtree */
     prntPre(node->left);  
     /* now recur on right subtree */
     prntPre(node->right);
}    

//Function to print level order traversal a tree
void prntLev(node* root){  
    int h = height(root);
    for (int i=1;i<=h;i++)prntLev(root, i);  
}  
  
//Print nodes at a given level
void prntLev(node* root, int level){  
    if (root == NULL)return;  
    if (level == 1)  
        cout << root->data << " ";  
    else if (level > 1){  
        prntLev(root->left, level-1);  
        prntLev(root->right, level-1);  
    }  
}  

//Compute the "height" of a tree -- the number of  
//nodes along the longest path from the root node  
//down to the farthest leaf node.
int height(node* node){  
    if (node == NULL)return 0; 
    //compute the height of each subtree
    int lheight = height(node->left);
    int rheight = height(node->right);
    //use the larger one
    if (lheight > rheight)return(lheight + 1);  
    else return(rheight + 1);
}
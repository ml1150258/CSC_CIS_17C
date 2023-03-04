/* 
 * File:   BNTnode.h
 * Modified:  from http://www.sanfoundry.com/cpp-program-implement-AVL-trees/
 * Created on May 23, 2021, 9:14 PM
 * Purpose:  An Binary Tree using an AVL balancing technique
 */

#ifndef AVLTREE_H
#define	AVLTREE_H

#include <iostream>
using namespace std;

#include "BNTnode.h"

class AVLTree{
    public:
        BNTnode *root;                   //Root node
        int height(BNTnode *);           //Tree height
        int diff(BNTnode *);             //Difference of right/left subtrees
        BNTnode *rr_rotation(BNTnode *); //Right-Right rotation
        BNTnode *ll_rotation(BNTnode *); //Left-Left   rotation
        BNTnode *lr_rotation(BNTnode *); //Left-Right  rotation
        BNTnode *rl_rotation(BNTnode *); //Right-Left  rotation
        BNTnode *balance(BNTnode *);     //Balance subtrees with diff > 1
        BNTnode *insert(BNTnode *, int );//Insert and balance the tree
        BNTnode *fndMxKey(BNTnode*);     //Utility needed in deletion
        void deleteBNT(BNTnode* &,int);  //3 cases for deletion
        void display(BNTnode *, int);    //Funky display root left to right
        void inorder(BNTnode *);         //In order display
        void preorder(BNTnode *);        //Pre order display
        void postorder(BNTnode *);       //Post order display
        AVLTree(){root = NULL;}          //Constructor
};

//******************************************************************************
//                            Height of AVL Sub Trees
//******************************************************************************
int AVLTree::height(BNTnode *temp){
    int h = 0;
    if (temp != NULL){
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
 
//******************************************************************************
//                      Height Difference of AVL Sub Trees
//******************************************************************************
int AVLTree::diff(BNTnode *temp){
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}
 
//******************************************************************************
//                      Right-Right Rotations of Sub Trees
//******************************************************************************
BNTnode *AVLTree::rr_rotation(BNTnode *parent){
    BNTnode *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

//******************************************************************************
//                      Left-Left Rotations of Sub Trees
//******************************************************************************
BNTnode *AVLTree::ll_rotation(BNTnode *parent){
    BNTnode *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
 
//******************************************************************************
//                      Left-Right Rotations of Sub Trees
//******************************************************************************
BNTnode *AVLTree::lr_rotation(BNTnode *parent){
    BNTnode *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}
 
//******************************************************************************
//                      Right-Left Rotations of Sub Trees
//******************************************************************************
BNTnode *AVLTree::rl_rotation(BNTnode *parent){
    BNTnode *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}
 
//******************************************************************************
//                         Balancing of Sub Trees
//******************************************************************************
BNTnode *AVLTree::balance(BNTnode *temp){
    int bal_factor = diff (temp);
    if (bal_factor > 1){
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }else if (bal_factor < -1){
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}
 
//******************************************************************************
//                    Insert the Data into the Sub Trees
//******************************************************************************
BNTnode *AVLTree::insert(BNTnode *root, int value){
    if (root == NULL){
        root = new BNTnode;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }else if (value < root->data){
        root->left = insert(root->left, value);
        root = balance (root);
    }else if (value >= root->data){
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}
 
//******************************************************************************
//                         Display all Sub Trees
//******************************************************************************
void AVLTree::display(BNTnode *ptr, int level){
    int i;
    if (ptr!=NULL){
        display(ptr->right, level + 1);
        cout<<endl;
        if (ptr == root)
        cout<<"R -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"     ";
        cout<<ptr->data;
        display(ptr->left, level + 1);
    }
}
 
//******************************************************************************
//                      In-order Output of Tree
//******************************************************************************
void AVLTree::inorder(BNTnode *tree){
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout<<tree->data<<"  ";
    inorder (tree->right);
}

//******************************************************************************
//                      Pre-order Output of Tree
//******************************************************************************
void AVLTree::preorder(BNTnode *tree){
    if (tree == NULL)
        return;
    cout<<tree->data<<"  ";
    preorder (tree->left);
    preorder (tree->right);
}
 
//******************************************************************************
//                      Post-order Output of Tree
//******************************************************************************
void AVLTree::postorder(BNTnode *tree){
    if (tree == NULL)
        return;
    postorder ( tree ->left );
    postorder ( tree ->right );
    cout<<tree->data<<"  ";
}

//******************************************************************************
//Helper function to find the maximum value node in the subtree rooted at `ptr`
//******************************************************************************
BNTnode* AVLTree::fndMxKey(BNTnode* ptr)
{
	while (ptr->right != nullptr) {
		ptr = ptr->right;
	}
	return ptr;
}
//******************************************************************************
// Function to delete a node from a BST. Note that root is passed by
// reference to the function//******************************************************************************
//******************************************************************************
void AVLTree::deleteBNT(BNTnode* &root, int key)
{
	// base case: the key is not found in the tree
	if (root == nullptr) {
		return;
	}

	// if the given key is less than the root node, recur for the left subtree
	if (key < root->data) {
		deleteBNT(root->left, key);
	}

	// if the given key is more than the root node, recur for the right subtree
	else if (key > root->data) {
		deleteBNT(root->right, key);
	}

	// key found
	else {
		// Case 1: node to be deleted has no children (it is a leaf node)
		if (root->left == nullptr && root->right == nullptr)
		{
			// deallocate the memory and update root to null
			delete root;
			root = nullptr;
		}

		// Case 2: node to be deleted has two children
		else if (root->left && root->right)
		{
			// find its inorder predecessor node
			BNTnode* predecessor = fndMxKey(root->left);

			// copy value of the predecessor to the current node
			root->data = predecessor->data;

			// recursively delete the predecessor. Note that the
			// predecessor will have at most one child (left child)
			deleteBNT(root->left, predecessor->data);
		}

		// Case 3: node to be deleted has only one child
		else {
			// choose a child node
			BNTnode* child = (root->left)? root->left: root->right;
			BNTnode* curr = root;

			root = child;

			// deallocate the memory
			delete curr;
		}
	}
}


#endif	/* AVLTREE_H */
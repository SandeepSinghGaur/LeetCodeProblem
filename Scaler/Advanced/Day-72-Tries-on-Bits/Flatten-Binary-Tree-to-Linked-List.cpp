/*
Problem Description
Given a binary tree A, flatten it to a linked list in-place.

The left child of all nodes should be NULL.

Problem Constraints
1 <= size of tree <= 100000

Input 1:

     1
    / \
   2   3

Input 2:

         1
        / \
       2   5
      / \   \
     3   4   6


Output 1:

1
 \
  2
   \
    3

Output 2:   

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/


#include<bits/stdc++.h>
using namespace std;


/* Definition for binary tree */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* flatten(TreeNode* A) {
      if (!A)
        return A;
    TreeNode* root = A;
    
    while (A)
    {
        if (A->left)
        {
            TreeNode* rightSubTree = A->left;
            while (rightSubTree->right)
                rightSubTree = rightSubTree->right;
            rightSubTree->right = A->right;
            A->right = A->left;
            A->left = NULL;
        }
        A = A->right;
    }
    return root;

}
 int main(){
    //create Node
    TreeNode *n1=new TreeNode(1);
    TreeNode *n2=new TreeNode(2);
    TreeNode *n3=new TreeNode(5);
    TreeNode *n4=new TreeNode(3);
    TreeNode *n5=new TreeNode(4);
    TreeNode *n6=new TreeNode(6);
  
    //Link the Node
    n1->right=n3;
    n1->left=n2;
    n2->left=n4;
    n2->right=n5;
    n3->right=n6;
    //call the helper function
 
   TreeNode* head=flatten(n1);
   while(head!=NULL){
       cout<<head->val<<" ";
       head=head->right;

   }
 }
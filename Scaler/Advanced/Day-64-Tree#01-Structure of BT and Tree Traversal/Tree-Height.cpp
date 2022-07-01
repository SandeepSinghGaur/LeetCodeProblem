/*
Problem Description
You are given the root node of a binary tree A. You have to find the height of the given tree.

A binary tree's height is the number of nodes along the longest path from the root node down to the farthest leaf node.

Problem Constraints
1 <= Number of nodes in the tree <= 10^5

0 <= Value of each node <= 10^9

Example Input
Input 1:
 Values =  1 
          / \     
         4   3 


Output
2
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

 int height_of_tree(TreeNode *root){
     if(root==NULL) return 0;
     int l=height_of_tree(root->left);
     int r=height_of_tree(root->right);
     return max(l,r)+1;
 }
int solve(TreeNode* A) {
    return height_of_tree(A);
}

 int main(){
    //create Node
    TreeNode *n1=new TreeNode(1);
    TreeNode *n3=new TreeNode(3);
    TreeNode *n4=new TreeNode(4);
  
    //Link the Node
    n1->right=n3;
    n1->left=n4;
    //call the helper function
    cout<<solve(n1);
  

 }

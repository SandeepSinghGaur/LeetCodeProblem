/*
Problem Description

You are given the root node of a binary tree A. You have to find the sum of node values of this tree.

Problem Constraints

1 <= Number of nodes in the tree <= 10^5

0 <= Value of each node <= 10^4

Example Input
Input 1:
 Values =  1 
          / \     
         4   3 


Output
8
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

 int sum_of_node_value(TreeNode* root){
    if(root==NULL) return 0;
    int sl=sum_of_node_value(root->left);
    int sr=sum_of_node_value(root->right);
    return sl+sr+root->val;
}
int solve(TreeNode* A) {
    return sum_of_node_value(A);
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

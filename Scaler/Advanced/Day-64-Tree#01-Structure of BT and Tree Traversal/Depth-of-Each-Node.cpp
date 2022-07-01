/*
Problem Description

You are given the root node of a binary tree A. Each node has a value val and depth depth.

Initially depth of each node is set to -1. You have to fill the depth of each node with its correct value.
Depth of a node T is the number of nodes along the longest path from the root node down to node T. Also, depth of root node is always equal to 1.

Problem Constraints

1 <= Number of nodes <= 10^5

0 <= Value of each node <= 10^9

Initially, Depth of each node(depth) is set to -1.

Example Input
Input 1:
Input 1:

 
 Values =  1        Depths = -1
          / \                / \
         4   3             -1  -1   
Output
  Values =  1        Depths =  1
          / \                / \
         4   3              2   2  
*/

#include<bits/stdc++.h>
using namespace std;


/* Definition for binary tree */
 struct TreeNode {
    int val;
    int depth;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), depth(-1), left(NULL), right(NULL) {}
};

void fill_depth(TreeNode *root,int depth){
  if(root==NULL) return;
  root->depth=depth;
  fill_depth(root->left,depth+1);
  fill_depth(root->right,depth+1);

}
void solve(TreeNode* A){
  fill_depth(A,1);
}

 int main(){
    //create Node
    TreeNode *n1=new TreeNode(1);
    TreeNode *n3=new TreeNode(3);
    TreeNode *n4=new TreeNode(4);

    n1->right=n3;
    n1->left=n4;
   
    //call the helper function
    solve(n1);
    

 }

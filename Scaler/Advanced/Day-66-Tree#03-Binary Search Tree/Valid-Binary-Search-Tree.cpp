/*
Problem Description
You are given a binary tree represented by root A.

Assume a BST is defined as follows:

1) The left subtree of a node contains only nodes with keys less than the node's key.

2) The right subtree of a node contains only nodes with keys greater than the node's key.

3) Both the left and right subtrees must also be binary search trees.

Problem Constraints
1 <= Number of nodes in binary tree <= 10^5

0 <= node values <= 10^9

Input 1:

 
   1
  /  \
 2    3


Input 2:

 
  2
 / \
1   3

Output 1:

 0

Output 2:

 1
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

bool checkBst(TreeNode *root,int min_val,int max_val){
    if(root==NULL) return true;
     if(!(root->val>=min_val && root->val<=max_val)) return false;
     return (checkBst(root->left,min_val,root->val-1) && checkBst(root->right,root->val+1,max_val));
 }

 int isValidBST(TreeNode* A) {
    if(checkBst(A,INT_MIN,INT_MAX)){
        return 1;
    }else return 0;
}

 int main(){
    //create Node
    TreeNode *n1=new TreeNode(1);
    TreeNode *n2=new TreeNode(2);
    TreeNode *n3=new TreeNode(3);
    //Link the Node
    n1->right=n3;
    n1->left=n2;
    vector<int>result;
    cout<<isValidBST(n1);
    
    

 }
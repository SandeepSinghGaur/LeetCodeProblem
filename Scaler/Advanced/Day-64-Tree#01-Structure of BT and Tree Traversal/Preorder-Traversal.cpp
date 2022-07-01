/*
Problem Description
Given a binary tree, return the preorder traversal of its nodes' values.

NOTE: Using recursion is not allowed.

Problem Constraints
1 <= number of nodes <= 10^5

Example Input
Input 1:

   1
    \
     2
    /
   3

Output
 [1, 2, 3]
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

vector<int>ans;
void preorder_traversal(TreeNode *root){
     if(root==NULL) return;
      ans.push_back(root->val);
     preorder_traversal(root->left);
     preorder_traversal(root->right);
 }
vector<int> preorderTraversal(TreeNode* A) {
    ans.clear();
    preorder_traversal(A);
    return ans;
}

 int main(){
    //create Node
    TreeNode *n1=new TreeNode(1);
    TreeNode *n2=new TreeNode(2);
    TreeNode *n3=new TreeNode(3);
    //Link the Node
    n1->right=n2;
    n2->left=n3;
    vector<int>result;
    result=preorderTraversal(n1);
    for(auto it:result){
        cout<<it<<" ";
    }

 }

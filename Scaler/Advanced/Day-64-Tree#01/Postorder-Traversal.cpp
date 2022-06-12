/*
Problem Description
Given a binary tree, return the Postorder traversal of its nodes' values.

NOTE: Using recursion is not allowed.

Problem Constraints
1 <= number of nodes <= 10^5

Example Input
Input 1:

  1
  / \
 6   2
    /
   3
Output
 [6, 3, 2, 1]
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
void post_order_traversal(TreeNode *root){
     if(root==NULL) return;
     post_order_traversal(root->left);
     post_order_traversal(root->right);
     ans.push_back(root->val);
 }
vector<int> postorderTraversal(TreeNode* A) {
    ans.clear();
    post_order_traversal(A);
    return ans;
}

 int main(){
    //create Node
    TreeNode *n1=new TreeNode(1);
    TreeNode *n2=new TreeNode(2);
    TreeNode *n3=new TreeNode(3);
    TreeNode *n4=new TreeNode(6);
    //Link the Node
    n1->right=n2;
    n1->left=n4;
    n2->left=n3;
    vector<int>result;
    result=postorderTraversal(n1);
    for(auto it:result){
        cout<<it<<" ";
    }

 }

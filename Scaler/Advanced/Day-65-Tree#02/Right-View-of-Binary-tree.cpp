/*
Problem Description
Given a binary tree of integers denoted by root A. Return an array of integers representing the right view of the Binary tree.

Right view of a Binary Tree is a set of nodes visible when the tree is visited from Right side.

Problem Constraints
1 <= Number of nodes in binary tree <= 100000

0 <= node values <= 10^9

Input 1:

 
            1
          /   \
         2    3
        / \  / \
       4   5 6  7
      /
     8


Output
 [1, 3, 7, 8]
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
 void right_view_bt(TreeNode *root){
     if(root==NULL) return;
     queue<TreeNode *>q;
     q.push(root);
     while(!q.empty()){
         int sz=q.size();
         for(int i=1;i<=sz;i++){
            TreeNode *temp=q.front();
            q.pop();
            if(i==1)
            ans.push_back(temp->val);
            if(temp->right!=NULL) q.push(temp->right);
            if(temp->left!=NULL) q.push(temp->left);
         }
     }
 }
vector<int> solve(TreeNode* A) {
    ans.clear();
    right_view_bt(A);
    return ans;
}

 int main(){
    //create Node
    TreeNode *n1=new TreeNode(1);
    TreeNode *n2=new TreeNode(2);
    TreeNode *n3=new TreeNode(3);
    TreeNode *n4=new TreeNode(4);
    TreeNode *n5=new TreeNode(5);
    TreeNode *n6=new TreeNode(6);
    TreeNode *n7=new TreeNode(7);
    TreeNode *n8=new TreeNode(8);
  
    //Link the Node
    n1->right=n3;
    n1->left=n2;
    n2->left=n4;
    n2->right=n5;
    n3->left=n6;
    n3->right=n7;
    n4->left=n8;
    //call the helper function
    vector<int>result;
    result=solve(n1);
    for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
    }
  

 }

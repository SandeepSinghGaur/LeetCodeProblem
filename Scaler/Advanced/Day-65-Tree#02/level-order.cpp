/*
Problem Description
Given a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Problem Constraints
1 <= number of nodes <= 10^5

Input 1:

    3
   / \
  9  20
    /  \
   15   7

Output
 [
   [3],
   [9, 20],
   [15, 7]
 ]
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

  vector<vector<int>>ans;
void lot(TreeNode *root){
     if(root==NULL) return ;
     queue<TreeNode *>q;
     q.push(root);
     vector<int>v;
     while(!q.empty()){
         v.clear();
         int sz=q.size();
         for(int i=0;i<sz;i++){
             TreeNode *temp=q.front(); 
             q.pop();
             v.push_back(temp->val);
             if(temp->left!=NULL) q.push(temp->left);
             if(temp->right!=NULL) q.push(temp->right);
         }
         ans.push_back(v);
     }
 }
vector<vector<int> > levelOrder(TreeNode* A) {
    ans.clear();
     lot(A);
     return ans;
}

 int main(){
    //create Node
    TreeNode *n1=new TreeNode(3);
    TreeNode *n2=new TreeNode(9);
    TreeNode *n3=new TreeNode(20);
    TreeNode *n4=new TreeNode(15);
    TreeNode *n5=new TreeNode(7);
  
    //Link the Node
    n1->right=n3;
    n1->left=n2;
    n3->left=n4;
    n3->right=n5;
    //call the helper function
    vector<vector<int>>result;
    result=levelOrder(n1);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
  

 }

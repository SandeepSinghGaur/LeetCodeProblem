/*
Problem Description
Given a binary tree of integers denoted by root A. Return an array of integers representing the top view of the Binary tree.

The top view of a Binary Tree is a set of nodes visible when the tree is visited from the top.

Return the nodes in any order.


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
 [1, 2, 4, 8, 3, 7]     
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

 vector<int>tov(TreeNode *root){
     unordered_map<int,TreeNode*>mp;
       queue<pair<TreeNode*,int>>q;
       int minl=INT_MAX,maxl=INT_MIN;
       q.push({root,0});
       while(!q.empty()){
           auto p=q.front();
           q.pop();
           TreeNode *temp=p.first;
           int level=p.second;
           minl=min(minl,level);
           maxl=max(maxl,level);
           if(mp.find(level)==mp.end()){
               mp.insert({level,temp});
           }
           if(temp->left){
               q.push({temp->left,level-1});
           }
           if(temp->right){
               q.push({temp->right,level+1});
           }

       }
       vector<int>ans;
       for(int i=minl;i<=maxl;i++){
           int key=mp[i]->val;
           ans.push_back(key);
       }
       return ans;
 }
vector<int> top_view(TreeNode* A) {
     return tov(A);
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
   result=top_view(n1);
    for(int i=0;i<result.size();i++){
      cout<<result[i]<<" ";
    }
  
  

 }
/*
Problem Description

Given a Binary Tree A consisting of N integer nodes, you need to print the bottom view from left to right.

A node x is there in output if x is the bottom-most node at its horizontal distance.

Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1.

Note: If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal.


Problem Constraints

0 <= N <= 10^5

Input:1

                      20
                    /    \
                  8       22
                /   \      \
              5      3      25
                    / \      
                  10    14

Input:2

                      20
                    /    \
                  8       22
                /   \    /   \
              5      3  4    25
                    / \      
                  10    14

Output:1

 [5, 10, 3, 14, 25]

Output:2

 [5, 10, 4, 14, 25]
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
           mp[level]=temp;
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
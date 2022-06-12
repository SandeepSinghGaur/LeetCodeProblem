/*
Problem Description
Given a Binary Tree A containing N nodes, you need to find the path from Root to a given node B.

NOTE:

No two nodes in the tree have the same data values.
You can assume that B is present in tree A and a path always exists.

Problem Constraints
1 <= N <= 10^5

1 <= Data Values of Each Node <= N

1 <= B <= N

Example Input
Input 1:
 A =     
           1
         /   \
        2     3
       / \   / \
      4   5 6   7 

 B = 5
Output
 [1, 2, 5]
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

  vector<int>path;
  vector<int>ans;
void get_path(TreeNode *root,int K){
    if(root==NULL) return;
    path.push_back(root->val);
    if(root->val==K){
        ans=path;
        return;
    }
    get_path(root->left,K);
    get_path(root->right,K);
    path.pop_back();
 }
vector<int>solve(TreeNode* A, int B) {
  path.clear();
  ans.clear();
  get_path(A,B);
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
    //Link the Node
    n1->right=n3;
    n1->left=n2;
    n2->left=n4;
    n2->right=n5;
    n3->left=n6;
    n3->right=n7;
    //call the helper function
    vector<int>result;
    result=solve(n1,5);
    for(auto it:result){
        cout<<it<<" ";
    }

 }

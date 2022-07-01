/*
Problem Description
Given a binary tree, return the zigzag level order traversal of its nodes values. (ie, from left to right, then right to left for the next level and alternate between).

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
   [20, 9],
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
void zigzag(TreeNode *root){
     if(root==NULL) return ;
     queue<TreeNode *>q;
     stack<int>st;
     q.push(root);
     vector<int>v;
     int k=0;
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
         if(k%2==0){
            ans.push_back(v);
         }else{
             for(int i=0;i<v.size();i++){
                 st.push(v[i]);
             }
             int p=0;
             while(!st.empty()){
               int ele=st.top();
               st.pop();
               v[p]=ele;
               p++;
             }
              ans.push_back(v);
         }
         k++; 
     }
 }
vector<vector<int> > zigzagLevelOrder(TreeNode* A) {
    ans.clear();
    zigzag(A);
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
    result=zigzagLevelOrder(n1);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
  

 }

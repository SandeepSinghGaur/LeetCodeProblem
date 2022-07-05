/*
Problem Description
You are given an integer array A denoting the Level Order Traversal of the Binary Tree.

You have to Deserialize the given Traversal in the Binary Tree and return the root of the Binary Tree.

NOTE:

In the array, the NULL/None child is denoted by -1.
For more clarification check the Example Input.

Problem Constraints
1 <= number of nodes <= 10^5

-1 <= A[i] <= 10^5

Input 1:

 A = [1, 2, 3, 4, 5, -1, -1, -1, -1, -1, -1]


Input 2:

 A = [1, 2, 3, 4, 5, -1, 6, -1, -1, -1, -1, -1, -1]

 Output 1:

           1
         /   \
        2     3
       / \
      4   5
Output 2:

            1
          /   \
         2     3
        / \ .   \
       4   5 .   6
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
void serialize_bt(TreeNode *root){
    if(root==NULL) return;
    queue<TreeNode *>q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto p=q.front();
            if(p==NULL){
               q.pop();
               ans.push_back(-1);
            }else{
                 q.pop();
                 ans.push_back(p->val);
            }
            if(p!=NULL && p->left!=NULL) q.push(p->left);
             if( p!=NULL && p->left==NULL) q.push(NULL);
            if(p!=NULL && p->right!=NULL) q.push(p->right);
            if(p!=NULL && p->right==NULL) q.push(NULL);
           
        }
    }
}
vector<int> solve(TreeNode* A) {
    ans.clear();
    serialize_bt(A);
    return ans;
}

 int main(){
    //create Node
    TreeNode *n1=new TreeNode(1);
    TreeNode *n2=new TreeNode(2);
    TreeNode *n3=new TreeNode(3);
    TreeNode *n4=new TreeNode(4);
    TreeNode *n5=new TreeNode(5);
    //Link the Node
    n1->left=n2;
    n1->right=n3;
    n2->left=n4;
    n2->right=n5;
    vector<int>result;
    result=solve(n1);
    for(auto it:result){
        cout<<it<<" ";
    }

 }

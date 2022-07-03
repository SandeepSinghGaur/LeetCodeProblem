/*
Problem Description
Given preorder and inorder traversal of a tree, construct the binary tree.

NOTE: You may assume that duplicates do not exist in the tree.

Problem Constraints
1 <= number of nodes <= 10^5

Input 1:

 A = [1, 2, 3]
 B = [2, 1, 3]


Input 2:

 A = [1, 6, 2, 3]
 B = [6, 1, 3, 2]

 Output 1:

   1
  / \
 2   3

Output 2:

   1  
  / \
 6   2
    /
   3
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

 TreeNode * cbt(vector<int>&pre,int ps,int pe,vector<int>&In,int is,int ie){
       if(ps>pe) return NULL;
       int node_val=pre[ps];
       TreeNode *root=new TreeNode(node_val);
       int id=pre_map[node_val];
       root->left=cbt(pre,ps+1,ps+id-is,In,is,id-1);
       root->right=cbt(pre,ps+id-is+1,pe,In,id+1,ie);
       return root;
       
       


    
 }
 unordered_map<int,int>in_map;
 unordered_map<int,int>pre_map;
TreeNode* buildTree(vector<int> &A, vector<int> &B) {
     in_map.clear();
     pre_map.clear();
     for(int i=0;i<B.size();i++){
        in_map.insert({B[i],i});
     }
     for(int i=0;i<A.size();i++){
        int index=in_map[A[i]];
        pre_map.insert({A[i],index});
     }
    return cbt(A,0,A.size()-1,B,0,B.size()-1);
}
 int main(){
     vector<int>pre={8,6,3,1,4,2,5,7};
     vector<int>in={3,6,1,8,5,2,4,7};
   
    //call the helper function
    TreeNode * root=buildTree(pre,in);
    

 }

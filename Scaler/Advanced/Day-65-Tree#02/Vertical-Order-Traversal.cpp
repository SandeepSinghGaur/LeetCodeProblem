/*
Given a binary tree, return a 2-D array with vertical order traversal of it. Go through the example and image for more details.


NOTE: If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.


Problem Constraints
0 <= number of nodes <= 10^5

Input 1:

      6
    /   \
   3     7
  / \     \
 2   5     9

Output 1:

 [
    [2],
    [3],
    [6, 5],
    [7],
    [9]
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

 vector<vector<int>>vot(TreeNode *root){
     unordered_map<int, vector<TreeNode*>> mp;
    queue<pair<TreeNode*,int>> q;
    vector<vector<int>> ans;
    vector<int> aux;
    int minl=0, maxl=0;
    q.push({root, 0});
    while(!q.empty()){
        pair<TreeNode*, int> temp=q.front();
        q.pop();
        TreeNode* curr=temp.first;
        int level=temp.second;
        maxl=max(maxl, level);
        minl=min(minl, level);
        mp[level].push_back(curr);
        if(curr->left!=NULL){
            q.push({curr->left, level-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right, level+1});
        }
    }
    for(int i=minl;i<=maxl;i++){
        for(int j=0;j<mp[i].size();j++){
            aux.push_back(mp[i][j]->val);
        }
        ans.push_back(aux);
        aux.clear();
    }

    return ans;
 }
vector<vector<int>> vertical_order_traversal(TreeNode* A) {
     return vot(A);
}

 int main(){
    //create Node
    TreeNode *n1=new TreeNode(6);
    TreeNode *n2=new TreeNode(3);
    TreeNode *n3=new TreeNode(7);
    TreeNode *n4=new TreeNode(2);
    TreeNode *n5=new TreeNode(5);
    TreeNode *n6=new TreeNode(9);
  
    //Link the Node
    n1->right=n2;
    n1->left=n3;
    n2->left=n4;
    n2->right=n5;
    n3->left=n6;
    n3->right=n6;
    //call the helper function
  vector<vector<int>>result;
    result=vertical_order_traversal(n1);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
  
  

 }
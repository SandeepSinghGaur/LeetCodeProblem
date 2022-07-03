/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Input: root = [2,1], p = 2, q = 1
Output: 2


Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.
*/

#include<bits/stdc++.h>
using namespace std;
/* Definition for binary tree*/
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*-----------------------------------------------------*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
    }
int main(){
    //Create the Tree Node
   TreeNode *n1=new TreeNode(6);
   TreeNode *n2=new TreeNode(2);
   TreeNode *n3=new TreeNode(8);
   TreeNode *n4=new TreeNode(0);
   TreeNode *n5=new TreeNode(4);
   TreeNode *n6=new TreeNode(7);
   TreeNode *n7=new TreeNode(9);
   TreeNode *n8=new TreeNode(3);
   TreeNode *n9=new TreeNode(5);
   //Link That Node
   n1->left=n2;
   n1->right=n3;
   n2->left=n4;
   n2->right=n5;
   n3->left=n6;
   n3->right=n7;
   n5->left=n8;
   n5->right=n9;
   int p=2,q=8;
   TreeNode *lca_Node=lowestCommonAncestor(n1,n2,n3);
   cout<<lca_Node->val<<" ";

}
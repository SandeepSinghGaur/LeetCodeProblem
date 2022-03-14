
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL),right(NULL) {}
  };

  TreeNode *root=NULL;
  int size_of_tree=0;
  vector<int>v;
  vector<int>ans;
  void preorder_traversal(TreeNode *root,int B ){
      if(root==NULL)
         return;
      v.push_back(root->val);
      if(root->val==B){
          for(int num:v){
              ans.push_back(num);
              size_of_tree++;
          }
        return;
      }
        
      preorder_traversal(root->left,B);
      preorder_traversal(root->right,B);
      v.pop_back();  
  }

vector<int> solve(TreeNode* A, int B) {
    preorder_traversal(A,B);
    return ans;
    
}
int main(){
    TreeNode *temp;
    root=NULL;
    size_of_tree=0;
    TreeNode *newNode=new TreeNode(1);
    root=newNode;
    TreeNode *second=new TreeNode(2);
    root->left=second;
    TreeNode *third=new TreeNode(3);
    root->right=third;
    TreeNode *fourth=new TreeNode(4);
    second->left=fourth;
    TreeNode *fifth=new TreeNode(5);
    second->right=fifth;
    TreeNode *sithx=new TreeNode(6);
    third->left=sithx;
    TreeNode *seventh=new TreeNode(7);
    third->right=seventh;
    vector<int>res;
    res=solve(root,5);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
   
}

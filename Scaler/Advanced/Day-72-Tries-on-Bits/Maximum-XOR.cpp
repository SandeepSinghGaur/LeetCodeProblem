/*
Problem Description
Given an array of integers A, find and return the maximum result of A[i] XOR A[j], where i, j are the indexes of the array.

Problem Constraints
1 <= length of the array <= 100000
0 <= A[i] <= 10^9


Input
 A = [1, 2, 3, 4, 5]
Output
7
*/


#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode *left;
    TrieNode *right;
    TrieNode() : left(NULL),right(NULL) {}
};

void insert_into_trie(TrieNode *root,int n){
    TrieNode *curr=root;
    for(int i=30;i>=0;i--){
        //check set bit
        if((n>>i)&1==1){
            if(curr->right==NULL){
            curr->right=new TrieNode();
            }
             curr=curr->right;
        }else{
              if(curr->left==NULL){
                curr->left=new TrieNode();
            }
            curr=curr->left;
        }
    }
}

int find_max_XOR(TrieNode *root, vector<int>&A){
    int ans=INT_MIN;
    for(int i=0;i<A.size();i++){
        int curr_xor=0;
        TrieNode *curr=root;
        for (int j = 30; j >= 0; j--) {
            int x=(A[i]>>j)&1;
            if(x==1){
                if(curr->left==NULL){
                  curr = curr->right;
                }else{
                    curr_xor+=(1<<j);
                    curr = curr->left;
                }
            }else{
                 if(curr->right==NULL){
                   curr = curr->left;
                }else{
                    curr_xor+=(1<<j);
                    curr = curr->right;
                }
            }
 
        }
        ans = max(ans, curr_xor);
       
    }
    return ans;
}
int solve(vector<int> &A) {
    TrieNode *dummy=new TrieNode();
    for(int i=0;i<A.size();i++){
        insert_into_trie(dummy,A[i]);
    }
    return find_max_XOR(dummy,A);
}
 int main(){
    vector<int>v={1, 2, 3, 4, 5};
    cout<<solve(v);
    

 }

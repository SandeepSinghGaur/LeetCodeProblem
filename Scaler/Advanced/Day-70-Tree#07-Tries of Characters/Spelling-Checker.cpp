/*
Problem Description
Given an array of words A (dictionary) and another array B (which contain some words).

You have to return the binary array (of length |B|) as the answer where 1 denotes that the word is present in the dictionary and 0 denotes it is not present.

Formally, for each word in B, you need to return 1 if it is present in Dictionary and 0 if not.

Such problems can be seen in real life when we work on any online editor (like Google Documnet), if the word is not valid it is underlined by a red line.

NOTE: Try to do this in O(n) time complexity.

Problem Constraints
1 <= |A| <= 1000

1 <= sum of all strings in A <= 50000

1 <= |B| <= 1000

Input 1:

A = [ "hat", "cat", "rat" ]
B = [ "cat", "ball" ]

Input 2:

A = [ "tape", "bcci" ]
B = [ "table", "cci" ]

Output 1:

[1, 0]


Output 2:

[0, 0]
*/


#include<bits/stdc++.h>
using namespace std;


struct TrieNode{
    unordered_map<char,TrieNode*>child;
    bool isFind;
    int count;
    TrieNode() : isFind(false),count(0),child(NULL) {}
};
void insert_into_trie(TrieNode *root,string str){
    TrieNode *curr=root;
    for(int i=0;i<str.length();i++){
        if(curr->child.find(str[i])==curr->child.end()){
           curr->child[str[i]]=new TrieNode();
        }
        curr=curr->child[str[i]];
    }
    curr->isFind=true;
}
bool find_word(TrieNode *root,string str){
    TrieNode *curr=root;
    for(int i=0;i<str.length();i++){
        if(curr->child.find(str[i])==curr->child.end()){
            return false;
        }
        curr=curr->child[str[i]];
    }
    if(curr->isFind){
        return true;
    }
    return false;
}
vector<int> solve(vector<string> &A, vector<string> &B) {
    vector<int>ans;
    TrieNode *dummy=new TrieNode();
    for(int i=0;i<A.size();i++){
        insert_into_trie(dummy,A[i]);
    }
    for(int i=0;i<B.size();i++){
       if(find_word(dummy,B[i])){
           ans.push_back(1);
       }else{
           ans.push_back(0);
       }
    }
    return ans;

}
 int main(){
    vector<string>v1={"hat", "cat", "rat"};
    vector<string>v2={"cat", "ball"};
    vector<int>result;
    result=solve(v1,v2);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    
 }
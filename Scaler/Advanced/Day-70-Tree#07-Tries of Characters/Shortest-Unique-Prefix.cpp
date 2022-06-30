/*
Problem Description
Given a list of N words, find the shortest unique prefix to represent each word in the list.

NOTE: Assume that no word is the prefix of another. In other words, the representation is always possible

Problem Constraints
1 <= Sum of length of all words <= 10^6

Input 1:

 A = ["zebra", "dog", "duck", "dove"]


Input 2:

A = ["apple", "ball", "cat"]

Output 1:

 ["z", "dog", "du", "dov"]


Output 2:

 ["a", "b", "c"]
*/



#include<bits/stdc++.h>
using namespace std;


vector<string>ans;
struct TrieNode{
    unordered_map<char,TrieNode*>child;
    bool isFind;
    int count;
    TrieNode(int count) : isFind(false),count(count),child(NULL) {}
};
void insert_into_trie(TrieNode *root,string str){
    TrieNode *curr=root;
    for(int i=0;i<str.length();i++){
        if(curr->child.find(str[i])==curr->child.end()){
           curr->child[str[i]]=new TrieNode(0);
        }
        curr=curr->child[str[i]];
        curr->count=curr->count+1;
    }
    curr->isFind=true;
}

void shortest_unique_prefix(TrieNode *root,string str){
    TrieNode *curr=root;
    string result="";
    for(int i=0;i<str.length();i++){
        if(curr->child.find(str[i])!=curr->child.end()){
            result.push_back(str[i]);
            TrieNode *temp=curr->child[str[i]];
            if(temp->count==1){
               ans.push_back(result);
               return;
            }
        }
        curr=curr->child[str[i]];
    }
}
vector<string> prefix(vector<string> &A) {
    ans.clear();
     TrieNode *dummy=new TrieNode(0);
    for(int i=0;i<A.size();i++){
        insert_into_trie(dummy,A[i]);
    }
    for(int i=0;i<A.size();i++){
        shortest_unique_prefix(dummy,A[i]);
    }
    return ans;
}
 int main(){
    vector<string>v1={"zebra", "dog", "duck", "dove"};
    vector<string>result;
    result=prefix(v1);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    
 }
/*
We want to make a custom contacts finder applications as part of our college project. The application must perform two types of operations:

Type 1: Add name B[i] ,denoted by 0 in vector A where B[i] is a string in vector B denoting a contact name. This must store B[i] as a new contact in the application.

Type 2: Find partial for B[i] ,denoted by 1 in vector A where B[i] is a string in vector B denoting a partial name to search the application for. It must count the number of contacts starting with B[i].

You have been given sequential add and find operations. You need to perform each operation in order.

And return as an array of integers, answers for each query of type 2(denoted by 1 in A) .


Problem Constraints

1 <= |A| <= 10000

1 <= |length of strings in B| <= 10


Input 1:

A = [0, 0, 1, 1]
B = ["hack", "hacker", "hac", "hak"]


Input 2:

A = [0, 1]
B = ["abcde", "abc"]

Output 1:

 
[2, 0]


Output 2:

[1]
*/

#include<bits/stdc++.h>
using namespace std;


struct TrieNode{
    unordered_map<char,TrieNode*>child;
    int count;
    bool isFind;
    TrieNode(int count):count(count),isFind(false),child(NULL){}
};
void insert_into_Tries(TrieNode *root,string s){
    TrieNode *curr=root;
    for(int i=0;i<s.length();i++){
        if(curr->child.find(s[i])==curr->child.end()){
            curr->child[s[i]]= new TrieNode(0);
        }

        curr=curr->child[s[i]];
        curr->count=curr->count+1;
    }
    curr->isFind=true;
}

int find_word(TrieNode *root,string s){
   TrieNode *curr=root;
   for(int i=0;i<s.length();i++){
       if(curr->child.find(s[i])==curr->child.end()){
           return 0;
       }else{
           curr=curr->child[s[i]];
       }
   }
   return curr->count;
}
vector<int> solve(vector<int> &A, vector<string> &B) {
    TrieNode* dummy=new TrieNode(0);
    vector<int>ans;
    for(int i=0;i<A.size();i++){
        if(A[i]==0){
            insert_into_Tries(dummy,B[i]);
        }
        if(A[i]==1){
            int k=find_word(dummy,B[i]);
            ans.push_back(k);
        }
    }
    return ans;
}
 int main(){
    vector<int>v1={0, 0, 1, 1};
    vector<string>v2={"hack", "hacker", "hac", "hak"};
    vector<int>result;
    result=solve(v1,v2);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    
 }
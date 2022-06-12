/*
Problem Description
Given a string A denoting a stream of lowercase alphabets, you have to make a new string B.
B is formed such that we have to find the first non-repeating character each time a character is inserted to the stream and append it at the end to B. If no non-repeating character is found, append '#' at the end of B.

Problem Constraints
1 <= |A| <= 100000

Input
A = "abadbc"

Output
"aabbdd"
*/
#include<bits/stdc++.h>
using namespace std;


string solve(string A) {
    string ans="";
    unordered_map<char,int>um;
    queue<char>q;
    for(int i=0;i<A.length();i++){
     um[A[i]]++;
     if(um[A[i]]==1)
     q.push(A[i]);
     while(!q.empty() && um[q.front()]>1){
            q.pop();
     }
     if(q.empty()){
         ans.push_back('#');
     }
     if(um[q.front()]==1){
         ans.push_back(q.front());
     }
    }
    return ans;

}
int main(){
string str="abcabc";
cout<<solve(str);
}
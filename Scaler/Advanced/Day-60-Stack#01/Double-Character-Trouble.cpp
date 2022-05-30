/*
Problem Description
You are given a string A.

An operation on the string is defined as follows:

Remove the first occurrence of the same consecutive characters. eg for a string "abbcd", the first occurrence of same consecutive characters is "bb".

Therefore the string after this operation will be "acd".

Keep performing this operation on the string until there are no more occurrences of the same consecutive characters and return the final string.


Problem Constraints
1 <= |A| <= 100000

Input
A = abccbc
Output
"ac"

*/

#include<bits/stdc++.h>
using namespace std;
string solve(string A){
     int n=A.length();
    stack<char>s;
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
          s.push(A[i]);
        }
        else if(s.top()==A[i]){
            s.pop();
        }else{
            s.push(A[i]);
        }
    }
      string res="";
    int ss=s.size();
    cout<<ss<<endl;
    for(int i=0;i<ss;i++){
        res+=s.top();
        s.pop();
    }
    return res;
     
}
int main(){
    string A="abccbc";
    string res=solve(A);
    for(int i=0;i<res.length();i++){
        cout<<res[i]<<" ";
    }
}
/*
Problem Description

Given two strings A and B. Check if B contains same characters as that of given string A and in the same order.

Problem Constraints

1: A and B contain only UPPERCASE Letters.
2: No two consecutive characters are same in A.
3: You can only use constant amount of extra memory.

Input
A = "HIRED" 
B = "HHHIIIRRRRREEEEEDDDDD"
Output
1
*/
#include<bits/stdc++.h>
using namespace std;

int solve(const string A, const string B) {
    int j=1;
    if(A[0]!=B[0]|| A.length()>B.length()){
        return 0;
    }
    for(int i=1;i<B.length()||j<A.length();i++){
       if(B[i]==B[i-1]){
           continue;
       }else{
           if(B[i]==A[j]){
               j++;
           }else{
               return 0;
           }
       }
    }
    return 1;
}
int main(){
    string A="HIRED";
    string B="HHHIIIRRRRREEEEEDDDDD";
    cout<<solve(A,B);
}
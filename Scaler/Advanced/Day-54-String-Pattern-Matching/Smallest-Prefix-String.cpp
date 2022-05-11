/*
Problem Description
Given 2 strings A and B of size N and M respectively consisting of lowercase alphabets, find the lexicographically smallest string that can be formed by concatenating non-empty prefixes of A and B (in that order).
Note: The answer string has to start with a non-empty prefix of string A followed by a non-empty prefix of string B.

Problem Constraints
1 <= N, M <= 100000

Input
 A = "abba"
 B = "cdd"
Output
"abbac"
*/

#include<bits/stdc++.h>
using namespace std;

string smallestPrefix(string A, string B) {
      string result="";
    result+=A[0];
    for(int i=1;i<A.length();i++){
        if(A[i]<B[0]){
           result+=A[i];
        }
        else if(A[i]==B[0]){
            result+=A[i];
            break;
        }else{
            break;
        }
    }
    if(result.back()==B[0] && result.length()!=1){
        return result;
    }
    result+=B[0];
    return result;
}
int main(){
    string A="abba";
    string B="cdd";
    cout<<smallestPrefix(A,B);
}
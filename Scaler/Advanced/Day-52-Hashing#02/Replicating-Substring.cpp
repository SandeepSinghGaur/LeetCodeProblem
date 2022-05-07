/*
Problem Description

Given a string B, find if it is possible to re-order the characters of the string B so that it can be represented as a concatenation of A similar strings.

Eg: B = aabb and A = 2, then it is possible to re-arrange the string as "abab" which is a concatenation of 2 similar strings "ab".

If it is possible, return 1, else return -1.


Problem Constraints

1 <= Length of string B <= 1000

1 <= A <= 1000

All the alphabets of S are lower case (a - z)

Input
A = 2
B = "bbaabb"
Output
1
*/
#include<bits/stdc++.h>
using namespace std;
int solve(int A, string B) {
     if(A==1)
    return 1;
    if(B.length()<A)
    return -1;
    if(B.length()%2!=0 && A%2==0)
    return -1;
    if(B.length()%2==0 && A%2!=0)
    return -1;
     unordered_map<char,int>um;
    for(int i=0;i<B.length();i++){
        um[B[i]]++;
    }
    int len_of_concatation=B.length()/A;
    int check=0;
    for(auto it:um){
       check+=it.second/A;
    }
    if(check==len_of_concatation)
    return 1;
    return -1;
}

int main(){
   string B="bbaabb";
   cout<<solve(2,B);
}
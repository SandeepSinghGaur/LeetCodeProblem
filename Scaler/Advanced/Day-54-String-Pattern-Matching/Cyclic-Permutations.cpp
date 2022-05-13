/*
Problem Description
Given two binary strings A and B, count how many cyclic permutations of B when taken XOR with A give 0.

NOTE: If there is a string, S0, S1, ... Sn-1 , then it is a cyclic permutation is of the form Sk, Sk+1, ... Sn-1, S0, S1, ... Sk-1 where k can be any integer from 0 to N-1.

Problem Constraints
1 ≤ length(A) = length(B) ≤ 10^5

Input
 A = "1001"
 B = "0011"
Output
 1
*/
#include<bits/stdc++.h>
using namespace std;

int solve(string A, string B) {
  string text=B;
  for(int i=0;i<B.length()-1;i++){
      text+=B[i];
  }
  text=A+"@"+text;
  int n=2*B.length()+A.length();
  //KMP Algo
    vector<int>lps(n,0);
    for(int i=1;i<n;i++){
        int x=lps[i-1];
        while(text[i]!=text[x]){
            if(x==0){x=-1;break;}
            x=lps[x-1];
        }
        lps[i]=x+1;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(lps[i]==A.length()){
            ans++;
        }
    }
    return ans;
  }
int main(){
    string A="1001";
    string B="0011";
   cout<<solve(A,B);
}
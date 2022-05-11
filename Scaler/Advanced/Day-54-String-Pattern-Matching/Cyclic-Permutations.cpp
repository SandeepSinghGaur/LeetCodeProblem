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
int main(){
    int a=1;
    int b=0;
    cout<<(a^b);
}
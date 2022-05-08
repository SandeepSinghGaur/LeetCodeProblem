/*
Problem Description
Given an array of integers A, find and return whether the given array contains a non-empty subarray with a sum equal to 0.

If the given array contains a sub-array with sum zero return 1, else return 0.

Problem Constraints
1 <= |A| <= 10^5

-10^9 <= A[i] <= 10^9

Input
A = [1, 2, 3, 4, 5]
Output
0

*/
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&A){
    vector<long long>pf(A.size());
    pf[0]=A[0];
    for(int i=1;i<A.size();i++){
        pf[i]=A[i]+pf[i-1];
    }
    for(int i=0;i<A.size();i++){
        if(pf[i]==0)
        return 1;
    }
    unordered_map<long long,int>um;
    for(int i=0;i<A.size();i++){
        um[pf[i]]++;
    }
    for(auto it:um){
        if(it.second>1){
            return 1;
        }
    }
    return 0;
}
int main(){
    vector<int>v={-1, 1};
    cout<<solve(v);
}
/*
Problem Description
Given two arrays of integers A and B of size N each, 
where each pair (A[i], B[i]) for 0 <= i < N represents a unique point (x, y) in 2D Cartesian plane.

Find and return the number of unordered triplets (i, j, k) such that (A[i], B[i]), (A[j], B[j]) and (A[k], B[k]) 
form a right-angled triangle with the triangle having one side parallel to the x-axis and one side parallel to the y-axis.

NOTE: The answer may be large so return the answer modulo (10^9 + 7).

Problem Constraints
1 <= N <= 10^5

0 <= A[i], B[i] <= 10^9

Input
A = [1, 1, 2]
B = [1, 2, 1]

A = [1, 1, 2, 3, 3]
B = [1, 2, 1, 2, 1]
Output
1
6
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=(int)(1e9+7);
int solve(vector<int> &A, vector<int> &B) {
    int n=A.size();
    unordered_map<int,int>umx;
    for(int i=0;i<n;i++){
      umx[A[i]]++;
    }
    unordered_map<int,int>umy;
    for(int i=0;i<n;i++){
      umy[B[i]]++;
    }
    int count=0;
    for(int i=0;i<n;i++){
        int cx=umx[A[i]]-1;
        int cy=umy[B[i]]-1;
        count=count+(cx%mod*cy%mod)%mod;
    }
    return count;

}
int main(){
    vector<int>A={1, 1, 2, 3, 3};
    vector<int>B={1, 2, 1, 2, 1};
    cout<<solve(A,B);
}

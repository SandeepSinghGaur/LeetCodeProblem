/*
Problem Description
Given a sorted array of integers A where every element appears twice except for one element which appears once, find and return this single element that appears only once.

NOTE: Users are expected to solve this in O(log(N)) time.



Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 10^9

Input
A = [1, 1, 7]
Output
7
*/

#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &A) {
    int res=A[0];
 for(int i=1;i<A.size();i++){
     res=res^A[i];
 }
 return res;
}
int main(){
    vector<int>arr={5, 11, 11, 100, 100};
   cout<<solve(arr);
}
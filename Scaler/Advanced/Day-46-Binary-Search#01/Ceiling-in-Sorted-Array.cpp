/*
Problem Description
Given a sorted array B of integers of size A, and a integer value C, return the ceiling of C which is present in array B.


Problem Constraints
1 <= A <= 10^5,
-10^9 <= B[i] <= 10^9,
-10^9 <= C <= 10^9

Input
A = 5
B = [2, 5, 6, 9, 18]
C = 7
Output
9
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int A, vector<int> &B, int C) {
    int low=0,high=A-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(B[mid]==C){
            return B[mid];
        }else if(B[mid]>C){
            ans=B[mid];
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int>A={2, 5, 6, 9, 18};
    cout<<solve(5,A,7);
}
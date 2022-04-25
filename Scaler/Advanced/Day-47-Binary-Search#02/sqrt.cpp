/*
Problem Description

Given an integer A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM THE STANDARD LIBRARY.

NOTE: Do not use the sqrt function from the standard library. Users are expected to solve this in O(log(A)) time.

Problem Constraints
0 <= A <= 10^10

Input
11
Output
3
*/
#include<bits/stdc++.h>
using namespace std;

 int sqrt(int A) {
    int low=0,high=A-1;
    int ans;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid*mid>A){
            high=mid-1;
        }else{
            ans=mid;
            low=mid+1;
        }
    }
    return ans;
}
int main(){
   cout<<sqrt(11);
}
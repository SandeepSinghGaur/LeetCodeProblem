/*
Problem Description

Given a sorted array of distinct integers A and an integer B, find and return how many rectangles with distinct configurations can be created using elements of this array as length and breadth whose area is lesser than B.

(Note that a rectangle of 2 x 3 is different from 3 x 2 if we take configuration into view)

Problem Constraints

1 <= |A| <= 100000
1 <= A[i] <= 10^9
1 <= B <= 10^9

Input
 A = [1, 2]
 B = 5
Output
 4
*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
       int ans=0;
       int n=A.size();
       int p1=0,p2=n-1;
       bool check=true;
       while(p1<p2){
           if(1l*A[p1]*A[p2]<B){
                 ans=ans+2*(p2-p1);
                p1++;
           }else{
               p2--;
           }
       }
       for(int i=0;i<n;i++){
           if(1l*A[i]*A[i]<B){
               ans++;
           }
       }
       return ans;
}
int main(){
    vector<int>A={1, 2, 3, 4, 5};
    int B=5;
    cout<<solve(A,B);
}
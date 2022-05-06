/*
Problem Description
Given two arrays of integers A and B of size N each, where each pair (A[i], B[i]) for 0 <= i < N represents a unique point (x, y) in a 2-D Cartesian plane.

Find and return the number of unordered quadruplet (i, j, k, l) 
such that (A[i], B[i]), (A[j], B[j]), (A[k], B[k]) and (A[l], B[l]) 
form a rectangle with the rectangle having all the sides parallel to either x-axis or y-axis.

Problem Constraints
1 <= N <= 2000
0 <= A[i], B[i] <= 10^9

Input
 A = [1, 1, 2, 2]
 B = [1, 2, 1, 2]
Output
1
*/

#include<bits/stdc++.h>
using namespace std;

int count_Ractangles(vector<int>&A,vector<int>&B){
    unordered_set<string>us;
    int n=A.size();
    for(int i=0;i<n;i++){
        us.insert(to_string(A[i])+"@"+to_string(B[i]));
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            //(x1,y1)=>A[i],B[i]
            //(x2,y2)=>A[j],B[j]
            if(B[i]==B[j] || A[i]==A[j]){
                continue;
            }
            //(x1,y2)=>A[i],B[j]
            //(x2,y1)=>A[j],B[i]
            string p1=to_string(A[j])+"@"+to_string(B[i]);
            string p2=to_string(A[i])+"@"+to_string(B[j]);
            if(us.find(p1)!=us.end() && us.find(p2)!=us.end()){
                ans++;
            }
        }
    }
    return ans/2;
}
int main(){
    vector<int>A={1, 1, 2, 2};
    vector<int>B={1, 2, 1, 2};
    cout<<count_Ractangles(A,B);
}
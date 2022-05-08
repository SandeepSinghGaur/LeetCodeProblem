/*
Problem Description
Given two arrays of integers A and B describing a pair of (A[i], B[i]) coordinates in a 2D plane. A[i] describe x coordinates of the ith point in the 2D plane, whereas B[i] describes the y-coordinate of the ith point in the 2D plane.

Find and return the maximum number of points that lie on the same line.

Problem Constraints
1 <= (length of the array A = length of array B) <= 1000

-10^5 <= A[i], B[i] <= 10^5

Input

 A = [-1, 0, 1, 2, 3, 3]
 B = [1, 0, 1, 2, 3, 4]

A : [ 3, 1, 4, 5, 7, -9, -8, 6 ]
B : [ 4, -8, -3, -2, -1, 5, 7, -4 ] 

Output
4 
2
*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, vector<int> &B) {
   unordered_map<int,int>usA;
     for(int i=0;i<A.size();i++){
           usA[A[i]]++;
     }
     int x=1,y=2,z=3,p=4;
     cout<<"max-number"<<max({x,y,z,p})<<endl;
     int count_x=0;
     for(auto it:usA){
       count_x=max(count_x,usA[it.second]);
     }
     unordered_map<int,int>usB;
     for(int i=0;i<A.size();i++){
           usB[B[i]]++;
     }
     int count_y=0;
     for(auto it:usB){
       count_y=max(count_y,usB[it.second]);
     }
     int max_val=max(count_x,count_y);
     int max_count=0;
    for(int i=0;i<A.size();i++){
        if(A[i]-B[i]==0){
            max_count++;
        }
    }
        
    return max(max_count,max_val);
}
int main(){
    vector<int>v1={3, 1, 4, 5, 7, -9, -8, 6};
    vector<int>v2={4, -8, -3, -2, -1, 5, 7, -4 };
    cout<<solve(v1,v2);
}
/*
Problem Description
Given two integer arrays, A and B of size N and M, respectively. Your task is to find all the common elements in both the array.

NOTE:

Each element in the result should appear as many times as it appears in both arrays.
The result can be in any order.

Problem Constraints
1 <= N, M <= 10^5

1 <= A[i] <= 10^9

Input
 A = [1, 2, 2, 1]
 B = [2, 3, 1, 2]
Output
[1,2,2]
*/
#include<bits/stdc++.h>
using namespace std;

vector<int>solve(vector<int> &A, vector<int> &B) {
    unordered_map<int,int>umA;
    unordered_map<int,int>umB;
    vector<int>result;
    for(int i=0;i<A.size();i++){
        umA[A[i]]++;
    }
    for(int i=0;i<B.size();i++){
        umB[B[i]]++;
    }
    for(auto it:umA){
        if(umB.find(it.first)!=umB.end()){
          int ele=min(umA[it.first],umB[it.first]);
         while(ele--){
             result.push_back(it.first);
         }
        }
    }
    return result;

}
int main(){
    vector<int>v1={1, 2, 2, 1};
    vector<int>v2={2, 3, 1, 2};
    vector<int>result;
    result=solve(v1,v2);
    for(auto it:result){
        cout<<it<<" ";
    }

}
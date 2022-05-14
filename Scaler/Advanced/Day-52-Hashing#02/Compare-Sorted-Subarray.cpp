/*
Problem Description
Given an array A of length N. You have to answer Q queries.

Each query will contain four integers l1, r1, l2, and r2. If sorted segment from [l1, r1] is the same as the sorted segment from [l2 r2], then the answer is 1 else 0.

NOTE The queries are 0-indexed.

Problem Constraints
0 <= A[i] <= 100000
1 <= N <= 100000
1 <= Q <= 100000

Input
A = [1, 7, 11, 8, 11, 7, 1]
B = [ 
       [0, 2, 4, 6]
    ]
Output
[1]
*/

#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
vector<int>solve(vector<int> &A, vector<vector<int> > &B) {
    vector<long long>pf(A.size());
    pf[0]=A[0];
     srand(0);
    for(int i=1;i<A.size();i++){
       long long randomnumber = (rand() * rand()) % mod;
       cout<<randomnumber<<endl;
        pf[i]=A[i]*randomnumber+pf[i-1];
    }
     vector<int>result;
    for(int i=0;i<B.size();i++){
        int l1=B[i][0];
        int r1=B[i][1];
        int l2=B[i][2];
        int r2=B[i][3];
        long long sumLeft;
        if(l1==0){
            sumLeft=pf[r1];
        }else{
            sumLeft=pf[r1]-pf[l1-1];
        }
        long long sumRight=pf[r2]-pf[l2-1];
        cout<<sumLeft<<" "<<sumRight<<endl;
       if(sumLeft==sumRight){
            result.push_back(1);
       }else{
           result.push_back(0);
       }
}
return result;
}
int main(){
    vector<int>A={100000, 100000, 100000, 100000, 100000 };
    vector<vector<int>>B={{0, 3, 1, 4},{0, 1, 2, 3},{4, 4, 1, 1},{1, 3, 0, 0},{2, 4, 1, 1}};
    vector<int>res;
    res=solve(A,B);
    for(auto it:res){
        cout<<it<<" ";
    }
}
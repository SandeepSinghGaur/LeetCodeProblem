/*
Problem Description
Given an integer array A of size N.

You have to find the product of the three largest integers in array A from range 1 to i, where i goes from 1 to N.

Return an array B where B[i] is the product of the largest 3 integers in range 1 to i in array A. If i < 3, then the integer at index i in B should be -1.

Problem Constraints
1 <= N <= 10^5
0 <= A[i] <= 10^3

Example Input
Input 1:

 A = [1, 2, 3, 4, 5]


Input 2:

 A = [10, 2, 13, 4]


 Example Output
Output 1:

 [-1, -1, 6, 24, 60]

Output 2:

 [-1, -1, 260, 520]
*/

#include<bits/stdc++.h>
using namespace std;


vector<int> solve(vector<int> &A) {

     priority_queue<int>pq;
    vector<int>ans;
    for(int i=0;i<A.size();i++){
        pq.push(A[i]);
        if(pq.size()<3){
            ans.push_back(-1);
        }
        if(pq.size()>=3){
            int sum=1;
            int k1,k2,k3;
            for(int i=0;i<3;i++){
                int x=pq.top();
                if(i==0) k1=x;
                if(i==1) k2=x;
                if(i==2) k3=x;
                sum*=x;
                pq.pop();
            }
            ans.push_back(sum);
           pq.push(k1);
           pq.push(k2);
           pq.push(k3);
        }
    }
    return ans;
}

int main(){
    vector<int>v={10, 2, 13, 4};
    vector<int>res;
    res=solve(v);
    for(auto it:res){
        cout<<it<<" ";
    }
}
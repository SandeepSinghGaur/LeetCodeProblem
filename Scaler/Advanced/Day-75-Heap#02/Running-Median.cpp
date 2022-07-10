/*
Problem Description
Given an array of integers, A denoting a stream of integers. New arrays of integer B and C are formed.
Each time an integer is encountered in a stream, append it at the end of B and append the median of array B at the C.

Find and return the array C.

NOTE:

If the number of elements is N in B and N is odd, then consider the median as B[N/2] ( B must be in sorted order).
If the number of elements is N in B and N is even, then consider the median as B[N/2-1]. ( B must be in sorted order).


Problem Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 10^9

Input 1:

 A = [1, 2, 5, 4, 3]

Input 2:

 A = [5, 17, 100, 11]

 Output 1:

 [1, 1, 2, 2, 3]

Output 2:

 [5, 5, 17, 11]
*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<A.size();i++){
        pq.push(A[i]);
    }
    int cost=0;
   while(pq.size()>1){
        int c1=pq.top();
        pq.pop();
        int c2=pq.top();
         pq.pop();
        cost+=(c1+c2);
        pq.push(c1+c2);
    }
    return cost;
}

int main(){
    vector<int>v={5, 17, 100, 11};
    cout<<solve(v);
  
}
/*
Problem Description
You are given an array A of integers that represent the lengths of ropes.

You need to connect these ropes into one rope. The cost of joining two ropes equals the sum of their lengths.

Find and return the minimum cost to connect these ropes into one rope.

Problem Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 1000

Input 1:

 A = [1, 2, 3, 4, 5]


Input 2:

 A = [5, 17, 100, 11]

 Output 1:

 33

Output 2:

 182
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

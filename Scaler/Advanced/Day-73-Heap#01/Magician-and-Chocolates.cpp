/*
Problem Description
Given N bags, each bag contains Bi chocolates. There is a kid and a magician.
In a unit of time, the kid can choose any bag i, and eat Bi chocolates from it, then the magician will fill the ith bag with floor(Bi/2) chocolates.

Find the maximum number of chocolates that the kid can eat in A units of time.

NOTE:

floor() function returns the largest integer less than or equal to a given number.
Return your answer modulo 10^9+7

Problem Constraints
1 <= N <= 100000
0 <= B[i] <= INT_MAX
0 <= A <= 10^5

Input 1:

 A = 3
 B = [6, 5]


Input 2:

 A = 5
 b = [2, 4, 6, 8, 10]

 Output 1:

 14


Output 2:

 33
*/


#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int nchoc(int A, vector<int> &B) {
      priority_queue<int>pq;
    int ans=0;
    for(int i=0;i<B.size();i++){
        pq.push(B[i]);
    }
    for(int i=0;i<A;i++){
        int k=pq.top();
        ans=(ans%mod+k%mod)%mod;
        int x=floor(pq.top()/2);
        pq.pop();
        pq.push(x);
    }
    return ans;
}

int main(){
    vector<int>v={6, 5};
    int A=3;
    cout<<nchoc(A,v);
  
}

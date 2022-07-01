/*
Problem Description
Given an array of integers A and an integer B. You must modify the array exactly B number of times. In a single modification, we can replace any one array element A[i] by -A[i].

You need to perform these modifications in such a way that after exactly B modifications, sum of the array must be maximum.


Problem Constraints
1 <= length of the array <= 5*10^5
1 <= B <= 5 * 10^6
-100 <= A[i] <= 100

Input 1:

 A = [24, -68, -29, -9, 84]
 B = 4


Input 2:

 A = [57, 3, -14, -87, 42, 38, 31, -7, -28, -61]
 B = 10

Output 1:

 196


Output 2:

 362
*/

#include<bits/stdc++.h>
using namespace std;


int Maximum_array_sum(vector<int>&A,int B){

    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<A.size();i++){
        pq.push(A[i]);
    }
    for(int i=0;i<B;i++){
        int x=pq.top();
        pq.pop();
        pq.push(-x);
    }
    int sum=0;
    while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
    }
    return sum;
}
int solve(vector<int> &A, int B) {
    return Maximum_array_sum(A,B);
}
int main(){
    vector<int>v={-50, 59, -80, -93, -51, -43, -35, -93, -2, 10, 18, 46, 68, -56, -7, -56, -54, -37, -57, -27, 0, 91, -40, 87, 88, 45, 11};
    int B=7325;
    cout<<solve(v,B);
}
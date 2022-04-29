/*
Problem Description
Given 2 integers A and B and an array of integers C of size N. Element C[i] represents the length of ith board.
You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each of them takes B units of time to paint 1 unit of the board.

Calculate and return the minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of the board.
NOTE:
1. 2 painters cannot share a board to paint. That is to say, a board cannot be painted partially by one painter, and partially by another.
2. A painter will only paint contiguous boards. This means a configuration where painter 1 paints boards 1 and 3 but not 2 is invalid.

Return the ans % 10000003.

Problem Constraints
1 <= A <= 1000
1 <= B <= 10^6
1 <= N <= 10^5
1 <= C[i] <= 10^6

Input
A = 2
B = 5
C = [1, 10]
Output
50
*/
#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>v,int k,int mid){
    int count=0,sum=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        if(sum>mid){
            sum=v[i];
            count++;
        }
        if(count==k){
            return false;
        }
    }
    return true;
}
int paint(int A, int B, vector<int> &C) {
    //first check can we apply binary search technique here
    //1- what we need to find(Target)
    //2- when we need to find(Search space)
    //3-are we able to divide our search space in one half or not
    int max_val=INT_MIN,total_sum=0;
    long long ans;
    for(int i=0;i<C.size();i++){
        max_val=max(max_val,C[i]);
        total_sum+=C[i];
    }
    int low=max_val,high=total_sum;
    while(low<=high){
        int mid=(low+high)/2;
        if(check(C,A,mid)){
          ans=(1l*B*mid)%10000003;
          high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans%10000003;
}
int main(){
    vector<int>v={1, 10};
    int A=2,B=5;
    cout<<paint(A,B,v);
}

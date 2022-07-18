/*
Problem Description
Given a array of integers A of size N and an integer B.

Return number of non-empty subsequences of A of size B having sum <= 1000.

Problem Constraints
1 <= N <= 20

1 <= A[i] <= 1000

1 <= B <= N


Input 1:

    A = [1, 2, 8]
    B = 2


Input 2:

    A = [5, 17, 1000, 11]
    B = 4

Output 1:

3

Output 2:

0
*/

#include<bits/stdc++.h>
using namespace std;


int sixlet(vector<int>&A,int n,int i,int B,int sum,vector<int>&temp){
    if(i==B){
        if(sum<=1000){
            return 1;
        }
        return 0;
    }
    int c=0;
    sum=sum+A[i];
    c=c+sixlet(A,n,i+1,B,sum,temp);
    sum=sum-A[i];
    c=c+sixlet(A,n,i+1,B,sum,temp);
    return c;
}
int solve(vector<int> &A, int B) {
    vector<int>temp;
    return sixlet(A,A.size(),0,B,0,temp);
    
}

int main(){
    vector<int>A={5, 17, 1000, 11};
    cout<<solve(A,4);
   
  
}

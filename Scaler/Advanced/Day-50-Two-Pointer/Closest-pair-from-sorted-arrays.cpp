/*
Problem Description

Given two sorted arrays of distinct integers, A and B, and an integer C, find and return the pair whose sum is closest to C and the pair has one element from each array.

More formally, find A[i] and B[j] such that abs((A[i] + B[j]) - C) has minimum value.

If there are multiple solutions find the one with minimum i and even if there are multiple values of j for the same i then return the one with minimum j.

Return an array with two elements {A[i], B[j]}.

Problem Constraints

1 <= length of both the arrays <= 100000

1 <= A[i], B[i] <= 10^9

1 <= C <= 10^9

Input
 A = [1, 2, 3, 4, 5]
 B = [2, 4, 6, 8]
 C = 9
Output
 [1,8]
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    int p1=0;
    int p2=B.size()-1;
    int ans=INT_MAX;
    vector<int>res;
    while(p1<A.size() && p2>=0){
        if(A[p1]+A[p2]>C){
            ans=min(ans, abs((A[p1] + B[p2])));
            res.push_back(A[p1]);
            res.push_back(B[p2]);
            p2--;
        }else if(A[p1]+A[p2]<C){
            ans=min(ans, abs((A[p1] + B[p2])));
            res.push_back(A[p1]);
            res.push_back(B[p2]);
            p1++;
        }else{
             res.push_back(A[p1]);
             res.push_back(B[p2]);
             return res;
        }
    }
    cout<<"ans"<<" "<<ans<<endl;
    return res;
}
int main(){
    vector<int>A={5, 10, 20};
    vector<int>B={1, 2, 30};
    int C=13;
    vector<int>result;
    result=solve(A,B, C);
    int i=1;
    for(auto it:result){
        cout<<it<<" ";
        if(i%2==0){
            cout<<endl;
        }
        i++;
    }
}
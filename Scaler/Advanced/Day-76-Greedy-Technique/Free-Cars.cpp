/*
Problem Description
Given two arrays, A and B of size N. A[i] represents the time by which you can buy the ith car without paying any money.

B[i] represents the profit you can earn by buying the ith car. It takes 1 minute to buy a car, so you can only buy the ith car when the current time <= A[i] - 1.

Your task is to find the maximum profit one can earn by buying cars considering that you can only buy one car at a time.

NOTE:

You can start buying from time = 0.
Return your answer modulo 109 + 7.

Problem Constraints
1 <= N <= 10^5
1 <= A[i] <= 10^9
0 <= B[i] <= 10^9

Input 1:

 A = [1, 3, 2, 3, 3]
 B = [5, 6, 1, 3, 9]


Input 2:

 A = [3, 8, 7, 5]
 B = [3, 1, 7, 19]

 Output 1:

 20
 
Output 2:

 30
*/

#include<bits/stdc++.h>
using namespace std;


bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.first==b.first){
        return a.second>b.second;
    }
   return a.first<b.first;
}
const int mod=1000000007; 
int solve(vector<int> &A, vector<int> &B) {
   int ans=0;
    vector<pair<int,int>>zipped;
    for(int i=0;i<A.size();i++){
        zipped.push_back({A[i],B[i]});
    }
    sort(zipped.begin(),zipped.end(),cmp);
    for(int i=0;i<zipped.size();i++){
        cout<<zipped[i].first<<"   "<<zipped[i].second<<endl;
    }
    int count=0;
    for(int i=0;i<zipped.size();i++){
       if(zipped[i].first-1>=count){
           ans=(ans%mod+(zipped[i].second)%mod)%mod;
           count++;
       }
    }
    return ans;
}

int main(){
    vector<int>A={1, 3, 1, 7, 2, 7, 1, 7, 6, 7, 8, 3, 3, 5, 4, 4, 5 };
    vector<int>B={2, 4, 6, 8, 4, 4, 4, 11, 8, 11, 8, 7, 7, 7, 6, 10, 4 };
    cout<<solve(A,B);
  
}
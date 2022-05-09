/*
Problem Description
Given an array A of N integers.

Find the largest continuous sequence in a array which sums to zero.


Problem Constraints
1 <= N <= 10^6

-10^7 <= A[i] <= 10^7

Input
A = [1,2,-2,4,-4]
Output
[2,-2,4,-4]
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> largest_Continuous_Sequences(vector<int>&A){
       map<long,int>mp;
       long sum=0;
       int start=-1,length=0;
       for(int i=0;i<A.size();i++){
           sum+=A[i];
           if(sum==0){
               start=0;
               length=i+1;
           }
           if(mp.count(sum) && length<i-mp[sum]){
               start=mp[sum]+1;
               length=i-mp[sum];
           }
           if(mp.count(sum)==false){
               mp[sum]=i;
           }
       }
       vector<int>ans;
       for(int i=start;i<start+length;i++){
             ans.push_back((A[i]));
       }
       return ans;

}
int main(){
    vector<int>v={10, 13, -1, 8, 29, 1, 24, 8, 21, 20, 21, -23, -21, 0 };
    vector<int>result;
    result=largest_Continuous_Sequences(v);
     cout<<"final result"<<" ";
    for(auto it:result){
        cout<<it<<" ";
    }
}
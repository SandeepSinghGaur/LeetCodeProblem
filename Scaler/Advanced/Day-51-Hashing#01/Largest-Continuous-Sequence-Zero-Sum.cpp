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
        vector<long long>pf(A.size());
      vector<int>result;
      int n=A.size();
     pf[0]=A[0];
    for(int i=1;i<A.size();i++){
        pf[i]=A[i]+pf[i-1];
    }
    int index=0;
    for(int i=n-1;i>=0;i--){
        if(pf[i]==0){
         index=i;
         break;
        }
         
    }
    int index2=INT_MIN;
    int start,end;
    bool check=true;
    unordered_map<long long,int>um;
   for(int i=0;i<A.size();i++){
       if(um.find(pf[i])!=um.end()){
           if(abs(i-um[pf[i]])>index2){
               check=false;
               index2=abs(i-um[pf[i]]);
               start=um[pf[i]];
               end=i;
           }
       }else{
           um.insert({pf[i],i});
       }
   }
   if(index==0 && check){
       return result;
   }
   if(index+1>=end-start){
       for(int i=0;i<=index;i++){
           result.push_back(A[i]);
       }
   }else{
       for(int i=start+1;i<=end;i++){
           result.push_back(A[i]);
       }
   }
  
    return result;
}
int main(){
    vector<int>v={1,2,-2,4,-4};
    vector<int>result;
    result=largest_Continuous_Sequences(v);
    for(auto it:result){
        cout<<it<<" ";
    }
}
/*
Problem Description
Given an array of integers A.

value of a array = max(array) - min(array).

Calculate and return the sum of values of all possible subarrays of A modulo 10^9+7.

Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 1000000


Input:
A = [4, 7, 3, 8]
Output:
26

*/
#include<bits/stdc++.h>
using namespace std;


vector<int> nextSmallestLeft(vector<int>&A){
    vector<int>res;
    stack<int>st;
    for(int i=0;i<A.size();i++){
        while(!st.empty() && A[st.top()]>=A[i]){
            st.pop();
        }
        if(!st.empty()){
            res.push_back(st.top());
        }else{
            res.push_back(-1);
        }
        st.push(i);
    }
    return res;
}
vector<int> nextSmallestRight(vector<int>&A){
    vector<int>res;
    stack<int>st;
    for(int i=A.size()-1;i>=0;i--){
        while(!st.empty() && A[st.top()]>=A[i]){
            st.pop();
        }
        if(!st.empty()){
            res.push_back(st.top());
        }else{
            res.push_back(A.size());
        }
        st.push(i);
    }
    reverse(res.begin(),res.end());
    return res;
}
vector<int> nextGreatestLeft(vector<int>&A){
   vector<int>res;
    stack<int>st;
    for(int i=0;i<A.size();i++){
        while(!st.empty() && A[st.top()]<=A[i]){
            st.pop();
        }
        if(!st.empty()){
            res.push_back(st.top());
        }else{
            res.push_back(-1);
        }
        st.push(i);
    }
    return res;
}
vector<int> nextGreatestRight(vector<int>&A){
   vector<int>res;
    stack<int>st;
    for(int i=A.size()-1;i>=0;i--){
        while(!st.empty() && A[st.top()]<=A[i]){
            st.pop();
        }
        if(!st.empty()){
            res.push_back(st.top());
        }else{
            res.push_back(A.size());
        }
        st.push(i);
    }
    reverse(res.begin(),res.end());
    return res;
}
const unsigned int MOD = 1000000007;
int solve(vector<int> &A) {
      vector<int>nsl(A.size());
      vector<int>nsr(A.size());
      vector<int>ngr(A.size());
      vector<int>ngl(A.size());
      nsl=nextSmallestLeft(A);
      cout<<"nsl Array:"<<endl;
      for(auto it:nsl){
          cout<<it<<" ";
      }
      cout<<endl;
      nsr=nextSmallestRight(A);
      cout<<"nsr Array:"<<endl;
      for(auto it:nsr){
          cout<<it<<" ";
      }
      cout<<endl;
      ngr=nextGreatestRight(A);
       cout<<"ngr Array:"<<endl;
      for(auto it:ngr){
          cout<<it<<" ";
      }
      cout<<endl;
      ngl=nextGreatestLeft(A);
         cout<<"ngl Array:"<<endl;
      for(auto it:ngl){
          cout<<it<<" ";
      }
      cout<<endl;
      long long max_val=0;
      long long min_val=0;
      for(int i=0;i<A.size();i++){
          long long left=(i-ngl[i]);
          long long right=(ngr[i]-i);
          long long index=(left%MOD * right%MOD)%MOD;
          long long local_max=(A[i]%MOD*index%MOD)%MOD;
          max_val=(max_val+local_max);
      }
      for(int i=0;i<A.size();i++){
          long long left=(i-nsl[i]);
          long long right=(nsr[i]-i);
          long long index=(left%MOD * right%MOD)%MOD;
          long long local_min=(A[i]%MOD*index%MOD)%MOD;
          min_val=(min_val+local_min);
      }
      return ((max_val%MOD-min_val%MOD+MOD)%MOD);

}


int main(){
    vector<int>v={4, 7, 3, 8};
    cout<<solve(v);
}
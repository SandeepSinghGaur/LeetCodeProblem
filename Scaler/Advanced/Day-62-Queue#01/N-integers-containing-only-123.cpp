/*
Problem Description
Given an integer, A. Find and Return first positive A integers in ascending order containing only digits 1, 2, and 3.

NOTE: All the A integers will fit in 32-bit integers.

Problem Constraints
1 <= A <= 29500

Input
 A = 3

Output
 [1,2,3]
*/
#include<bits/stdc++.h>
using namespace std;



vector<int> solve(vector<int> &A, int B) {
    queue<int>myQ;
    for(int i=0;i<B;i++){
        myQ.push(A[i]);
    }
   stack<int>st;
  while (!myQ.empty())
  {
      st.push(myQ.front());
      myQ.pop();
  }
  for(int i=0;i<B;i++){
      A[i]=st.top();
      st.pop();
  }
  
   return A;
}
int main(){
 vector<int>v={1, 2, 3, 4, 5};
 vector<int>result;
  result=solve(v,3);  
  for(auto it:result){
      cout<<it<<" ";
  }
}
/*
Problem Description
Given an array of integers A and an integer B, we need to reverse the order of the first B elements of the array, leaving the other elements in the same relative order.

NOTE: You are required to the first insert elements into an auxiliary queue then perform Reversal of first B elements.

Problem Constraints
1 <= B <= length of the array <= 500000
1 <= A[i] <= 100000

Input
 A = [1, 2, 3, 4, 5]
 B = 3

Output
 [3, 2, 1, 4, 5]
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
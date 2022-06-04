/*
Problem Description
Given an integer, A. Find and Return first positive A integers in ascending order containing only digits 1, 2, and 3.

NOTE: All the A integers will fit in 32-bit integers.

Problem Constraints
1 <= A <= 29500

Input:
A = 3
Output
[1, 2, 3]
*/


#include<bits/stdc++.h>
using namespace std;


vector<int> solve(int A) {
int count=0;
vector<int>ans;
queue<int>myQueue;
for(int i=1;i<=3;i++){
    myQueue.push(i);
    count++;
}

while(count<=A){
      int k=myQueue.front();
      myQueue.pop();
      int k1=(k*10)+1;
      int k2=(k*10)+2;
      int k3=(k*10)+3;
      ans.push_back(k);
      myQueue.push(k1);
      count++;
      myQueue.push(k2);
      count++;
      myQueue.push(k3);
      count++;
}
while(!myQueue.empty()){
    ans.push_back(myQueue.front());
    myQueue.pop();
}
vector<int>res(A);
for(int i=0;i<A;i++){
    res[i]=ans[i];
}
return res;
}
int main(){
   vector<int>result;
   result=solve(7);
   for(auto it:result){
       cout<<it<<" ";
   }
    
}
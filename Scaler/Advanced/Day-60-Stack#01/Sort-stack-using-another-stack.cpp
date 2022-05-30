/*
Problem Description
Given a stack of integers A, sort it using another stack.

Return the array of integers after sorting the stack using another stack.

Problem Constraints
1 <= |A| <= 5000

0 <= A[i] <= 10^9

Input:
 A = [5, 4, 3, 2, 1]

Output
 [1, 2, 3, 4, 5]
*/

#include<bits/stdc++.h>
using namespace std;


stack<int> merge_stack(stack<int>s1,stack<int>s2){
    stack<int>ans;
    while(s1.size()>0 && s2.size()>0){
        if(s1.top()>s2.top()){
            ans.push(s1.top());
             s1.pop();
        }else{
            ans.push(s2.top());
            s2.pop();
        }
    }
       while(s1.size()>0){
            ans.push(s1.top());
            s1.pop();
       }
       while(s2.size()>0){
            ans.push(s2.top());
            s2.pop();
       }
    return ans;
}
stack<int> sort_stack(stack<int>s){
    if(s.size()<=1){
        return s;
    }
    int ss=s.size()/2;
    stack<int>s1;
    for(int i=0;i<ss;i++){
          s1.push(s.top());
        //   cout<<s.top()<<endl;
          s.pop();

    }
    s=sort_stack(s);
    s1=sort_stack(s1);
    return merge_stack(s,s1);
}
vector<int> solve(vector<int> &A) {
    stack<int>s;
    stack<int>result;
    vector<int>ans;
    for(int i=0;i<A.size();i++){
        s.push(A[i]);
        //cout<<s.top()<<endl;
    }
    result=sort_stack(s);
     int ss=result.size();
     for(int i=0;i<ss;i++){
         ans.push_back(result.top());
         result.pop();
     }
     return ans;
}
int main(){
vector<int>v={5, 4, 3, 2, 1};
vector<int>res;
res=solve(v);
for(auto it:res){
    cout<<it<<" ";
}
}
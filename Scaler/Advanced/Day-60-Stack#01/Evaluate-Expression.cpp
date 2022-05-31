/*
Problem Description
An arithmetic expression is given by a character array A of size N. Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each character may be an integer or an operator.

Problem Constraints
1 <= N <= 10^5

Input 1:
    A =   ["2", "1", "+", "3", "*"]

Output
   9
*/

#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &A) {
    stack<string>st;
    int ans;
    for(int i=0;i<A.size();i++){
            if(A[i]=="/"){
            int x=stoi(st.top());
            st.pop();
            int y=stoi(st.top());
            st.pop();
            ans=y/x;
            string z=to_string(y/x);
            st.push(z);
       }else if(A[i]=="*"){
           int x=stoi(st.top());
           st.pop();
           int y=stoi(st.top());
           st.pop();
           ans=y*x;
           string z=to_string(y*x);
           st.push(z);
       }else if(A[i]=="+"){
             int x=stoi(st.top());
             st.pop();
             int y=stoi(st.top());
             st.pop();
             ans=y+x;
             string z=to_string(y+x);
             st.push(z);
       }else if(A[i]=="-"){
            int x=stoi(st.top());
             st.pop();
             int y=stoi(st.top());
             st.pop();
             ans=y-x;
             string z=to_string(y-x);
             st.push(z);
       }else{
           st.push(A[i]);
       }
    }
    if(!st.empty()){
        ans=stoi(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    vector<string>A={"2"};
    cout<<evalRPN(A);
}
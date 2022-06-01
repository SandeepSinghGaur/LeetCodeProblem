/*
Problem Description
Given two strings A and B. Each string represents an expression consisting of lowercase English alphabets, '+', '-', '(' and ')'.

The task is to compare them and check if they are similar. If they are identical, return 1 else, return 0.

NOTE: It may be assumed that there are at most 26 operands from ‘a’ to ‘z’, and every operand appears only once.


Problem Constraints
1 <= length of the each String <= 100

Input
A = "-(a+b+c)"
B = "-a-b-c"

Output
1
*/

#include<bits/stdc++.h>
using namespace std;

int solve(string A, string B) {
   stack<char>st;
    for(int i=0;i<A.length();i++){
        if(!st.empty() && A[i]=='(' && st.top()=='-'){
             while(i<A.length() && A[i]!=')'){
                 if(A[i]=='-'){
                     st.push('+');
                 }else if(A[i]=='+'){
                     st.push('-');
                 }else{
                     st.push(A[i]);
                 }
                 i++;
             }
        }else if(st.empty() && A[i]=='('){
            i++;
            while(i<A.length() && A[i]!=')'){
                     st.push(A[i]);
                      i++;
                 }
        }else if(!st.empty() && A[i]=='(' && st.top()!='-'){
               i++;
               st.push(A[i]);
        }
        else{
             st.push(A[i]);
        }
    }
     stack<char>st2;
      for(int i=0;i<B.length();i++){
        if(!st2.empty() && B[i]=='(' && st2.top()=='-'){
             while(i<B.length() && B[i]!=')'){
                 if(B[i]=='-'){
                     st2.push('+');
                 }else if(B[i]=='+'){
                     st2.push('-');
                 }else{
                     st2.push(B[i]);
                 }
                 i++;
             }
        }else if(st2.empty() && B[i]=='('){
            i++;
            while(i<B.length() && B[i]!=')'){
                     st2.push(B[i]);
                      i++;
                 }
        }else if(!st2.empty() && B[i]=='(' && st2.top()!='-'){
               i++;
               st2.push(B[i]);
        }
        else{
             st2.push(B[i]);
        }
    }

    int n1=st.size();
    int n2=st2.size();
    if(n1!=n2){
        return 0;
    }else{
          for(int i=0;i<n1;i++){
              if(st.top()!=st2.top()){
                  return 0;
              }
              st.pop();
              st2.pop();
          }
    }
    return 1;

}

int main(){
    string A="(a+b-c-d+e-f+g+h+i)";
    string B="a+b-c-d+e-f+g+h+i";
    cout<<solve(A,B);
}
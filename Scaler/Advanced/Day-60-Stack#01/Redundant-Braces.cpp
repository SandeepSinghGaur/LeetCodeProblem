/*
Problem Description
Given a string A denoting an expression. It contains the following operators '+', '-', '*', '/'.

Check whether A has redundant braces or not.

NOTE: A will be always a valid expression and will not contain any white spaces.


Problem Constraints
1 <= |A| <= 10^5

Input
 A = "((a+b))"
Output
1
Input
 A = "(a+(a+b))"
Output
0

*/
#include<bits/stdc++.h>
using namespace std;

int braces(string A) {
     stack<char>st;
    bool check=true;
    for(int i=0;i<A.length();i++){
        if(A[i]==')'){
            int count=0;
            while(st.top()!='('){
                count++;
                //if operator is not in stack present return 1;
                if(st.top()=='/'||st.top()=='*'||st.top()=='+'||st.top()=='-'){
                    check=false;
                }
                st.pop();
            }
             st.pop();
            if(count==0){
                return 1;
            }
            if(check){
                return 1;
            }
        }else{
              check=true;
              st.push(A[i]);
        }
    }
    return 0;
}
int main(){
      string A="(a*b)+(b*(d+(a)))";
      cout<<braces(A);
  
}
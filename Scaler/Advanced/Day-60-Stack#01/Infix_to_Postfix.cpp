/*
Problem Description
Given string A denoting an infix expression. Convert the infix expression into a postfix expression.

String A consists of ^, /, *, +, -, (, ) and lowercase English alphabets where lowercase English alphabets are operands and ^, /, *, +, - are operators.

Find and return the postfix expression of A.

NOTE:

^ has the highest precedence.
/ and * have equal precedence but greater than + and -.
+ and - have equal precedence and lowest precedence among given operators.

Problem Constraints
1 <= length of the string <= 500000

Input
A = "x^y/(a*z)+b"
Output
 "x y ^ a z * / b +"

 //aroh*+*

*/
#include<bits/stdc++.h>
using namespace std;



 unordered_map<char,int>um;
bool compair_character(char Ai, char st_top){
    if(um[Ai]<=um[st_top]){
        return true;
    }
     return false;  
}
string solve(string A) {
    um.insert({'^',5});
    um.insert({'/',4});
    um.insert({'*',4});
    um.insert({'+',2});
    um.insert({'-',2});
    um.insert({'(',0});
    string postfix="";
    stack<char>st;
    for(int i=0;i<A.length();i++){
        if(A[i]=='^'|| A[i]=='/' || A[i]=='*' || A[i]=='+' ||A[i]=='-'){

            if(st.empty()){

               st.push(A[i]);

            }else{
                while (!st.empty() && compair_character(A[i],st.top()))
                {
                    postfix.push_back(st.top());
                    st.pop();
                }

                 st.push(A[i]);
                
            }
           

        }else if(A[i]=='('){

            st.push(A[i]);

        }else if(A[i]==')'){

            //keep poping element from stack till we get )
            while(st.top()!='('){

                postfix.push_back(st.top());
                st.pop();

            }
            st.pop();

        }else{

            postfix.push_back(A[i]);

        }
    }
    while(!st.empty()){
         postfix.push_back(st.top());
        st.pop();
    }
    return postfix;
}
int main(){
    string A="q+(c*t)*o+(g*g)+q*(i-a)*p-(i*l)";
   string res=solve(A);
   cout<<res.length()<<endl;
  for(int i=0;i<res.length();i++){
     cout<<res[i];
    }
}
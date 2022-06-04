/*
Problem Description
Given an integer A, you have to find the Ath Perfect Number.

A Perfect Number has the following properties:

It comprises only 1 and 2.

The number of digits in a Perfect number is even.

It is a palindrome number.

For example, 11, 22, 112211 are Perfect numbers, where 123, 121, 782, 1 are not.

Problem Constraints
1 <= A <= 100000

Input:
A = 2
Output
22
*/


#include<bits/stdc++.h>
using namespace std;


string solve(int A) {
        int count=0;
    queue<string>myQ;
    vector<string>ans;
    myQ.push("11");
    count++;
    myQ.push("22");
    count++;
    while(count<=A){
        string str=myQ.front();
        ans.push_back(str);
        myQ.pop();
        int n=str.length();
        string s1=str;
        string s2=str;
        s1.insert(n/2,"11");
        myQ.push(s1);
        count++;
        s2.insert(n/2,"22");
        myQ.push(s2);
        count++;
    }
    while(!myQ.empty()){
        ans.push_back(myQ.front());
        myQ.pop();
    }
    string res;
    int i=1;
    for(auto it:ans){
       if(i==A){
           res=it;
           break;
       }
       i++;
    }
   return res;

}
int main(){

  cout<<solve(2);  
}
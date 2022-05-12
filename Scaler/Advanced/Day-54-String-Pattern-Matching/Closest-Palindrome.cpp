/*
Problem Description
Groot has a profound love for palindrome which is why he keeps fooling around with strings.
A palindrome string is one that reads the same backward as well as forward.

Given a string A of size N consisting of lowercase alphabets, he wants to know if it is possible to make the given string a palindrome by changing exactly one of its character.

Problem Constraints
1 <= N <= 10^5

Input
 A = "abbba"
Output
 "YES"
*/
#include<bits/stdc++.h>
using namespace std;


string solve(string A) {
    cout<<A.length()<<endl;
      int n=(A.length())/2;
   int p1=0;
   int p2=A.length()-1;
   while(p1<p2){
       if(A[p1]!=A[p2] && A[n-1]==A[n]){
           return "NO";
       }
       p1++;
       p2--;
   }
 
   if(A.length()%2==0){
       if(A[n-1]==A[n])
        return "NO";
   }
   return "YES";

}
int main(){
    string A="aaaaaaaaaabaaaaaaaaa";
    cout<<solve(A);
}
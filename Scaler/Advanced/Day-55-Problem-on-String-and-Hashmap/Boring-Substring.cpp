/*
Problem Description
You are given a string A of lowercase English alphabets. Rearrange the characters of the given string A such that there is no boring substring in A.

A boring substring has the following properties:

Its length is 2.
Both the characters are consecutive, for example - "ab", "cd", "dc", "zy" etc.(If the first character is C then the next character can be either (C+1) or (C-1)).
Return 1 if it is possible to rearrange the letters of A such that there are no boring substrings in A else, return 0.


Problem Constraints
1 <= |A| <= 10^5

Input
 A = "abcd"
 A = "aab"
Output
 1
 0
*/

#include<bits/stdc++.h>
using namespace std;

int solve(string &A){
      int no_of_substring=0;
    for(int i=0;i<A.length()-1;i++){
          if(abs(A[i]-'0'-A[i+1]-'0')==1){
              no_of_substring++;
          }
    }
    unordered_set<char>us;
    for(int i=0;i<A.length();i++){
        us.insert(A[i]);
    }
    if(no_of_substring>us.size())
    return 0;
    return 1;
}
int main(){
    string str="abcd";
    cout<<solve(str);
}
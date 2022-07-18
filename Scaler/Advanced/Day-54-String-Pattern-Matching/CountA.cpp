/*
Problem Description
You are given a string A. Find the number of substrings that start and end with 'a'.

Problem Constraints
1 <= |A| <= 105

The string will have only lowercase English letters.

Input
  A = "aab"
Output
 3
*/
#include<bits/stdc++.h>
using namespace std;


int solve(string A) {
      int totala=0;
    for(int i=0;i<A.length();i++){
        if(A[i]=='a'-0){
            cout<<A[i]<<" "<<"=="<<'a'-0<<endl;
            totala++;
        }
    }
    int n=totala-1;
    n=(n*(n+1))/2;
    return n+totala;


}
int main(){
    string A="abbba";
    cout<<solve(A);
}
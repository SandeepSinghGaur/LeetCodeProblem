/*
Problem Description
Given a string A of size N consisting only of lowercase alphabets. The only operation allowed is to insert characters in the beginning of the string.

Find and return how many minimum characters are needed to be inserted to make the string a palindrome string.


Problem Constraints
1 <= N <= 10^6

Input
A = "abc"
Output
2

*/

#include<bits/stdc++.h>
using namespace std;

int solve(string A) {
    int n=A.length();
    string mid="@";
    string dummy=A;
    reverse(dummy.begin(), dummy.end());
    string str=A+mid+dummy;
    vector<int>lps(2*n+1,0);
    for(int i=1;i<2*n+1;i++){
        int x=lps[i-1];
        while(str[i]!=str[x]){
            if(x==0){x=-1;break;}
            x=lps[x-1];
        }
        lps[i]=x+1;
    }
    cout<<endl;
    return n-lps[2*n];
  

}
int main(){
   cout<<solve("aaaaa");
}
/*
Problem Description
You are given a string A of length N consisting of lowercase alphabets. Find the period of the string.

Period of the string is the minimum value of k (k >= 1), that satisfies A[i] = A[i % k] for all valid i.

Problem Constraints
1 <= N <= 10^6

Input
 A = "abababab"
Output
 2
*/

#include<bits/stdc++.h>
using namespace std;


int count_Period(string A){
      vector<int>lps(A.length(),0);
    lps[0]=0;
    for(int i=1;i<A.length();i++){
        int x=lps[i-1];
        while(A[x]!=A[i]){
            if(x==0){
                x=-1;
                break;
            }
            x=lps[x-1];
        }
        lps[i]=x+1;
    }
   
    int count_zeros=0;
   for(int it:lps){
       if(it==0){
           count_zeros++;
       }else{
           break;
       }
   }
   int k=1;
   bool q=true;
   for(int i=count_zeros;i<lps.size();i++){
      if(lps[i]==k){
           q=false;
           k++;
      }else if(lps[i]==1 && !q){
           count_zeros=i;
            k=2;
      }else if(lps[i]==0 && !q){
              count_zeros=i+1;
               k=1;
      }
      else{
          return A.length();
      }
   }
   return count_zeros;

}
int main(){
    string A="zzzzzzzzzzzzzzbzzzzzzzzzzzzzzbzzzzzzzzzzzzzzbzzzzzzzzzzzzzzbzzzzzzzzzzzzzzbzzzzzzzzzzzzzzbzzzzzzzzzzzzzzbzzzzzzzzzzzzzzbzzzzzzzz";
    cout<<count_Period(A);
}
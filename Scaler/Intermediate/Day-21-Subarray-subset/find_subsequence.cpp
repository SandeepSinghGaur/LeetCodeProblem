#include <bits/stdc++.h>
using namespace std;

string find_subsequence(string A, string B) {
    int count=0;
    int k=0;
   for(int i=0;i<A.length();i++){
       for(int j=k;j<B.length();j++){
           if(A[i]==B[j]){
             count++;
             k=j+1;
             break;
           }
       }
   }
   if(count==A.length())
   return "YES";
   return "NO";
}


int main(){
   string A="apple";
   string B="appel";
   cout<<find_subsequence(A,B)<<" ";
   return 0;
}

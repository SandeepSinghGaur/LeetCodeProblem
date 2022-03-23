
/*
This technique is called swapping technique. it is very much used 

TC: O(n);
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &A) {
     int n=A.size();
    for(int i=0;i<=n;i++ ) {
          while(A[i]!=i+1 && A[i]>0 && A[i]<=n){
               if(A[i]==A[A[i]-1])
               break;
            swap(A[i],A[A[i]-1]);
        }
    }
        for(int j=0;j<n;j++){
            if(A[j]!=j+1){
                return j+1;
            }
        }
        return n+1;
}

int main(){

   vector<int>v={2,3,1,2};
   cout<<firstMissingPositive(v)<<" ";
  
}







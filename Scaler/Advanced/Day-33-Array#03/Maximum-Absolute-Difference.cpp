// This problem is very imporatant its purely based on mathematics and give good understanding about Mode. how we will get max of mod
/*
 TC: O(n)
 SC:O(n)

*/

#include <bits/stdc++.h>
using namespace std;

/* Brute force Approach: 

int maxArr(vector<int> &A) {
     int n=A.size();
    int max_val=INT_MIN;
    for(int i=0;i<n-1;i++){
      for(int j=i;j<n;j++){
        if(i==j){
            max_val=max(max_val,0);
        }else{
            int first=max(A[i]-A[j],-(A[i]-A[j]));
            int second=max((i+1)-(j+1),-((i+1)-(j+1)));
            max_val=max(first+second,max_val);
        }
    }
    }
   
    return max_val;
}
*/
// Optimize Approach 

int maxArr(vector<int> &A) {
     int n=A.size();
    int first[n]={0};
    int second[n]={0};
    for(int i=0;i<n;i++){
        first[i]=A[i]+i+1;
        second[i]=A[i]-i-1;
    }
    int max_val_in_first=INT_MIN;
    int min_val_in_first=INT_MAX;
     int max_val_in_second=INT_MIN;
    int min_val_in_second=INT_MAX;
    for(int i=0;i<n;i++){
         max_val_in_first=max(max_val_in_first,first[i]);
         min_val_in_first=min(min_val_in_first,first[i]);
          max_val_in_second=max(max_val_in_second,second[i]);
         min_val_in_second=min(min_val_in_second,second[i]);
    }
    int first_abs=max_val_in_first-min_val_in_first;
    int second_abs=max_val_in_second-min_val_in_second;
    return max(first_abs,second_abs);
}


int main(){

   vector<int>v={2, 2, 2 };
   cout<<maxArr(v)<<" ";
  
}







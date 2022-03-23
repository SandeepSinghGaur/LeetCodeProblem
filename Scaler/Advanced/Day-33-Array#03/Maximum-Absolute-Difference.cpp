


#include <bits/stdc++.h>
using namespace std;

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

int main(){

   vector<int>v={2, 2, 2 };
   cout<<maxArr(v)<<" ";
  
}







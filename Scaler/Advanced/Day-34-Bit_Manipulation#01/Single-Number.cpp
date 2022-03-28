

#include <bits/stdc++.h>
using namespace std;

int singleNumber(const vector<int> &A) {
    int res=A[0];
    for(int i=1;i<A.size();i++){
        res=res^A[i];
    }
    return res;
}

int main(){

   vector<int>v={1, 2, 2, 3, 1};
   cout<<singleNumber(v)<<" ";
  
}







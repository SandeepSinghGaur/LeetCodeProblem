

#include <bits/stdc++.h>
using namespace std;


bool checkbit(int n,int i){
     if(n>>i&1){
         return true;
     }else{
         return false;
     }
}
int singleNumber(const vector<int> &A) {
    int ans=0;
    for(int i=0;i<=30;i++){
        int count_set_bit=0;
          for(int j=0;j<A.size();j++){
              if(checkbit(A[j],i)){
                  count_set_bit++;
              }
          }
          if(count_set_bit%3==1){
              ans+=1<<i;
          }  
    }
    return ans;
}


int main(){

   vector<int>v={1, 2, 4, 3, 3, 2, 2, 3, 1, 1};
   cout<<singleNumber(v)<<" ";
  
}







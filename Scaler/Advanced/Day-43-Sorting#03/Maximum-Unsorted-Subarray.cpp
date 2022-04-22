#include <bits/stdc++.h>
using namespace std;


vector<int> subUnsort(vector<int> &A) {
    vector<int>ans;
    int n=A.size();
    bool check=true;
    int low,high;
     if(n==2 && A[0]==A[1]){
        ans.push_back(-1);
    return ans;
     }
   for(int i=1;i<A.size();i++){
       if(A[i-1]<A[i] && A[i]>A[i+1]){
           low=i;
           check=false;
           break;
       }
   }
    if(check){
    ans.push_back(-1);
    return ans;
    }
   for(int i=low+1;i<A.size();i++){
       if(A[i-1]>A[i] && A[i]<A[i+1]){
           high=i;
           break;
       }
   }
   ans.push_back(low);
   ans.push_back(high);
   return ans;

       
    
}

int main()
{
  vector<int>arr{1, 1, 10, 10, 15, 10, 15, 10, 10, 15, 10, 15};
  vector<int>result;
  result=subUnsort(arr);
  for(int i=0;i<result.size();i++){
      cout<<result[i]<<" ";
  }
}





#include <bits/stdc++.h>
using namespace std;


int kadane(int *res,int n){
    int sum=0,ans=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=res[i];
        ans=max(ans,sum);
        if(sum<0)
        sum=0;
    }
    return ans;
}

int solve(vector<vector<int> > &A) {
    int ans=INT_MIN;
    int n=A[0].size();
     for(int st=0;st<A.size();st++){
        int sum[n]={0};
       for(int i=st;i<A.size();i++){
        for(int j=0;j<n;j++){
            sum[j]+=A[i][j];
        }
        ans=max(ans,kadane(sum,n));
    }
    }
   
    return ans;
}


int main(){

   vector<vector<int>>v={{-6, -6},{-29, -8},{3, -8},{-15, 2},{25, 25},{20, -5}};
   cout<<solve(v)<<" ";
  
}







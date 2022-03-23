


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
    int ans=0;
    int col=A[0].size();
    int sum[col]={0};
    for(int i=0;i<A.size();i++){
        for(int j=0;j<col;j++){
            sum[i]+=A[i][j];
        }
        ans=max(ans,kadane(sum,col));
    }
    return ans;
}


int main(){

   vector<vector<int>>v={{-6, -6},{-29, -8},{3, -8},{-15, 2},{25, 25},{20, -5}};
   cout<<solve(v)<<" ";
  
}







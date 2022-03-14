
// its a Kadane's Algorthim
// TC:O(n)
// SC=O(1)


#include <bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int> &A) {
    int sum=0,ans=INT_MIN;
    for(int i=0;i<A.size();i++){
        sum+=A[i];
        ans=max(ans,sum);
         if(sum<0){
            sum=0;
        }
    }
    return ans;
}
int main(){

   vector<int>v={-2, 1, -3, 4, -1, 2, 1, -5, 4};
   cout<<maxSubArray(v)<<" ";
}







/*
RAIN_WATER_TAPPED PROBLEM
it's a famous interview problem.

TC:O(N);
SC:O(N);

*/


#include <bits/stdc++.h>
using namespace std;


int trap(vector<int> &A) {
   int n=A.size();
    int ans=0;
    vector<int>pfm(n);
    vector<int>sfm(n);
    pfm[0]=A[0];
    sfm[n-1]=A[n-1];

    for(int i=1,j=n-2;i<n ||j>=0;i++,j--){
      pfm[i]=max(A[i],pfm[i-1]);
      sfm[j]=max(sfm[j+1],A[j]);
    }
    
    for(int i=1;i<n-1;i++){
        int left=pfm[i-1];
        int right=sfm[i+1];
        int height=min(left,right);
        int water=max(height-A[i],0);
        ans+=water;
    }
    return ans;
}

int main(){
    vector<int>height_of_building={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    cout<<trap(height_of_building)<<" ";
}
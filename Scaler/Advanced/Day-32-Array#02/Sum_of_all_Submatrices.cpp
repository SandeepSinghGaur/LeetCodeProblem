/*****/
//  Sum of all Submatrices. developed intitution about contribution technique.
// TC:O(n*m)
// SC=O(1)


#include <bits/stdc++.h>
using namespace std;


int solve(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans+=A[i][j]*(i+1)*(j+1)*(n-i)*(m-j);
        }
    }
    return ans;
}
int main(){

   vector<vector<int>>v={{1, 1},{1, 1}};
   cout<<solve(v)<<" ";
  
}







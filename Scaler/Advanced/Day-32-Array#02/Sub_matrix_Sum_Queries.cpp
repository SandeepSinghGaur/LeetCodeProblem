/*****/
//   Sub-matrix Sum Queries. developed intitution about contribution technique.
// TC:O(n*m)
// SC=O(1)


#include <bits/stdc++.h>
using namespace std;

vector<int>solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
     int row=A.size();
    int col=A[0].size();
    vector<int>result;
    for(int i=0;i<row;i++){
        for(int j=1;j<col;j++){
            A[i][j]=(A[i][j]+A[i][j-1])%1000000007;
        }
    }
    for(int i=0;i<col;i++){
        for(int j=1;j<row;j++){
            A[j][i]=(A[j][i]+A[j-1][i])%1000000007;
        }
    }
    for(int i=0;i<B.size();i++){
        int x1=B[i]-1;
        int y1=C[i]-1;
        int x2=D[i]-1;
        int y2=E[i]-1;
        if(x1<=0 && y1<=0){
            result.push_back(A[x2][y2]%1000000007);
        }
        else if(x1<=0){
            result.push_back((A[x2][y2]-A[x2][y1-1])%1000000007);
        }else if(y1<=0){
            result.push_back((A[x2][y2]-A[x1-1][y2])%1000000007);
        }else{
             result.push_back((A[x2][y2]-A[x2][y1-1]-A[x1-1][y2]+A[x1-1][y1-1])%1000000007);
        }
       int sum=result[result.size()-1];
       if(sum<0){
           sum=sum+1000000007;
           result[result.size()-1]=sum;
       }
    }
    return result;
}

int main(){

   vector<vector<int>>A={{1,2,3},{4,5,6},{7,8,9}};
   vector<int>B={1,2};
   vector<int>C={1,2};
   vector<int>D={2,3};
   vector<int>E={2,3};
   vector<int>ans;
   ans=solve(A,B,C,D,E);
   for(auto x:ans){
       cout<<x<<" ";
   }
  
}







/*****/
//  Beggars Outside Temple it's a standard problem based on prefix_sum. developed intitution about prefix_sum concept
// TC:O(n)
// SC=O(n)


#include <bits/stdc++.h>
using namespace std;

vector<int>solve(int A, vector<vector<int> > &B) {
        vector<int>vect(A,0);
      for(int i=0;i<B.size();i++){
          vect[B[i][0]-1]+=B[i][2];
          if(B[i][1]!=A)
          vect[B[i][1]]-=B[i][2];
      }
      for(int i=1;i<A;i++){
          vect[i]+=vect[i-1];
      }
      return vect;
}
int main(){

   vector<vector<int>>v={{1, 2, 10},{2, 3, 20},{2, 5, 25}};
   vector<int>res;
   res=solve(5,v);
   for(int i=0;i<res.size();i++){
       cout<<res[i]<<" ";
   }
}







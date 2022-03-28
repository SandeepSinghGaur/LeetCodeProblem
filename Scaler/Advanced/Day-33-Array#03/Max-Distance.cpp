
/*
Good question concept which are used 1- comparator sorting 2-suffix-sum 3-need to use vector of pair

TC: O(n);
SC: O(n)
*/

#include <bits/stdc++.h>
using namespace std;


bool cmp(pair<int,int>x,pair<int,int>y){
    if(x.first<y.first){
        return true;
    }else if(x.first==y.first && x.second<y.second){
        return true;
    }else{
        return false;
    }
}
int maximumGap(const vector<int> &A) {
 vector<pair<int,int>>temp;
 int n=A.size();
 for(int i=0;i<n;i++){
     pair x=make_pair(A[i],i);
     temp.push_back(x);
  }
  sort(temp.begin(),temp.end(),cmp);
 
  vector<int>max_index(n);
  max_index[n-1]=temp[n-1].second;
  int max_val=temp[n-1].second;
   for(int i=n-2;i>=0;i--){
     max_val=max(max_val,temp[i].second);
     max_index[i]=max_val;
   }
   
  int res=INT_MIN;
  int k=0;
  for(auto x:temp){
   res=max(res,max_index[k]-x.second);
   k++;
  }
  return res;
}

int main(){

   vector<int>v={3, 5, 4, 2};
   cout<<maximumGap(v)<<" ";
  
}







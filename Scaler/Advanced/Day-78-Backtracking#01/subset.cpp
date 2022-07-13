/*
Problem Description
Given a set of distinct integers A, return all possible subsets.

NOTE:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.


Problem Constraints
1 <= |A| <= 16
INTMIN <= A[i] <= INTMAX

Input 1:

A = [1]

Input 2:

A = [1, 2, 3]

Output 1:

[
    []
    [1]
]


Output 2:

[
 []
 [1]
 [1, 2]
 [1, 2, 3]
 [1, 3]
 [2]
 [2, 3]
 [3]
]
*/

#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>ans;
void findsubset(vector<int>&A,int n,int i,vector<int>&t){
  if(i==n){
      ans.push_back(t);
      return;
  }
  t.push_back(A[i]);
  findsubset(A,n,i+1,t);
  t.pop_back();
  findsubset(A,n,i+1,t);
 
}
vector<vector<int> >subsets(vector<int> &A) {
    ans.clear();
    vector<int>t;
    sort(A.begin(),A.end());
    findsubset(A,A.size(),0,t);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int>A={1, 2, 3};
    vector<vector<int>>res;
    res=subsets(A);
    for(int i=0;i<res.size();i++){
       vector<int>temp;
       for(int j=0;j<res[i].size();j++){
        temp.push_back(res[i][j]);
       }
       cout<<"[";
       for(auto it:temp){
        cout<<it<<" ";
       }
       cout<<"]";
       cout<<endl;
    }
  
}
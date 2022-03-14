
#include <bits/stdc++.h>
using namespace std;

// v1={10,12} v2={10,13}
bool cmp(vector<int>&v1,vector<int>&v2){
   for(int i=0;i<v1.size() && i<v2.size();i++){
       if(v1[i]!=v2[i]){
           return (v1[i]<v2[i]);
       }
   }
   return v1.size()<v2.size();
    
}
vector<vector<int> > subsets(vector<int> &A) {
    sort(A.begin(),A.end());
     int n=1<<A.size();
    vector<vector<int>>temp;                                                
    for(int i=0;i<n;i++){
         temp.push_back(vector<int>());
        for(int j=0;j<A.size();j++){
            if(i & 1<<j){
                temp[i].push_back(A[j]);
            }
        }
    }
    sort(temp.begin(),temp.end(),cmp); // we are passing temp.begin() means first row and temp.end() last row 
    return temp;
}

int main()
{
	vector<int>v={12,13};
    vector<vector<int>>result;
	result=subsets(v);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
    }
	return 0;
}

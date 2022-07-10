/*
Problem Description
There are N jobs to be done, but you can do only one job at a time.

Given an array A denoting the start time of the jobs and an array B denoting the finish time of the jobs.

Your aim is to select jobs in such a way so that you can finish the maximum number of jobs.

Return the maximum number of jobs you can finish.


Problem Constraints
1 <= N <= 10^5

1 <= A[i] < B[i] <= 10^9

Input 1:

 A = [1, 5, 7, 1]
 B = [7, 8, 8, 8]

 Output
 2
*/
#include<bits/stdc++.h>
using namespace std;


bool cmp(pair<int,int>&a,pair<int,int>&b){
    return a.second<b.second;
}
int solve(vector<int> &A, vector<int> &B) {
    vector<pair<int,int>>zipped;
    for(int i=0;i<A.size();i++){
        zipped.push_back({A[i],B[i]});
    }
    sort(zipped.begin(),zipped.end(),cmp);
    for(int i=0;i<zipped.size();i++){
        cout<<zipped[i].first<<" "<<zipped[i].second<<endl;
    }
    int ind=0;
    int ans=0;
    for(int i=1;i<zipped.size();i++){
        if(zipped[ind].second<=zipped[i].first){
            ans++;
            ind=i;
        }
    }
    return ans+1;
}

int main(){
    vector<int>A={1, 5, 7, 1};
    vector<int>B={7, 8, 8, 8 };
    cout<<solve(A,B);
  
}
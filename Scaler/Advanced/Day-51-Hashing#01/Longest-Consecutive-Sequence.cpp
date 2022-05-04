/*
Problem Description
Given an unsorted integer array A of size N.

Find the length of the longest set of consecutive elements from array A.

Problem Constraints
1 <= N <= 10^6

-10^6 <= A[i] <= 10^6

Input:
A = [100, 4, 200, 1, 3, 2]
Output
4
*/

#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(const vector<int>&A){
    unordered_set<int>us;
    for(auto num:A){
        us.insert(num);
    }
    int ans=1;
    for(auto it:us){
       if(us.find(it-1)==us.end()){
           int ele=it,c=0;
           while(us.find(ele)!=us.end()){
               ele++,c++;
           }
           ans=max(ans,c);
       }

    }
    return ans;
}
int main(){
    vector<int>v={100, 4, 200, 1, 3, 2};
    cout<<longestConsecutive(v);
}
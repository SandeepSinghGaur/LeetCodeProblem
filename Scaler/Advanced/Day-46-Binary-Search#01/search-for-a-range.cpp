
/*
Given a sorted array of integers A(0 based index) of size N, find the starting and the ending position of a given integer B in array A.

Your algorithm's runtime complexity must be in the order of O(log n).

Return an array of size 2, such that the first element = starting position of B in A and the second element = ending position of B in A, if B is not found in A return [-1, -1].

*/
#include <bits/stdc++.h>
using namespace std;


vector<int> searchRange(const vector<int> &A, int B) {
 int low=0,high=A.size()-1;
 int l=0,h=A.size()-1;
 vector<int>arr=A;
 vector<int>ans;
 int left_side_index=-1;
 int right_side_index=-1;
 while(low<=high){
     int mid=low+(high-low)/2;
     if(arr[mid]==B){
         left_side_index=mid;
         high=mid-1;
     }else if(arr[mid]>B){
         high=mid-1;
     }else{
         low=mid+1;
     }
 }
 while(l<=h){
     int mid=l+(h-l)/2;
     if(arr[mid]==B){
         right_side_index=mid;
         l=mid+1;
     }else if(arr[mid]>B){
         h=mid-1;
     }else{
         l=mid+1;
     }
 }
 ans.push_back(left_side_index);
 ans.push_back(right_side_index);
 return ans;

   
    
}

int main()
{
  vector<int>arr{5,7,7,8,8,10};
  vector<int>ans;
  ans=searchRange(arr,8);
  for(auto it:ans){
      cout<<it<<" ";
  }
  
}


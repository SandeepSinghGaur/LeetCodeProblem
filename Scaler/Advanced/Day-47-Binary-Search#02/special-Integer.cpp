/*
Problem Description
Given an array of integers A and an integer B, find and return the maximum value K such that there is no subarray in A of size K with the sum of elements greater than B.

Problem Constraints
1 <= |A| <= 100000
1 <= A[i] <= 10^9

1 <= B <= 10^9

Input
A = [1, 2, 3, 4, 5]
B = 10
Output
2
*/
#include<bits/stdc++.h>
using namespace std;
long long get_sum_of_window_k(vector<int>&arr,int k){
    long long ans=INT_MIN,sum=0;
    for(int i=0;i<k;i++){
         sum+=arr[i];
    }
    int start=0,end=k;
    while(end<arr.size()){
        sum=sum+arr[end]-arr[start];
        ans=max(ans,sum);
        start++;
        end++;
    }
    return ans;
}
int max_value_of_K(vector<int>&arr,int B){
    int low=0,high=arr.size();
    long long sum,ans;
    while(low<=high){
        int mid=(low+high)/2;
        sum=get_sum_of_window_k(arr,mid);
        if(sum<=B){
           ans=mid;
           low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}
int main(){
    vector<int>arr={1, 2, 3, 4, 5};
    int B=10;
    cout<<max_value_of_K(arr,B);
}
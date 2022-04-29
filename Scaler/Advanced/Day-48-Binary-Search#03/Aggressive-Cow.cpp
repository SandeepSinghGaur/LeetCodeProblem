/*
Problem Description
Farmer John has built a new long barn with N stalls. Given an array of integers A of size N 
where each element of the array represents the location of the stall and an integer B which represents the number of cows.

His cows don't like this barn layout and become aggressive towards each other once put into a stall.
To prevent the cows from hurting each other, John wants to assign the cows to the stalls, 
such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Problem Constraints
2 <= N <= 100000
0 <= A[i] <= 10^9
2 <= B <= N

Input
A = [1, 2, 3, 4, 5]
B = 3
Output
2
*/
#include<bits/stdc++.h>
using namespace std;
bool isPlaceCow(vector<int>&stall,int mid,int cow){
    int count=1,last_placed=stall[0];
    for(int i=1;i<stall.size();i++){
        if(stall[i]-last_placed>=mid){
            count++;
            last_placed=stall[i];
        }
        if(cow==count)
        return true;
    }
    return false;
}
int solve(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int n=A.size();
    //Apply Binary Search
    //check the three condition of the binary Search
    //1-what we want to search(Target)
    //2-Where we want to search(Search Space)
    //3-Can we dive our search space in two half
    //calculate search space={low,high};
    int low=INT_MAX;
    for(int i=0;i<n-1;i++){
        low=min(low,A[i+1]-A[i]);
    }
    cout<<"low"<<" "<<low<<endl;
    int high=A[n-1]-A[0];
    cout<<"high"<<" "<<high<<endl;
    int ans;
    while(low<=high){
        int mid=(low+high)/2;
        if(isPlaceCow(A,mid,B)){
           ans=mid;
           low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}
int main(){
    vector<int>stall={1, 2, 3, 4, 5};
    int cow=3;
    cout<<solve(stall,cow);
}
/*
Problem Description
Given an integer array A, sort the array using Merge Sort.

Problem Constraints
1 <= |A| <= 10^5
1 <= A[i] <= 10^9

Input
A = [1, 4, 10, 2, 1, 5]
Output
1, 1, 2, 4, 5, 10
*/
#include<bits/stdc++.h>
using namespace std;
void merge_array(vector<int>&A,int low,int mid,int high){
        vector<int>temp(high-low+1);
        int p1=low,p2=mid+1, p3=0;
        while(p1<mid && p2<high){
            if(A[p1]<A[p2]){
                temp[p3]=A[p1];
                p3++;
                p1++;
            }else{
                temp[p3]=A[p2];
                p3++;
                p2++;
            }
        }
        while(p1<mid){
            temp[p3]=A[p1];
            p1++;
            p3++;
        }
         while(p2<high){
            temp[p3]=A[p2];
            p2++;
            p3++;
        }
        int k=0;
        for(int i=low;i<=high;i++){
            A[low]=temp[k];
            k++;
        }
    }
   void merge_sort(vector<int>&A,int low,int high){
        if(low>=high) return;
        int mid=(low+high)/2;
        merge_sort(A,low,mid);
        merge_sort(A,mid+1,high);
        merge_array(A,low,mid,high);
    }
vector<int>solve(vector<int> &A) {
     merge_sort(A,0,A.size()-1);
        return A;
}
int main(){
    vector<int>A={1, 4, 10, 2, 1, 5};
    vector<int>result;
     result=solve(A);
     for(auto it:result){
        cout<<it<<" ";
     }
}
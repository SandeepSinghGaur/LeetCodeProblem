/*
Problem Description

Given an integer array A, sort the array using QuickSort.

Problem Constraints

1 <= |A| <= 10^5

1 <= A[i] <= 10^9

Input
 A = [1, 4, 10, 2, 1, 5]
Output
 1,1,2,4,5,10
*/

#include<bits/stdc++.h>
using namespace std;

int re_arrange(vector<int>&A,int s,int e){
    int p1=s+1,p2=e;
    while(p1<=p2){
         if(A[s]>=A[p1]){
            p1++;
         }else if(A[s]<A[p2]){
            p2--;
         }else{
            swap(A[p1],A[p2]);
            p1++;
            p2--;
         }
    }
    swap(A[s],A[p2]);
    return p2;

}
   void quick_sort(vector<int>&A,int low,int high){
        if(low>=high) return;
        int p=re_arrange(A,low,high);
        quick_sort(A,low,p-1);
        quick_sort(A,p+1,high);
    }
vector<int>solve(vector<int> &A) {
     quick_sort(A,0,A.size()-1);
        return A;
}
int main(){
    vector<int>A={5,2,3,1};
    vector<int>result;
     result=solve(A);
     for(auto it:result){
        cout<<it<<" ";
     }
}
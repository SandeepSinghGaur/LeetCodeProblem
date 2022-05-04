/*
Problem Description:
Given the price list at which tickets for a flight were purchased, figure out the kth smallest price for the flight.
kth smallest price is the minimum possible n such that there are at least k price elements in the price list with value <= n. In other words, 
if the price list was sorted, then A[k-1] ( k is 1 based, while the array is 0 based ).

NOTE You are not allowed to modify the price list ( The price list is read only ). Try to do it using constant extra space.

Input:
A : [2 1 4 3 2]
k : 3

Output : 2

Constraints :
1 <= number of elements in the price list <= 1000000
1 <= k <= number of elements in the price list

*/

#include<bits/stdc++.h>
using namespace std;
int kthsmallest(const vector<int> &A, int B) {
       int low=A[0];
       int high=A[0];
    for(int i=1;i<A.size();i++){
        low=min(low,A[i]);
        high=max(high,A[i]);
    }
   int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        int no_of_element=0;
        for(int i=0;i<A.size();i++){
            if(A[i]<=mid){
                no_of_element++;
            }
        }
        if(no_of_element>B-1){
             ans=mid;
             high=mid-1;
           
        }else{
            low=mid+1;
        }
    }
    return ans;
    
}
int main(){
    vector<int>v={2,1,4,3,2};
    cout<<kthsmallest(v,3);  
}
/*
Problem Description
Given a sorted array of integers (not necessarily distinct) A and an integer B, find and return how many pair of integers ( A[i], A[j] ) such that i != j have sum equal to B.

Since the number of such pairs can be very large, return number of such pairs modulo (10^9 + 7).

Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 10^9

1 <= B <= 10^9

Input
A = [1, 1, 1]
B = 2
A : [ 1, 2, 6, 6, 7, 9, 9 ]
B : 13
Output
3
2
*/



#include<bits/stdc++.h>
using namespace std;

const int mod=(int)(1e9+7);
long long ncr(long long A,int B){
     long long temp=(A%mod*(A-1)%mod)%mod;
     return temp/B;
}
 

int pairs_with_given(vector<int>&A,int B){
     unordered_map<int,int>data_frequency;
    for(int i=0;i<A.size();i++){
        data_frequency[A[i]]++;
    }

    // newArray contain unique element
    vector<int>newArray;
    newArray.push_back(A[0]);
    for(int i=1;i<A.size();i++){
       if(A[i]!=newArray.back()){
           newArray.push_back(A[i]);
       }
    }
    
    long long ans=0;
    // if newArray contain only one element
     if(newArray.size()==1 && newArray[0]+newArray[0]==B){
       ans+=ncr((long long)data_frequency[newArray[0]],2);
       return ans%mod;
    }

    int p1=0,p2=newArray.size()-1;
    while(p1<p2){
        if(newArray[p1]+newArray[p2]==B){
            long long x,y;
             x=(long long)data_frequency[newArray[p1]];
             y=(long long)data_frequency[newArray[p2]];
             ans=ans+(x%mod*y%mod)%mod;
             p1++;
        }else if(newArray[p1]+newArray[p2]>B){
            p2--;
            if(p1==p2 && newArray[p1]+newArray[p2]==B){
                     if(data_frequency[newArray[p1]]>1){
                         ans=(ans%mod+ncr((long long)data_frequency[newArray[p1]],2)%mod)%mod;
                     }
                }
        }else{
            p1++;
             if(p1==p2 && newArray[p1]+newArray[p2]==B){
                     if(data_frequency[newArray[p1]]>1){
                         ans=(ans%mod+ncr((long long)data_frequency[newArray[p1]],2)%mod)%mod;
                     }
            }
        }
    }
    return ans%mod;
}
int main(){
    vector<int>v={1, 2, 6, 6, 7, 9, 9 };
    int B=13;
    cout<<pairs_with_given(v,B); 
}

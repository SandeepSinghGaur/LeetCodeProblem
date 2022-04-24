/*
Problem Name: Alternating Subarrays

Problem Description

You are given an integer array A of length N comprising of 0's & 1's, and an integer B.

You have to tell all the indices of array A that can act as a centre of 2 * B + 1 length 0-1 alternating subarray.

A 0-1 alternating array is an array containing only 0's & 1's, and having no adjacent 0's or 1's. For e.g. arrays [0, 1, 0, 1], [1, 0] and [1] are 0-1 alternating, while [1, 1] and [0, 1, 0, 0, 1] are not.


Problem Constraints

1 <= N <= 10^5
A[i] equals to 0 or 1.
0 <= B <= (N - 1) / 2

Input:
 A = [1, 0, 1, 0, 1]
 B = 1 

 Output:
 [1, 2, 3]
*/


#include<bits/stdc++.h>
using namespace std;
 vector<int> solve(const vector<int> &A, const int B) {
     vector<int>temp;
    bool check=true;
    int x=2*B+1;
    if(x>A.size())
    return temp;
    if(x==1){
        for(int i=0;i<A.size();i++){
            temp.push_back(A[i]);
        }
        return temp;
    }
    for(int i=0;i<A.size();i++){
        int count=0,index;
        for(int j=i+1;j<A.size();j++){
            index=j;
            if(A[j]==A[j-1]){
                break;
            }else{
                count++;
            }
            if(count==x-1)
            break;
        }
        if(count==x-1){
            temp.push_back(ceil(index+i)/2);
        }
    }
    return temp;
}

int main(){
    vector<int>vec={1, 0, 1, 0, 1};
    int B=1;
    vector<int>result;
    result=solve(vec,B);
    for(auto it:result){
        cout<<it<<" ";
    }
}
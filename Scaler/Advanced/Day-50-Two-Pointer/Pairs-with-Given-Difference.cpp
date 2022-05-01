/*
Problem Description
Given an one-dimensional integer array A of size N and an integer B.

Count all distinct pairs with difference equal to B.

Here a pair is defined as an integer pair (x, y), where x and y are both numbers in the array and their absolute difference is B.

Problem Constraints
1 <= N <= 10^4

0 <= A[i], B <= 10^5

Input
A = [1, 5, 3, 4, 2]
B = 3
A : [ 8, 12, 16, 4, 0, 20 ]
B : 4
Output
2
5
*/



#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int p1=0,p2=1,ans=0;
    while(p2<A.size()){
       if(abs(A[p2]-A[p1])==B){
          ans++;
          p2++;
       }else if(abs(A[p2]-A[p1])>B){
           p1--;
       }else{
           p1++;
       }
    }
    return ans;
}
int main(){
    vector<int>v={ 1, 1, 1, 2, 2};
    int B=0;
    cout<<solve(v,B); 
}

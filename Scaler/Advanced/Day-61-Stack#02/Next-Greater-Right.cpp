/*
Given an array A, find the next greater element G[i] for every element A[i] in the array.
The next greater element for an element A[i] is the first greater element on the right side of A[i] in the array, A.

More formally:

G[i] for an element A[i] = an element A[j] such that 
    j is minimum possible AND 
    j > i AND
    A[j] > A[i]
Elements for which no greater element exists, consider the next greater element as -1.

Problem Constraints
1 <= |A| <= 10^5

1 <= A[i] <= 10^7


Input
 A = [4, 5, 2, 10] 
Output
 [5, 10, 10, -1] 
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterLeft(vector<int> &A) {
 stack<int>st;
    vector<int>ans;
    for(int i=A.size()-1;i>=0;i--){
        while(!st.empty() && st.top()<=A[i]){
            st.pop();
        }
        if(!st.empty()){
            ans.push_back(st.top());
        }else{
            ans.push_back(-1);
        }
        st.push(A[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    vector<int>A={10,3,9,5,7,2,11};
    vector<int>result;
    result=nextGreaterLeft(A);
    for(auto it:result){
        cout<<it<<" ";
    }
}
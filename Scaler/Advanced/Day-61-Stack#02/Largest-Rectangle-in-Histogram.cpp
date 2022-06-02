/*
Problem Description
Given an array of integers A.

A represents a histogram i.e A[i] denotes the height of the ith histogram's bar. Width of each bar is 1.

Find the area of the largest rectangle formed by the histogram.


Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 1000000000


Input
 A = [2, 1, 5, 6, 2, 3]
Output
10
*/


#include<bits/stdc++.h>
using namespace std;


//BruteForce Approach
/*
int largestRectangleArea(vector<int> &A) {
    int global_max_area=INT_MIN;
    for(int i=0;i<A.size();i++){
        int local_max_area=INT_MIN;
        for(int j=i;j<A.size();j++){
            int width=(j-i+1);
            int height=min(A[i],A[j]);
            int area=height*width;
            local_max_area=max(local_max_area,area);
        }
        global_max_area=max(global_max_area,local_max_area);
    }
    return global_max_area;
}
*/
vector<int>prevSmallerLeft(vector<int>&A){
   vector<int>ans;
    stack<int>look_up_container;
    for(int i=0;i<A.size();i++){
        while(!look_up_container.empty() && A[look_up_container.top()]>=A[i]){
            look_up_container.pop();
        }
        if(!look_up_container.empty()){
            ans.push_back(look_up_container.top());
        }else{
            ans.push_back(-1);
        }
        look_up_container.push(i);
    }
    return ans;
}
vector<int>prevSmallerRight(vector<int>&A){
   vector<int>ans;
    stack<int>look_up_container;
    for(int i=A.size()-1;i>=0;i--){
        while(!look_up_container.empty() && A[look_up_container.top()]>=A[i]){
            look_up_container.pop();
        }
        if(!look_up_container.empty()){
            ans.push_back(look_up_container.top());
        }else{
            ans.push_back(A.size());
        }
        look_up_container.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int largestRectangleArea(vector<int> &A) {
     if(A.size()==1){
        return A[0];
    }
    vector<int>nsl(A.size());
    vector<int>nsr(A.size());
    nsl=prevSmallerLeft(A);
    nsr=prevSmallerRight(A);
    int ans=INT_MIN;
    for(int i=0;i<A.size();i++){
        int p1=nsl[i];
        int p2=nsr[i];
        int area=(p2-p1-1)*(A[i]);
        ans=max(ans,area);
        
    }
    return ans;
}
//
//2,1,5,6,2,3
//nsl: -1.-1,1,2,1,4
//nsr: 1,6,4,4,6,6
int main(){
    vector<int>A={90, 58, 69, 70, 82, 100, 13, 57, 47, 18};
    cout<<largestRectangleArea(A);
    
}
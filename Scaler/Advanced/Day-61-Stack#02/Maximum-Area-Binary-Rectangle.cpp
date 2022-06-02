/*
Given a 2D binary matrix of integers A containing 0's and 1's of size N x M.

Find the largest rectangle containing only 1's and return its area.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.

Constraints

1 <= N, M <= 1000
0 <= A[i] <= 1

Input:
    A = [   [0, 0, 1]
            [0, 1, 1]
            [1, 1, 1]   ]
Output:
    4

Input:
    A = [   [0, 1, 0, 1]
            [1, 0, 1, 0]    ]
Output:
    1
*/

#include<bits/stdc++.h>
using namespace std;


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
int solve(vector<vector<int> > &A) {
    int max_area=INT_MIN;
    cout<<"row"<<A.size()<<endl;
    cout<<"col"<<A[0].size()<<endl;
    vector<int>temp(A[0].size());
    cout<<"initial size"<<temp.size()<<endl;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            if(i==0){
             temp[j]=(A[i][j]);
            }else{
                if(A[i][j]==0){
                    temp[j]=0;
                }else{
                    temp[j]=(temp[j]+A[i][j]);
                }
            }  
        }
        cout<<i+1<<endl;
        cout<<"size"<<" "<<temp.size()<<endl;
         for(auto it:temp){
                cout<<it<<" ";
            }
            cout<<endl;
            int area=largestRectangleArea(temp);
            // cout<<"area"<<" "<<area<<endl;
            max_area=max(area,max_area); 

    }
    return max_area;
}

int main(){
    vector<vector<int>>v={{0, 1, 1},{1, 0, 0},{1, 0, 0},{1, 0, 0},{1, 0, 0},{1, 1, 1}};
    cout<<solve(v);
}


#include <bits/stdc++.h>
using namespace std;

vector<int>solve(const vector<int> &A, const vector<int> &B) {
    vector<int>ans(A.size()+B.size()); // taking an array which will contain the element of the A and B in sorted order
    int p1=0,p2=0,p3=0;  // taking three pointer for the tracking the index

    while(p1<A.size() && p2<B.size()){
        if(A[p1]<=B[p2]){
            ans[p3]=A[p1];
            p1++;
            p3++;
        }else{
            ans[p3]=B[p2];
            p2++;
            p3++;
        }
    }
    while(p1<A.size()){
        ans[p3]=A[p1];
        p1++;
        p3++;
    }
    while(p2<B.size()){
        ans[p3]=B[p2];
        p2++;
        p3++;
    }
    return ans;


}

int main(){
    vector<int>A={4, 7, 9 };
    vector<int>B={2, 11, 19};
    vector<int>ans;
    ans=solve(A,B);
    for(auto i:ans){
        cout<<i<<" ";
    }
  
}



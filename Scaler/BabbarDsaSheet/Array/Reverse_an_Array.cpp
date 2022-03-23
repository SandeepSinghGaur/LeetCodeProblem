#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>&A){
     int low=0;
     int high=A.size()-1;
     while(low<high){
         swap(A[low],A[high]);
         low++,high--;
     }
}

int main(){
    vector<int>v={2,1,5,6,2,5,8,3,5,7,9};
    reverseArray(v);
    for(auto ele:v)
    cout<<ele<<" ";
    return 0;
}
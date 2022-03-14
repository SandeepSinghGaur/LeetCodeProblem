#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&A){
    int max_even=INT_MIN;
    int min_odd=INT_MAX;
    for(int i=0;i<A.size();i++){
       A[i]%2==0?max_even=max(max_even,A[i]):min_odd=min(min_odd,A[i]);
    }
    return max_even-min_odd;

}

int main(){
    vector<int>v={5, 17, 100, 1};
    cout<<solve(v);
    return 0;
}
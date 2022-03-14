#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&v,int n){
    if(v.end()==find(v.begin(),v.end(),n))
    return-1;
    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]>n){
            v[i]=-1;
            count++;
        }
    }
    return count;

}

int main(){
    vector<int>v={1, 4, 2};
    cout<<solve(v,3);
    return 0;
}
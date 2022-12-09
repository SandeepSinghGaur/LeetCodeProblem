#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=4;
    int m=5;
    vector<vector<int>>v(n,vector<int>(5));
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            v[i][j]=-1;
        }
    }
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

}
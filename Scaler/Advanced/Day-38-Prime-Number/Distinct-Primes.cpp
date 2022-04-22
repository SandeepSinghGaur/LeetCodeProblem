
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    unordered_map<int,int>um;
   int n=A.size();

    //calculate max in array
    int max_number=INT_MIN;
    for(int i=0;i<n;i++){
        max_number=max(max_number,A[i]);
    }

    // create a smallest prime factor array
    vector<int>spf(max_number+1);
    for(int i=0;i<=max_number;i++){
        spf[i]=i;
    }

    // Apply Seive Algo to store smallest prime factor
    for(int i=2;i<=sqrt(max_number);i++){
        if(spf[i]==i){
            for(int j=i*i;j<=max_number;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        int k=A[i];
        while(k>1){
            if(um.find(spf[k])==um.end()){
                um[spf[k]]++;
            }
            k=k/spf[k];
        }
    }
    return um.size();
    
}

int main(){
    vector<int>v={10,20};
    cout<<solve(v);
  
}


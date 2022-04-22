
#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &A) {
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

    // count number of divisors
    vector<int>res;
    for(int i=0;i<n;i++){
        int num=A[i];
        unordered_map<int,int>um;
        while(num>1){
            um[spf[num]]++;
            num=num/spf[num];
        }

        int temp=1;
        for(auto it:um){
        temp*=it.second+1;
       }
       
       res.push_back(temp);
    }
    return res;
}

int main(){
    vector<int>v={10,20};
    vector<int>res;
    res=solve(v);
    for(auto it:res){
        cout<<it<<" ";
    }
  
}


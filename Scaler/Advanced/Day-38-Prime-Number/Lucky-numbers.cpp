
#include <bits/stdc++.h>
using namespace std;


int solve(int A) {

    // create a smallest prime factor array
    vector<int>spf(A+1);
    for(int i=0;i<=A;i++){
        spf[i]=i;
    }

    // Apply Seive Algo to store smallest prime factor
    for(int i=2;i<=sqrt(A);i++){
        if(spf[i]==i){
            for(int j=i*i;j<=A;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
    // A lucky number is a number that has exactly 2 distinct prime divisors.
    int result=0;
    for(int i=1;i<=A;i++){
        int num=i;
        unordered_map<int,int>um;
        while(num>1){
            um[spf[num]]++;
            num=num/spf[num];
        }
        if(um.size()==2){
          result++;
        }
       
    }
    return result;
}


int main(){
    cout<<solve(20);
}


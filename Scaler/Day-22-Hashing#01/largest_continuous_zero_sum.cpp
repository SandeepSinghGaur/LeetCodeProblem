
#include <bits/stdc++.h>
using namespace std;


vector<int> lszero(vector<int> &A) {
    vector<int>temp;
    unordered_map<int,int>mp;
    vector<int>pf(A.size());
    pf[0]=A[0];
    for(int i=1;i<A.size();i++){
        pf[i]=pf[i-1]+A[i];
    }
    int start,end;
    for(int i=0;i<A.size();i++){
        if(pf[i]==0){
             end=i;
             start=0;
        }
        if(mp.find(pf[i])!=mp.end()){
            end=i;
            start=mp[pf[i]]+1;
        }
        else{
            mp.insert({pf[i],i});
        }
    }
    for(int i=start;i<=end;i++){
        temp.push_back(A[i]);
    }
    return temp;
}

int main()
{
	vector<int>v={1, 2, -2, 4, -4};
	vector<int>res;
    res=lszero(v);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
	return 0;
}

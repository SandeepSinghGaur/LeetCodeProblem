
#include <bits/stdc++.h>
using namespace std;

int solve(int A,int B,vector<int> &C) {
   unordered_map<int,int>um;
    int sum=0;
    for(int i=0;i<A;i++){
           um[C[i]]++;
    }
    for(auto x :um){
         cout<<x.first<<" "<<x.second;
    }
    for(int i=0;i<A;i++){
        if(um.find(C[i])!=um.end()){
            if(um.at(C[i])==B){
                sum+=C[i];
                 um.erase(C[i]);
            }
        }
    }
    return sum;
}

int main()
{
	vector<int>v={2, 2, 2, 2 };
   
	cout<<solve(4,4,v)<<" ";
    
	return 0;
}

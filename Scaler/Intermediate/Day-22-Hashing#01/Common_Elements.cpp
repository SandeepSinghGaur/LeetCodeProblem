
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B) {
    unordered_map<int,int>um;
    vector<int>temp;
    for(int i=0;i<A.size();i++){
        um[A[i]]++;
    }
    for(int i=0;i<B.size();i++){
        if ( um.find (B[i]) != um.end() && um[B[i]]>0){
             temp.push_back(B[i]);
             um[B[i]]--; 
        }
    }
    return temp;
}

int main()
{
	vector<int>v1={1, 2, 2, 1};
	vector<int>v2={2, 3, 1, 2};
    vector<int>result;
	result=solve(v1,v2);
    sort(result.begin(),result.end());
    for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
        
    }
	return 0;
}


#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, int B) {
    vector<int>v;
    vector<int>pf(A.size());
    unordered_map<int,int>um;
    pf[0]=A[0];
    for(int i=1;i<A.size();i++){
        pf[i]=pf[i-1]+A[i];
    }
   
    for(int i=0;i<A.size();i++){
        if(pf[i]==B){
            for(int j=0;j<=i;j++){
                   v.push_back(A[j]);
               }
               return v;
        }
        else if(um.find(B-pf[i])!=um.end()){
               int start_index=um.at(pf[i]-B);
               for(int j=start_index+1;j<=i;j++){
                   v.push_back(A[j]);
               }
               return v;
        }else{
            um.insert({pf[i],i});
        }

    }
      v.push_back(-1);
      return v;
}



int main()
{
	vector<int>v={15, 2, 48, 19, 28, 22, 44, 2, 32, 46, 46, 24, 1, 23, 49, 26, 23, 17, 17, 46, 4, 30, 40, 36, 20, 5 };
    vector<int>result;
    result=solve(v,82);
	for(int num : result){
        cout<<num<<" ";
    }
    
	return 0;
}

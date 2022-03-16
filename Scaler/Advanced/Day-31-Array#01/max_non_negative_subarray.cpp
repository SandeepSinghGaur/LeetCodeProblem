

// TC:O(n)
// SC=O(n)


#include <bits/stdc++.h>
using namespace std;

vector<int>maxset(vector<long long> &A) {
    long long prev_sum=0;
    long long sum=0;
    int index=0;
    pair<int,int>p;
    vector<int>res;
    for(int i=0;i<A.size();i++){
        if(A[i]>=0){
            sum+=A[i];
        }else if(A[i]<0){
            if(prev_sum<=sum){
               p=make_pair(index,i);
               prev_sum=sum;
            }
            sum=0;
            index=i+1;
        }
    }
    if(sum>prev_sum){
        p=make_pair(index,A.size());
    }
    for(int i=p.first;i<=p.second;i++){
        if(i==p.second)
        break;
        res.push_back(A[i]);
    }
    return res;

}
int main(){

   vector<long long>v={ 1967513926, 1540383426, -1303455736, -521595368 };
   vector<int>result;
   result=maxset(v);
   for(auto ele:result)
   cout<<ele<<" ";
}







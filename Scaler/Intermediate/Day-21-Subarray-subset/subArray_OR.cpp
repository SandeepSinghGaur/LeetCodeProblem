
#include <bits/stdc++.h>
using namespace std;

long long  power_Calculate(int a,int n){
    long long  ans=1;
    long long p=100000000;
    for(int i=1;i<=n;i++){
        ans=((ans%p)*(a%p))%p;
    }
    return ans;
}

int solve(vector<int> &A) {
    long sum=0;
    long count_zero=0;
    int n=A.size();
    for(int i=0;i<31;i++){
         vector<int>v;
        for(int j=0;j<A.size();j++){
             if(A[j]&1==1){
                v.push_back(1);
             }else{
                 v.push_back(0);
             }
       }
       for(int i=0;i<A.size();i++){
           int count=0;
          while(v[i]==0){
              count++;
              i++;
          }
          count_zero+=1l*count*(count+1)/2;
       }
       long  contribution=(1l*n*(n+1)/2)-count_zero;
       sum+=contribution*power_Calculate(2,i)*1l;
    }
    
    return sum;
}


int main()
{
	vector<int>v={ 1, 2, 3, 4, 5};
   
	cout<<solve(v)<<" ";
    
	return 0;
}

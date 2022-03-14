
#include <bits/stdc++.h>
using namespace std;

long solve(int A, vector<int> &B) {
    long sum=0;
    for(int i=0;i<A;i++){
        long count=0;
        if(B[i]==0){
          count++;
           i++;
          while(i<A){
              if(B[i]==0){
                  count++;
                   i++;
              }else{
                  break;
              }
             
          }
        }
        sum+=(count*(count+1))/2;
    }
    long total=(A*1L*(A+1))/2;
    return total-sum;
   
}

int main()
{
	vector<int>v={1, 0, 1};
    long result=solve(3,v);
	cout<<result<<" ";
    
	return 0;
}

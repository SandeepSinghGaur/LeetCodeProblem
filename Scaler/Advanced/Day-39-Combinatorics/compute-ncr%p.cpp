

#include <bits/stdc++.h>
using namespace std;

int compute_factorial(int n,int p){
    if(n==1)
    return 1;
    return ((n%p)*compute_factorial(n-1,p))%p;
}

int fast_power_function(int a,int n,int m){
    if(n==0)
    return 1;
    long half_power=fast_power_function(a,n>>1,m);
    long ans=((half_power%m)*(half_power%m))%m;
    return n%2==0?ans:(a>0?((ans%m)*(a%m))%m:((ans%m+m)*(a%m+m))%m);
}

int compute_NCR(int n, int r, int p) {
   /*
       ncr%p== ((n!)/r!*(n-r)!)%p
       
       first part==n!%p
       second part== ((n-r)!)^-1%p 
       third part== ((r)!)^-1%p 
       we know farmet theorem:-
       if p is prime and gcd((n-r)!,p)==1 format can apply
       ((n-r)!)^-1%p ====>(((n-r)!)^p-2)%p==>((((n-r)!)%p)^p-2)

       n!%p==>(n(n-1)(n-2)(n-3)------1)%p

    */

    if(n==r && n==p) return 0;
    if(n==r && n!=p) return 1;
   int x=compute_factorial(n,p);
   int y=compute_factorial(n-r,p);
   int z=compute_factorial(r,p);
   int k1=fast_power_function(y,p-2,p);
   int k2=fast_power_function(z,p-2,p);
   int ans=((x%p)*(k1%p))%p;
   int res=((ans%p)*(k2%p))%p;
   return res;
    
}

int main(){
    cout<<compute_NCR(2069,759,93701);
  
}



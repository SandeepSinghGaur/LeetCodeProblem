

#include <bits/stdc++.h>
using namespace std;

int fast_power_function(int a,int n,int m){
    if(n==0)
    return 1;
    long half_power=fast_power_function(a,n>>1,m);
    long ans=((half_power%m)*(half_power%m))%m;
    return n%2==0?ans:(a>0?((ans%m)*(a%m))%m:((ans%m+m)*(a%m+m))%m);
}
int pow(int A, int B, int C) {
    if(A==0)
    return 0;
    return  fast_power_function(A,B,C);
}

int main()
{
	cout << pow(-1,2,20) << endl;
	return 0;
}

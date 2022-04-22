
/*
  Time Complaxity:O(log(max(a,b)))
  Space Complaxity:constant  
*/
#include <bits/stdc++.h>
using namespace std;

int gcd(int A, int B) {
    if(B==0) return A;
    return gcd(B,A%B);
}

int lcm(int B, int C ){
     return (B / gcd(B, C)) * C;
   }

int solve(int A, int B, int C) {
    int count=1;
    int res=lcm(B,C);
    cout<<res<<endl;
    while(res<=A){
        count++;
        res=res*2;
    }
    return count;
}


int main(){
   cout<<solve(81991,2549,7)<<" ";
  
}


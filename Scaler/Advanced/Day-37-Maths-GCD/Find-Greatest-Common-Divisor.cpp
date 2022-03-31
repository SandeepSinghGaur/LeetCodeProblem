/*
   GCD means Greatest Common Divior or Highest Common Factor
   How we know when we need to use GCD..?
   first observe the pattern of the problem.
   then if there any patter like repetitive subtraction type ex: a-1b,a-2b,a-3b,a-4b----------a-xb
   it means its a modulus concept we know if a%b==>range of this from(0 to b-1)
   some how try to figure out 
*/
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


int main(){
    int a,b;
    cin>>a;
    cin>>b;
   cout<<gcd(a,b)<<" ";
  
}


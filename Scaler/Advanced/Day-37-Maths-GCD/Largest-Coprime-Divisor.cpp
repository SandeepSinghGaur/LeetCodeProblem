
/*
  Time Complaxity:O(log(max(a,b)))
  Space Complaxity:constant  
*/
#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int cpFact(int A, int B) {
    int res=gcd(A,B);
    int check=A>B?B:A;
    if(res==1){
    return check;
   }
    cout<<"res"<<res<<endl;
  if(res==check){
      cout<<"if condition executed"<<endl;
    return 1;
  }else{
     for(int i=A-1;i>=1;i--){
       if(A%i==0 && B%i!=0){
         return i;
       }
     }
  }
}

int main(){
   cout<<cpFact(22,38)<<" ";
  
}


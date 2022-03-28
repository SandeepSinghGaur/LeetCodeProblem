

#include <bits/stdc++.h>
using namespace std;

int numSetBits(int A) {
    int res=0;
    while(A>0){
        if(A&1==1){
            res++;
        }
        A=A>>1;
    }
    return res;

}

int main(){
   cout<<numSetBits(11)<<" ";
  
}







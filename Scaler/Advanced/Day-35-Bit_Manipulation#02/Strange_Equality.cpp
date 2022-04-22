
#include <bits/stdc++.h>
using namespace std;

int solve(int A) {
    int x,y;
    for(int i=A-1;i>=0;i--){
        if((A^i)==(A+i)){
            x=i;
            break;
        }
    }
    cout<<x<<endl;
    int i=A+1;
    while(i>A){
        if((A^i)==(A+i)){
            y=i;
            break;
        }
        i++;
    }
     cout<<y<<endl;
    return x^y;
}

int main(){
    cout<<solve(2)<<" ";
}







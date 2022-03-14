#include<iostream>
#include<math.h>
using namespace std;

int main()  {
    int n;
    cin>>n;
    bool check=true;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0){
           check=false;
            break;
        }
    }
    if(!check)
    cout<<"No ! it's not a prime Number";
    else{
        cout<<"YES ! it's a prime Number";
    }
   
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
string convert_number_into_bits(int A){
    string res="";
    while(A>0){
        if(A&1==1){
            res.push_back('1');
        }else{
            res.push_back('0');
        }
        A=A>>1;
    }
    return res;
}
int main(){
    string str=convert_number_into_bits(4);
    cout<<str<<" ";
}
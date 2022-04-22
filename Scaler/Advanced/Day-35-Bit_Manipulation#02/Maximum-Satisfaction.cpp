


#include <bits/stdc++.h>
using namespace std;

//In order to calculate the Hamming distance between two strings, 
//and , we perform their XOR operation, (a⊕ b), and then count the total number of 1s in the resultant string.

bool checkBit(int n,int i){
    if(n>>i&1){
        return true;
    }else{
        return false;
    }
}
int hammingDistance(const vector<int> &A) {
    int ans=0;
   for(int i=0;i<=30;i++){
       int count=0;
       for(int j=0;j<A.size();j++){
           if(checkBit(A[j],i)){
               count++;
           }
       }
       ans=ans%1000000007+(count*(A.size()-count))%1000000007;
   }
   return (2*ans)%1000000007;
}
int main(){
    vector<int>v={2,4,6};
    cout<<hammingDistance(v)<<" ";
}







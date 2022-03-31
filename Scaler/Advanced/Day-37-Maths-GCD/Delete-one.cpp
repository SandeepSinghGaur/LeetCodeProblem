
/*
  Time Complaxity:O(n) 
  Space Complaxity:O(n)  
*/
#include <bits/stdc++.h>
using namespace std;

int gcd(int A, int B) {
    if(B==0) return A;
    return gcd(B,A%B);
}

int solve(vector<int> &A) {
    vector<int>pf_gcd(A.size());
    vector<int>sf_gcd(A.size());
    int n=A.size();
    // created prefix GCD
    pf_gcd[0]=A[0];
    for(int i=1;i<A.size();i++){
        pf_gcd[i]=gcd(pf_gcd[i-1],A[i]);
    }

    // created suffix GCD
    sf_gcd[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--){
        sf_gcd[i]=gcd(sf_gcd[i+1],A[i]);
    }

    //Delete one everytime and find GCD
    int ans=INT_MIN;
     int left_side_gcd=0;
     int right_side_gcd=0;
    for(int i=0;i<n;i++){
        if(i==0){
            right_side_gcd=sf_gcd[i+1];
            left_side_gcd=0;
        }else if(i==n-1){
            left_side_gcd=pf_gcd[i-1];
            right_side_gcd=0;
        }else{
            left_side_gcd=pf_gcd[i-1];
            right_side_gcd=sf_gcd[i+1];
        }
        
        ans=max(ans,gcd(left_side_gcd,right_side_gcd));
    }
    return ans;
}


int main(){
    vector<int>v={3, 9, 6, 8, 3 };
   cout<<solve(v)<<" ";
  
}


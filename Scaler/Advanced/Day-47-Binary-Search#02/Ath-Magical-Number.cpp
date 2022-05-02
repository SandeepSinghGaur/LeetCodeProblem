/*
Problem Description
You are given three positive integers, A, B, and C.

Any positive integer is magical if divisible by either B or C.

Return the Ath smallest magical number. Since the answer may be very large, return modulo 10^9 + 7.

Problem Constraints
1 <= A <= 10^9

2 <= B, C <= 40000

Input
A = 1
B = 2
C = 3
Output
2

*/
#include<bits/stdc++.h>
using namespace std;
//Brute force approach
// int ath_Magical_Number(int a,int b,int c){
//     int count=0;
//     int num=1;
//     while(count!=a){
//         if(num%b==0 || num%c==0){
//             count++;
//         }
//         num++;
//     }
//     return num-1;
// }

const int mod=(int)(1e9+7);
int gcd(int b,int c){
    if(c==0) return b;
    return gcd(c,b%c);
}
int ath_Magical_Number(int A,int B,int C){
    long long ans;
    long long low=1;
    long long minima=min(B,C);
    long long high=(minima*A);
    while(low<=high){
        long long mid=(low+high)/2;
        long long lcm_of_BC=(B*C)/gcd(B,C);
        long long factor=(mid/B)+(mid/C)-(mid/lcm_of_BC);
        if(factor==A){
            ans=mid;
            high=mid-1;
        }else if(factor<A){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans%mod;
}
int main(){
    int A=807414236,B=3788,C=38141;
    cout<<ath_Magical_Number(A,B,C);
}
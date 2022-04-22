#include <bits/stdc++.h>
using namespace std;


int merge_inversion(vector<int>&A,int s,int m,int e){
    int temp[e-s+1],c=0;
    int p1=s,p2=m+1,p3=0;
    while(p1<=m && p2<=e){
        if(A[p1]<=A[p2]){
            temp[p3]=A[p1];
            p1++;
            p3++;
        }else{
            temp[p3]=A[p2];
            p2++;
            p3++;
            c+=(m-p1+1);
        }
    }
    while(p1<=m){
        temp[p3]=A[p1];
        p1++;
        p3++;
    }
    while(p2<=e){
        temp[p3]=A[p2];
        p2++;
        p3++;
    }
    for(int i=0;i<=e-s;i++){
        A[i+s]=temp[i];
    }
    return c;
}
int inversion(vector<int>&A,int s,int e){
    if(s==e) return 0;
    int m=(s+e)/2;
    int l=inversion(A,s,m);
    int r=inversion(A,m+1,e);
    int c=merge_inversion(A,s,m,e);
    return (l+r+c);
}
int solve(vector<int> &A) {
    int n=A.size()-1;
    return inversion(A,0,n);
}

int main()
{
  vector<int>arr{3, 2, 1};
  
  cout<<solve(arr);
}


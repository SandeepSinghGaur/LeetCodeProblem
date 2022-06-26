#include<bits/stdc++.h>
using namespace std;

int sum_list(vector<int>&v1,vector<int>&v2){
    int n1=v1.size();
    int n2=v2.size();
    cout<<"n1"<<n1<<endl;
        cout<<"n2"<<n2<<endl;
    if(n2>=n1){
        cout<<"n1"<<n1<<endl;
        cout<<"n2"<<n2<<endl;
      vector<int>arr;
      arr=v1;
      v1=v2;
      v2=arr;
    }
    int sum=0;
    int k=0;
    if(n1>n2){
        int r=0;
        for(int i=n2-1;i>=0;i--){
             sum=((v2[i]+v1[n1-1-k])+r)%10;
             if(k!=0){
                   sum+=sum*(pow(10,k));
             }
            
             cout<<"next sum"<<" "<<sum<<endl;
             if(v2[i]+v1[n1-1-k]+r>10){
                 r=(v2[i]+v1[n1-1-k]+r)/10;
             }
             
             k++;
        }
        cout<<"sum"<<" "<<sum<<endl;
        for(int i=n1-1-k;i>=0;i--){
            sum=((v1[i])+r)%10;
            sum+=(sum*pow(10,k));
            r=(v1[i]+r)/10;
            k++;
        }
        if(r!=0){
        sum+=(pow(10,k));
        }
    }
    return sum;
}
int main(){
    vector<int>v1={1,1,0,2};
    vector<int>v2={1,0};
    cout<<sum_list(v1,v2);
}
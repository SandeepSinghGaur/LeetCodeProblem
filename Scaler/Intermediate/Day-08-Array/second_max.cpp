#include<bits/stdc++.h>
using namespace std;

int main()  {
   int T;
   cin>>T;
   while(T--){
       int n;
       cin>>n;
       int arr[n];
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
        if(n<=1){
        cout<<-1<<endl;
        }
        else{
            int first_max=INT_MIN,second_max=INT_MIN;
            for(int i=0;i<n;i++){
           if(arr[i]>first_max){
               second_max=first_max;
                first_max=arr[i];
           }else if(arr[i]<=first_max && arr[i]>second_max){
               second_max=arr[i];
           }
       }
       cout<<"second max : "<<second_max<<endl;
        }
      
   }
}

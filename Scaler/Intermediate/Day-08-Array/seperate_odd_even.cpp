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
       
       for(int i=0;i<n;i++){
           if(arr[i]%2!=0){
               cout<<arr[i]<<" ";
           } 
       }
        cout<<endl;
       for(int i=0;i<n;i++){
           if(arr[i]%2==0){
               cout<<arr[i]<<" ";
           } 
       }
    }
    return 0;
}
// 509800927 348992125 733735508 654457679 499101452 855551825 443382987
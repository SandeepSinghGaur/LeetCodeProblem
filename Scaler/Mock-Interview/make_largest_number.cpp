/*
Find the highest number that can be made from the given number 513 -> 531 
  1020 ->  2100
*/
#include<bits/stdc++.h>
using namespace std;

int make_largest_number(int n){
    vector<int>ans(10,0);
    string str="";
    while(n>0){
        int r=n%10;
        ans[r]=ans[r]+1;
        n=n/10;
    }
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    for(int i=ans.size()-1;i>=0;i--){
        while(ans[i]!=0){
            //cout<<i<<" "<<endl;
            str+=to_string(i);
            ans[i]=ans[i]-1;
        }
    }
    //cout<<"our string"<<str<<" ";
    return stoi(str);

}

int main(){
    cout<<make_largest_number(5133);
}
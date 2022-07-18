//brute force calculate all substring

#include<bits/stdc++.h>
using namespace std;
void calculate_substring(string A){
    int p=0;
    for(int i=0;i<A.length();i++){
        for(int j=i;j<A.length();j++){
            for(int k=0;k<=j;k++){
               cout<<A[k];
               if(k==j){
                cout<<endl;
                p++;
               }
            }
        }
        cout<<i<<" "<<"substring"<<endl;
    }
    cout<<"total substring"<<p;
}
int main(){
    string str="abacab";
    calculate_substring(str);
}
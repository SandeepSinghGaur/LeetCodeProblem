


#include <bits/stdc++.h>
using namespace std;

vector<int>flip(string A) {
    vector<int>temp;
    vector<int>v;
    for(int i=0;i<A.length();i++){
        if(A[i]=='0'){
            temp.push_back(1);
        }else{
            temp.push_back(-1);
        }
    }
    int count=0;
    for(int i=0;i<temp.size();i++){
        if(temp[i]==-1){
            count++;
        }
    }
    if(count==temp.size())
    return v;
 int ans=INT_MIN,sum=0;
    int start=0,end;
    int new_start=0;
    for(int i=0;i<A.size();i++){
        sum+=temp[i];
         if(ans<sum){
              if(start!=0){
                  new_start=start;
              }
             end=i;
             ans=sum;
         }
        if(sum<0){
         sum=0;
        
         start=i+1;
        }
        
    }

    v.push_back(new_start+1);
    v.push_back(end+1);
    return v;

}


int main(){

   string str="011";
   vector<int>result;
   result=flip(str);
   for(auto ele:result)
   cout<<ele<<" ";
}







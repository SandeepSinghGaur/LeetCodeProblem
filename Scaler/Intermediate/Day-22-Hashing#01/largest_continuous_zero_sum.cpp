
#include <bits/stdc++.h>
using namespace std;


vector<int>lszero(vector<int> &A) {
   vector<int>pf(A.size());
   pf[0]=A[0];
   cout<<pf[0]<<" ";
   for(int i=1;i<A.size();i++){
      pf[i]=pf[i-1]+A[i];
       cout<<pf[i]<<" ";
   }
   cout<<endl;
   int last_index=0;
   for(int i=0;i<A.size();i++){
       if(pf[i]==0){
        last_index=i;
       }
   }

   int first=0,last=0;
   unordered_map<int,int>um;
   for(int i=0;i<pf.size();i++){
       if(um.find(pf[i])!=um.end()){
           cout<<"compair"<<um.at(pf[i])+1<<" "<<i<<endl;
           if(i-um.at(pf[i])>last-first){
              first=um.at(pf[i])+1;
               last=i;
           }   
       }else{
           um.insert({pf[i],i});
       }
   }
   
   vector<int>temp;
   if(last_index>last-first){
     for(int i=0;i<=last_index;i++){
         temp.push_back(A[i]);
     }
   }else{
       if(first==0 && last==0){
           return temp;
       }else{
               for(int i=first;i<=last;i++){
           temp.push_back(A[i]);
         }
       }
         
   }
   return temp;
}


int main()
{
	vector<int>v={-8, 8, -1, -16, -28, -27, 15, -14, 14, -27, -5, -6, -25, -11, 28, 29, -3, -25, 17, -25, 4, -20, 2, 1, -17, -10, -25 };
	vector<int>res;
    res=lszero(v);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
	return 0;
}

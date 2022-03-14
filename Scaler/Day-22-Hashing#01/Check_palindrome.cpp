
#include <bits/stdc++.h>
using namespace std;

int solve(string A) {
   int n=A.length(),count=0;
   cout<<n<<" ";
   bool check=true;
   unordered_map<char,int>um;
   for(int i=0;i<n;i++){
       um[A[i]]++;
   }
   if(n%2==0){
       for(int i=0;i<n;i++){
           if(um.find(A[i])!=um.end() && um.at(A[i])%2==0){
               check=true;
           }else{
               check=false;
           }
       }
       if(check){
       return 1;
   }else{
       return 0;
   }
   }else{
        for(int i=0;i<n;i++){
           if(um.find(A[i])!=um.end() && um.at(A[i])%2!=0){
               count++;
               if(count>10)
                return 0;
           }
       }
   }
   return 1;
 
  
}


int main()
{
	string a = "dcnzutptzzilbtihpgtyegycjysfxlasllvjqatoznaxftxrxjlyoxqnkcalaunxuyokvnkcnouhhxrabcxdaezxakxhjoyco";
	cout << solve(a) << endl;
	return 0;
}

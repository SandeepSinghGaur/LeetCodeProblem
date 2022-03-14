
#include <bits/stdc++.h>
using namespace std;

int solve(string A, int B) {
 int count[26]={0};
 for(int i=0;i<A.length();i++){
      count[A[i]-'a']++;
 }
   sort(count, count + 26);
   for(int i=0;i<26;i++){
       if(B>=count[i] && count[i]!=0){
            B=B-count[i];
           count[i]=0;
          
       }
       if(B==0)
       break;
   }
    
   int result=0;
   for(int i=0;i<26;i++){
       if(count[i]>0){
           result++;
       }
   }
 return result;
}


int main()
{
	string a = "umeaylnlfd";
	cout << solve(a,1) << endl;
	return 0;
}

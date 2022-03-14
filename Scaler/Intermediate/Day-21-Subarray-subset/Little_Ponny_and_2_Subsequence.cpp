
#include <bits/stdc++.h>
using namespace std;
string solve(string A) {
    char ch=A[0];
    char ch2=A[1];
    string str="";
   for(int i=1;i<A.length()-1;i++){
     if(ch>ch2){
         ch2=A[i+1];
         ch=A[i];
         i++;
     }else if(A[i]<ch2 && A[i]>=ch){
         ch2=A[i];
     }else if(A[i]<ch2 && A[i]<ch){
         ch=A[i];
         ch2=A[i+1];
     }
   }
   if(A[A.length()-1]<ch2){
       ch2=A[A.length()-1];
   }
   str.push_back(ch);
   str.push_back(ch2);
   return str;
}



int main()
{
	string a = "ksdjgha";
	cout << solve(a) << endl;
	return 0;
}

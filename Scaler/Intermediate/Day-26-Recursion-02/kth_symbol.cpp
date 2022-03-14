

#include <bits/stdc++.h>
using namespace std;


void kth_symbol(string &res,int A){
   if(A==1)
   return;
   for(int i=0;i<res.length();i++){
      if(res[i]=='0'){
         res.replace(i,1, "01");
         i++;
      }else{
          res.replace(i, 1, "10");
          i++;
      }
   }
   kth_symbol(res,A-1);
}
int solve(int A, int B) {
    string res="0";
    kth_symbol(res,A);
    return res[B-1]-'0';
}


int main()
{
	cout << solve(2,1) << endl;
	return 0;
}

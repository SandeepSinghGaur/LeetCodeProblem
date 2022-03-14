
#include <bits/stdc++.h>
using namespace std;

void printNumber(int n) {
   if(n==1){
     cout<<n<<" ";
   return;
   }
   printNumber(n-1);
   cout<<n<<" ";
}


int main()
{
	auto num=10;
	printNumber(num);
	return 0;
}

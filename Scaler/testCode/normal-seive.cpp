#include <bits/stdc++.h>
using namespace std;

void simpleSieve(int x)
{
  vector<bool> isPrime(x + 1, true);
  isPrime[0] = false;
  isPrime[1] = false;
  for (int i = 2; i * i <= x; i++)
  {
      if (isPrime[i])
      {
          for (int m = i * i; m <= x; m += i)
          {
              isPrime[m] = false;
          }
      }
  }
  long long ans=0;
  for (int i = 2; i <= x; i++)
  {
      if (isPrime[i])
      {
        ans+=i;
      }
  }
  cout<<"total prime sum"<<" "<<ans;
}

 
int main()
{
  simpleSieve(20000000);
 
  

}
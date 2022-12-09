#include <bits/stdc++.h>
using namespace std;
 
// To hold the prime numbers <= sqrt(n)
vector<int> primes;
 
// Get all the primes <= x
// x = sqrt(n)
void simpleSieve(int x)
{
  vector<bool> isPrime(x + 1, true);

  /*
  Making 0 and 1 as false since
  they are not prime
  */
  isPrime[0] = false;
  isPrime[1] = false;
 
  // Sieve for filtering out the primes <= x
  for (int i = 2; i * i <= x; i++)
  {
      if (isPrime[i])
      {
          // Cancelling out all the multiples of i
          for (int m = i * i; m <= x; m += i)
          {
              isPrime[m] = false;
          }
      }
  }
 
  // Add the primes into primes[]
  for (int i = 2; i <= x; i++)
  {
      if (isPrime[i])
      {
          primes.push_back(i);
      }
  }
}
 
void segmentedSieve(int low, int high, vector<int> &ans)
{
  vector<int> isPrime(high - low + 1, true);

  // Looping over all the primes
  for (int p : primes)
  {

      // Choosing the first multiple of p >= low
      int s = low / p * p;
      if (s < low)
      {
          s += p;
      }

      // Cancelling out the factors of p
      for (int i = s; i <= high; i += p)
      {
          isPrime[i - low] = false;
      }
  }

  // Append primes in range [low, high] in ans
  long long ourAns=0;
  for (int i = 0; i < isPrime.size(); i++)
  {
      if (isPrime[i])
      {
          ans.push_back(i + low);
          ourAns+=(i+low);
      }
  }
  cout<<"ourAns"<<" "<<ourAns;
}
 
int main()
{
  primes.clear();

 
   // Take input
  int n;
  cin >> n;
 
  // Get all primes <= sqrt(n)
  simpleSieve((int)floor(sqrt(n)));
 
  vector<int> ans;

  /*
  divide the range [2, n-1] into
  smaller segments of size sqrt(n),
  use segmentedSieve to find all the
  primes in the range [l, r] and append
  to ans
  */
 
  // For every segment, we call segmentedSieve()
  int updateVal = floor(sqrt(n));
  for (int l = 2; l < n; l += updateVal)
  {
      int r = min(l + updateVal - 1, n - 1);
      segmentedSieve(l, r, ans);
  }

  // Printing all the primes < n
  long long sum=0;
  for (int p : ans)
  {
      sum+=p;
  }

  cout<<"total sum"<<" "<<sum;
}
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr)
{
  return lower_bound(arr.begin(), arr.end() , 5)-arr.begin();
}
int main()
{
  vector<int> arr{2, 3, 6, 9, 12};
  
  cout<<solve(arr);
}


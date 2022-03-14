
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(const vector<int> &A, int B) {
  vector<int>result;
  unordered_map<int ,int>um;
  for(int i=0;i<A.size();i++){
      int search_ele=B-A[i];
   if(um.find(search_ele)!=um.end()){
      int index=um.at(search_ele);
      result.push_back(index+1);
      result.push_back(i+1);
      return result;
   }else{
       um.insert({A[i],i});
   }
  }
  return result;
}



int main()
{
	vector<int>v={4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
    vector<int>result;
    result=twoSum(v,-3);
	for(int num : result){
        cout<<num<<" ";
    }
    
	return 0;
}

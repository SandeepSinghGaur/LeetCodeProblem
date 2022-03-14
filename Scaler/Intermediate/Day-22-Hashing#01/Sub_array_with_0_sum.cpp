
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    for(int i=0;i<A.size();i++){
        if(A[i]==0)
        return 0;
    }
    unordered_set<long>us;
    vector<long>pf(A.size());
    pf[0]=A[0];
    for(int i=1;i<A.size();i++){
        pf[i]=pf[i-1]+A[i];
    }
    for(int i=0;i<A.size();i++){
        cout<<pf[i]<<" ";
    }
    for(int i=0;i<A.size();i++){
         if(pf[i]==0)
         return 1;
          if(us.find(pf[i])!=us.end()){
            return 1;
        }
        us.insert(pf[i]);
       
    }
    return 0;
  
}

int main()
{
	vector<int>v={190, 713, 462, 963, 993, 934, -762, -810, 261, -699, 542, 321, -549, -767, -985, 53, -253, 461, -29, -9, 221, -135, 923, -912, 979, -832, 311, 171, -437, -750, -482, 636, 370, -526, 655, 169, 607, -214, 284, -86, 418, -380, 222, 898, -822, 667, 885, 723, 707, 398, 254, 535, -878, -52, 476, -882, 475, -619, 347, -422, 862, -292, -511, 539, -244, 98, 913, 33, -483, 644, 801, 347, 661, -223, -92, -61, -647, 979, -306, 285, 818, -254, 0};
	cout<<solve(v)<<" ";
	return 0;
}


#include <bits/stdc++.h>
using namespace std;

int diffPossible(const vector<int> &A, int B) {
     unordered_set<int>us;
    for(int i=0;i<A.size();i++){
        int search_ele=B+A[i];
        if(us.find(A[i])!=us.end()){
            return 1;
        }
        else{
            if(A[i]>=B){
                us.insert((A[i]-B));
            }else{
               us.insert(search_ele);
            }
        }
    }
    return 0;
}




int main()
{
	vector<int>v={34, 63, 64, 38, 65, 83, 50, 44, 18, 34, 71, 80, 22, 28, 20, 96, 33, 70, 0, 25, 64, 96, 18, 2, 53, 100, 24, 47, 98, 69, 60, 55, 8, 38, 72, 94, 18, 68, 0, 53, 18, 30, 86, 55, 13, 93, 15, 43, 73, 68, 29 };
    cout<<diffPossible(v,97)<<" ";
	return 0;
}

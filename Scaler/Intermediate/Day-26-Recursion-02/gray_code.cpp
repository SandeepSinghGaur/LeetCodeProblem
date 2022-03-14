#include <bits/stdc++.h>
using namespace std;




int binaryToGray(int num)
{
    return num ^ (num >> 1);
}
vector<int>grayCode(int A) {
    vector<int> res;
    for (auto i = 0; i<(1<<A); ++i)
        res.push_back(binaryToGray(i));
    return res;
}
int main(){
    int A;
    cin>>A;
    vector<int>result;
    result=grayCode(A);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}
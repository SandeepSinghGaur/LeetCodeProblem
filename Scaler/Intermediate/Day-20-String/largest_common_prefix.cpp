#include <bits/stdc++.h>
using namespace std;

string longest_common_prefix(vector<string>& strs) {    
    string result="";
        for(int col=0;col<strs[0].size();col++){
            for(int row=0;row<strs.size()-1;row++){
                if(strs[row][col]!=strs[row+1][col]){
                    return result;
                }
            }
            result.push_back(strs[0][col]);
        }
        return result;
}

int main(){
    vector<string>v;
    v.push_back("flower");
    v.push_back("flow");
    v.push_back("flight");
    cout<<longest_common_prefix(v)<<" ";
}
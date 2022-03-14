#include <bits/stdc++.h>
using namespace std;


int is_dictionary(vector<string> &A, string B) {
     unordered_map<char,int>um;
    for(int i=0;i<B.length();i++){
        um.insert({B[i],i});
    }
   
   for(int i=0;i<A.size()-1;i++){
        bool terminate=false;
            for(int j=0;j<A[i].length() && j<A[i+1].length();j++){
                if(um[A[i][j]]>um[A[i+1][j]]){
                      return 0;
                }
                if(um[A[i][j]]<um[A[i+1][j]]){
                    terminate=true;
                      break;
                }
            }
            if(!terminate){
                if(A[i].length()>A[i+1].length())
                return 0;
            }

   }
   return 1;
}
int main()
{
	vector<string>v={"hello", "scaler", "interviewbit"};
    string B = "adhbcfegskjlponmirqtxwuvzy";
    cout<<is_dictionary(v,B)<<" ";
	return 0;
}


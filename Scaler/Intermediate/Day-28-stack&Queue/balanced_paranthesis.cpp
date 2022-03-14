
#include <bits/stdc++.h>
using namespace std;
  stack<char>s;
int solve(string A) {
    if(A[0]==')')
    return 0;
    if(A[A.size()-1]=='(')
    return 0;
    for(int i=0;i<A.size();i++){
        if(s.empty()){
            s.push(A[i]);
        }
        else if(A[i]!=s.top()){
            s.pop();
        }else{
            s.push(A[i]);
        }
    }
    if(s.empty()){
        return 1;
    }
    return 0;
 
}


int main()
{
     while(!s.empty()){
        s.pop();
    }
	string a = "(()";
	cout << solve(a) << endl;
	return 0;
}

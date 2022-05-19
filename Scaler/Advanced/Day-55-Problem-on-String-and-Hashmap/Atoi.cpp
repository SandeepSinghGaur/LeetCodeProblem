/*
There are certain questions where the interviewer would intentionally frame the question vague.
The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.

Input : "9 2704"
Output : 9

Note: There might be multiple corner cases here. Clarify all your doubts using "See Expected Output".

Questions:

Q1. Does string contain whitespace characters before the number? A. Yes

Q2. Can the string have garbage characters after the number? A. Yes. Ignore it.

Q3. If no numeric character is found before encountering garbage characters, what should I do? A. Return 0.

Q4. What if the integer overflows? A. Return INTMAX if the number is positive, INTMIN otherwise.

Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI. If you do, we will disqualify your submission retroactively and give you penalty points.
*/
#include<bits/stdc++.h>
using namespace std;
int solve(string A){
    vector<int>v;
    int p=0;
    bool check=true;
    for(int i=0;i<A.length();i++){
        // cout<<A[i]-'0'<<endl;
        while((A[i]-'0'<0) && !isspace(A[i]) && v.size()==0){
             i++;
             p++;
        }
        while(isspace(A[i]) && v.size()==0){
            if(p!=0){
                check=false;
                break;
            }
             i++;
        }
        if(!check) break;
        if((isspace(A[i])|| A[i]-'0'>9) && v.size()>0){
            break;
        }
        v.push_back(A[i]-'0');
    }
    int finalNumber = 0;
for (int i = 0; i < v.size(); i++) {
    int num = v[i];
    if (num != 0) {
        while (num > 0) {
            finalNumber *= 10;
            num /= 10;
        }
        finalNumber += v[i];
    } else {
        finalNumber *= 10;
    }
}
if(A[0]=='-'){
    return -1*finalNumber;
}
return finalNumber;
}
int main(){
    string A="- 88297";
    cout<<solve(A);
}
/*
Problem Description
You are given a string A of lowercase English alphabets. Rearrange the characters of the given string A such that there is no boring substring in A.

A boring substring has the following properties:

Its length is 2.
Both the characters are consecutive, for example - "ab", "cd", "dc", "zy" etc.(If the first character is C then the next character can be either (C+1) or (C-1)).
Return 1 if it is possible to rearrange the letters of A such that there are no boring substrings in A else, return 0.


Problem Constraints
1 <= |A| <= 10^5

Input
 A = "abcd"
 A = "aab"
Output
 1
 0
*/
/*
Approach-:
1-we can represent every number in o or 1;
2-if we keep all even together and all odd together we will not get and Boring string just one condition need to check
  when we concatnate even to odd or odd to even need to check difference must be greater than 1.

Time Complaxity:
1- we are taking two array which are storing odd character and even character
TC:O(A.length())
SC:O(A.length())  

*/
#include<bits/stdc++.h>
using namespace std;

int solve(string &A){
   vector<char>evenChar;
vector<char>oddChar;
for(int i=0;i<A.length();i++){
    if((A[i]-'0')%2==0){
        evenChar.push_back(A[i]);
    }else{
        oddChar.push_back(A[i]);
    }
}
int num=1;
for(auto it:oddChar){
    cout<<num<<" "<<it<<" "<<endl;
    num++;
}
num=1;
cout<<"===================="<<endl;
for(auto it:evenChar){
   cout<<num<<" "<<it<<" "<<endl;
   num++;
}
if(evenChar.size()==0 || oddChar.size()==0){
    return 1;
}
if(evenChar.size()>oddChar.size()){
  for(int i=0;i<evenChar.size();i++){
      if(abs((evenChar[i]-'0')-(oddChar[0]-'0'))>1){
          return 1;
      }
  }
  return 0;
}else{
      for(int i=0;i<oddChar.size();i++){
      if(abs((oddChar[i]-'0')-(evenChar[0]-'0'))>1){
          return 1;
      }
  }
  return 0;
}
}
int main(){
    string str="hbbgcbcadjgii";
    cout<<solve(str);
}

/* Problem: 13. Roman to Integer :Easy date:27/02/22 */


/*convert Roman Number to Integer */

/*Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3. */

/* https://leetcode.com/problems/roman-to-integer/ */

// Time Complaxity: O(n)



#include <bits/stdc++.h>
using namespace std;

  int romanToInt(string s) {
        unordered_map<char,int>um;
        um['I']=1;
        um['V']=5;
        um['X']=10;
        um['L']=50;
        um['C']=100;
        um['D']=500;
        um['M']=1000;
        int sum=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='I' && s[i+1]=='V'){
                sum+=um[s[i+1]]-um[s[i]];
                i++;
            }else if(s[i]=='I' && s[i+1]=='X'){
                sum+=um[s[i+1]]-um[s[i]];
                i++;
            }else if(s[i]=='X' && s[i+1]=='L'){
                sum+=um[s[i+1]]-um[s[i]];
                i++;
            }else if(s[i]=='X' && s[i+1]=='C'){
                sum+=um[s[i+1]]-um[s[i]];
                i++;
            }else if(s[i]=='C' && s[i+1]=='D'){
                sum+=um[s[i+1]]-um[s[i]];
                i++;
            }else if(s[i]=='C' && s[i+1]=='M'){
                sum+=um[s[i+1]]-um[s[i]];
                i++;
            }else{
                sum+=um[s[i]];
            }
        }
        return sum;
    }

int main(){
    string str="LVIII";
   cout<<romanToInt(str);
}



/* Problem: 13. Roman to Integer :Easy date:27/02/22 */


/*convert Roman Number to Integer */

/*Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3. */

/* https://leetcode.com/problems/roman-to-integer/ */

// Time Complaxity: O(n)



#include <bits/stdc++.h>
using namespace std;

   int strStr(string haystack, string needle) {
        bool check=true;
        if(needle.length()==0 )
            return 0;
        for(int i=0;i<haystack.length();i++){
            if(haystack[i]==needle[0]){
                for(int j=1;j<needle.length();j++){
                    check=haystack[j+i]==needle[j]?true:false;
                    if(!check)
                        break;
                }
                if(check)
                    return i;
              
            }
        }
        return -1;
    }

int main(){
    string str="";
    string str2="a";
   cout<<strStr(str,str2);
}
/*
"hello"
"ll"
"aaaaa"
"bba"
""
""
""
"a"
*/


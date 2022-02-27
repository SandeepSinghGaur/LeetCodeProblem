
/* Problem 9. Palindrome Number :Easy date:27/02/22 */


/* Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not. */

/*Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left. */

/* https://leetcode.com/problems/palindrome-number/ */

// Time Complaxity: O(n^2)





#include <bits/stdc++.h>
using namespace std;



 bool isPalindrome(int x) {
        string str=to_string(x);
        int start=0;
        int last=str.length()-1;
        while(start<last){
            if(str[start]==str[last]){
                start++,last--;
            }else{
                return false;
            }
            
        }
         return true;   
    }


int main()
{
    int x=121;
	cout<<isPalindrome(x);
    
	return 0;
}


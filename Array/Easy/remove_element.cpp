
/* Problem: 13. Roman to Integer :Easy date:27/02/22 */


/*convert Roman Number to Integer */

/*Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3. */

/* https://leetcode.com/problems/roman-to-integer/ */

// Time Complaxity: O(n)



#include <bits/stdc++.h>
using namespace std;

  int removeElement(vector<int>& nums, int val) {
        int count=0;
        int sum=0;
         for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                sum++;
            }
         }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                count++;
                int j=i;
                int k=i+1;
               while(j<nums.size()-1 && k<=nums.size()-2){
                   if(nums[j]==nums[k]){
                       k++;
                   }else{
                       swap(nums[j],nums[k]);
                        j++;
                        k++;
                   }
                   
               }
            }
        }
        if(nums.size()==sum)
            return 0;
        return nums.size()-count;
    }

int main(){
    vector<int>v={4,5};
   cout<<removeElement(v,5);
}


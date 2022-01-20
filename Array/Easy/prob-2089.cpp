
//Problem_code and Category and date
code:2089 Category:Easy date:20/01/22

//Problem Statement

You are given a 0-indexed integer array nums and a target element target.

A target index is an index i such that nums[i] == target.

Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

//Solution

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
         sort(nums.begin(), nums.end());
      vector<int>temp;
      for(int i=0;i<nums.size();i++){
         if(target==nums[i]){
           temp.push_back(i);
         }  
      }
      return temp;
    }
};

 /**
     * Optimize Approach: Just apply what's said in the statement.
     * TC: O(nlogn)
     * SC: O(n)
     */
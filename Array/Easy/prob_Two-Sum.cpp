
//Problem_code and Category and date
code:TWO SUM Category:Easy date:22/01/22

//Problem Statement

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

//Solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>dummy;
        int n=nums.size();
        unordered_map<int,int>us;
        for(int i=0;i<n;i++){
                    int x=target-nums[i];
            if(us.find(nums[i])!=us.end()){
                 dummy.push_back(us[nums[i]]);
                dummy.push_back(i);
               
            }else{
                us.insert({x,i});
            }
            }
        return dummy;
        
    }
};

// Time Complaxity and Space Complaxity

 /**
     * MY Approach: using unordered_map able to reduce time complaxity .
     * TC: O(n) 
     * SC: O(n)
       I am using the dummy vector to saved the index and finally I am returning this Index.
     */
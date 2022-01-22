
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
        for(int i=0;i<n;i++){
             if(target==0 && nums[i]==0){
                     dummy.push_back(i);
                }
               else{
                    int sum=0;
                    for(int j=i+1;j<n;j++){
                      sum=nums[i]+nums[j];
                      if(sum==target){
                      dummy.push_back(i);
                      dummy.push_back(j);
                      }
                  }
            }
           
        }
        return dummy;  
    }
};

// Time Complaxity and Space Complaxity

 /**
     * MY Approach: Just apply what's said in the statement.
     * TC: O(n^2) 
       Because I am two for loop for getting the pair of (i,j)
     * SC: O(n)
       I am using the dummy vector to saved the index and finally I am returning this Index.
     */
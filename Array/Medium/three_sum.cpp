
/* Problem: 15. 3Sum :Medium date:27/02/22 */


/* Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets. */

/* Input: nums = [-1,0,1,2,-1,-4]
   Output: [[-1,-1,2],[-1,0,1]]  */

/* https://leetcode.com/problems/3sum/ */

// Time Complaxity: O(n^2)





#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>temp;
        if(nums.size()<3){
            return temp;
        }
       vector<vector<int> > set_of_vectors;
        for(int i=0;i<nums.size()-2;i++){
            int start=i+1;
            int end=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1])
                continue;
            while(start<end){
                if(nums[start]+nums[end]+nums[i]==0){
                     vector<int>temp_ele;
                    temp_ele.push_back(nums[i]);
                    temp_ele.push_back(nums[start]);
                    temp_ele.push_back(nums[end]);
                    set_of_vectors.push_back(temp_ele);
                    end--;
                    while(start<end && nums[end]==nums[end+1] ){
                    end=end-1;
                    }
                }
                nums[i]+nums[start]+nums[end]>0?end--:start++;
            }
        }
        for(auto num :set_of_vectors){
            temp.push_back(num);
        }
        
        return temp;
    }


int main()
{
	vector<int>v={3,0,-2,-1,1,2};
    vector<vector<int>>result;
	result=threeSum(v);
    for(int row=0;row<result.size();row++){
        for(int j=0;j<result[row].size();j++){
            cout<<result[row][j]<<" ";
        }
        cout<<endl;
    }
    
	return 0;
}


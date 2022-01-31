//Problem_code , Category and date
problem: 11. Container With Most Water Category:Medium date:01/02/22

//Problem Statement
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.


//Input 

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.


//Contraints
n == height.length
2 <= n <= 105
0 <= height[i] <= 104


//Solution

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int max_water=INT_MIN;
        while(i<j){
            int num=min(height[i],height[j]);
            int water=num*(j-i);
            max_water=max(max_water,water);
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return max_water;
        
    }
};

//Observation

1st step check Contraints according that decide  in which time complaxity the TLE will come.


//Complaxity Analysis

TC: O(n)
SC:O(1)

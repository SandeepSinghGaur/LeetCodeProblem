
//Problem_code and Category and date
code:2133 Category:Easy date:20/01/22

//Problem Statement

An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).

Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.

//Solution

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        vector<int>v1;
        vector<int>v2(matrix.size());
        vector<int>v3(matrix.size());
        for(int i=0;i<matrix.size();i++){
            v1.push_back(i+1);
        }
       
        for(int i=0;i<matrix.size();i++ ){
            
            for(int j=0;j<matrix[i].size();j++){
                v2[j]=matrix[i][j];
                v3[j]=matrix[j][i];
                }
            for(int i=0;i<matrix.size();i++){
                  auto it =find(v2.begin(), v2.end(),v1[i]);
                 auto it2 =find(v3.begin(), v3.end(),v1[i]);
                  if (!(it != v2.end()))
                    return false;
                if (!(it2 != v3.end()))
                    return false;
            }
        }
              
        return true;
          
    }
};
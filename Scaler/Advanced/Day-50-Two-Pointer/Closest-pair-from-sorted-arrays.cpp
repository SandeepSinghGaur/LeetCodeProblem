/*
Problem Description

Given two sorted arrays of distinct integers, A and B, and an integer C, find and return the pair whose sum is closest to C and the pair has one element from each array.

More formally, find A[i] and B[j] such that abs((A[i] + B[j]) - C) has minimum value.

If there are multiple solutions find the one with minimum i and even if there are multiple values of j for the same i then return the one with minimum j.

Return an array with two elements {A[i], B[j]}.

Problem Constraints

1 <= length of both the arrays <= 100000

1 <= A[i], B[i] <= 10^9

1 <= C <= 10^9

Input
 A = [1, 2, 3, 4, 5]
 B = [2, 4, 6, 8]
 C = 9
Output
 [1,8]
*/

#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B, int C) {
  int i=0;
  int j=0;
  int min_val;
  vector<int>result;
  int abs_val=(A[i]+B[j]);
  cout<<abs_val<<" "<<endl;
  min_val=abs(C-abs_val);
  cout<<min_val<<endl;
  int jindex=j;
  int iIndex=i;
  for(j=1;j<B.size();j++){
      if(abs(C-(A[iIndex]+B[j]))<min_val){
             min_val=abs(C-(A[iIndex]+B[j]));
             jindex=j;
      }else if(abs(C-(A[iIndex]+B[j]))==min_val){
        result.pb(A[iIndex]);
        result.pb(B[j]);
        return result;
      }
      else{
          break;
      }
  }
  for(i=1;j<B.size();i++){
      if(abs(C-(A[i]+B[jindex]))<min_val){
             min_val=abs(C-(A[i]+B[jindex]));
             iIndex=i;
      }else if(abs(C-(A[i]+B[jindex]))==min_val){
        result.pb(A[i]);
        result.pb(B[jindex]);
        return result;
      }
      else{
          break;
      }
  }
  result.pb(A[iIndex]);
        result.pb(B[jindex]);
        return result;

}
int main(){
    vector<int>A={ 6, 7, 9, 13, 21, 29, 56, 74, 77, 83, 84, 88, 93, 96, 101, 104, 114, 115, 122, 125, 144, 147, 151, 152, 154, 161, 165, 167, 174, 179, 185, 189, 192, 194, 198, 201, 203, 208, 224, 229, 230, 238, 252, 253, 257, 264, 266, 275, 278, 279, 282, 284, 291, 312, 316, 322, 332, 335, 336, 339, 364, 380, 381, 384, 387, 388, 390, 392, 394, 395, 401, 403, 431, 432, 440, 442, 443, 444, 446, 451, 454, 461, 470, 483, 492};
    vector<int>B={2, 8, 13, 16, 19, 21, 22, 23, 37, 48, 63, 66, 68, 71, 72, 95, 102, 116, 123, 127, 131, 132, 146, 148, 153, 171, 173, 179, 187, 194, 215, 220, 227, 229, 240, 245, 254, 255, 257, 259, 271, 276, 277, 286, 296, 312, 314, 318, 321, 333, 339, 341, 343, 355, 356, 359, 363, 364, 380, 390, 393, 398, 401, 409, 413, 417, 427, 442, 444, 446, 454, 455, 459, 460, 468, 471, 473, 475, 476, 478, 479, 482, 483, 488, 489};
    int C=409;
    vector<int>result;
    result=solve(A,B, C);
    int i=1;
    for(auto it:result){
        cout<<it<<" ";
    }
}
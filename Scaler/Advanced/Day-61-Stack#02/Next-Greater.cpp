/*
Given an array A, find the next greater element G[i] for every element A[i] in the array.
The next greater element for an element A[i] is the first greater element on the right side of A[i] in the array, A.

More formally:

G[i] for an element A[i] = an element A[j] such that 
    j is minimum possible AND 
    j > i AND
    A[j] > A[i]
Elements for which no greater element exists, consider the next greater element as -1.

Problem Constraints
1 <= |A| <= 10^5

1 <= A[i] <= 10^7


Input
 A = [4, 5, 2, 10] 
Output
 [5, 10, 10, -1] 
*/


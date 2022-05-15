/*
Problem Description
You are given 3 sorted arrays A, B and C.

Find i, j, k such that : max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.

Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])).

Problem Constraints
0 <= len(A), len(B), len(c) <= 10^6

0 <= A[i], B[i], C[i] <= 10^7

Input
 A = [1, 4, 10]
 B = [2, 15, 20]
 C = [10, 12]
Output
5
*/
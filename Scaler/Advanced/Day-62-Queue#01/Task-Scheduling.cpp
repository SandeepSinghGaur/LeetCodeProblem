/*
Problem Description
A CPU has N tasks to be performed. It is to be noted that the tasks have to be completed in a specific order to avoid deadlock. In every clock cycle, the CPU can either perform a task or move it to the back of the queue. You are given the current state of the scheduler queue in array A and the required order of the tasks in array B.

Determine the minimum number of clock cycles to complete all the tasks.


Problem Constraints
1 <= N <= 1000
1 <= A[i], B[i] <= N

Input:
A = [2, 3, 1, 5, 4]
B = [1, 3, 5, 4, 2]

Output
10

*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, vector<int> &B) {
    queue<int>myQ;
    for(int i=0;i<A.size();i++){
        myQ.push(A[i]);
    }
    int cpu_cycle=0;
    for(int i=0;i<B.size();i++){
        while(B[i]!=myQ.front()){
            int k=myQ.front();
            myQ.pop();
            myQ.push(k);
            cpu_cycle++;
        }
      cpu_cycle++;
      myQ.pop();
        
    }
    return cpu_cycle;
}
int main(){
    vector<int>A={6, 7, 1, 2, 4, 5, 8, 3};
    vector<int>B={3, 7, 2, 5, 1, 8, 4, 6 };
    cout<<solve(A,B);
}
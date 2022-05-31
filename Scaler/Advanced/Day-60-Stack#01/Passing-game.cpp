/*
Problem Description
There is a football event going on in your city. In this event, you are given A passes and players having ids between 1 and 106.

Initially, some player with a given id had the ball in his possession. You have to make a program to display the id of the player who possessed the ball after exactly A passes.

There are two kinds of passes:

1) ID

2) 0

For the first kind of pass, the player in possession of the ball passes the ball "forward" to the player with id = ID.

For the second kind of pass, the player in possession of the ball passes the ball back to the player who had forwarded the ball to him.

In the second kind of pass "0" just means Back Pass.

Return the ID of the player who currently possesses the ball.


Problem Constraints
1 <= A <= 100000

1 <= B <= 100000

|C| = A

Input
 A = 10
 B = 23
 C = [86, 63, 60, 0, 47, 0, 99, 9, 0, 0]
Output
63
*/
#include<bits/stdc++.h>
using namespace std;

int solve(int A, int B, vector<int> &C) {
         stack<int>st;
    for(int i=0;i<C.size();i++){
        if(C[i]!=0){
            st.push(C[i]);
        }else{
            st.pop();
        }
    }
    if(st.empty()){
        return B;
    }
    return st.top();
}
int main(){
    int A=10;
    int B=23;
    vector<int>C={86, 63, 60, 0, 47, 0, 99, 9, 0, 0};
    cout<<solve(A,B,C);
}
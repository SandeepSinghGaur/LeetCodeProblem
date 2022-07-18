/*
A hotel manager has to process N advance bookings of rooms for the next season. His hotel has K rooms.

Bookings contain an arrival date and a departure date.

He wants to find out whether there are enough rooms in the hotel to satisfy the demand.

Write a program that solves this problem in time O(N log N) .


Problem Constraints
1 <= N <= 10^6

1 <= K <= 10^6

0 <= arrive[i] <= depart[i] <= 10^8

Input

arrive = [1, 3, 5]
depart = [2, 6, 8]
 K = 1

 Output
  False / 0 
*/

#include<bits/stdc++.h>
using namespace std;
 bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}
bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
   vector<pair<int,int>>zipped;
    for(int i=0;i<arrive.size();i++){
        zipped.push_back({arrive[i],depart[i]});
    }
    sort(zipped.begin(),zipped.end(),cmp);
      for(auto it:zipped){
        cout<<it.first<<" "<<it.second<<endl;
    }
    int count=0;
    int index=0;
    for(int i=1;i<zipped.size();i++){
        if(zipped[index].second>=zipped[i].first){
            count++;
        }else{
            index++;
        }
        cout<<"count"<<" "<<count<<endl;
        if(count+1>K){
            return false;
        }
    }
    return true;
}
 

int main(){
    vector<int>v1={9, 47, 17, 39, 35, 35, 20, 18, 15, 34, 11, 2, 45, 46, 15, 33, 47, 47, 10, 11, 27};
    vector<int>v2={32, 82, 39, 86, 81, 58, 64, 53, 40, 76, 40, 46, 63, 88, 56, 52, 50, 72, 22, 19, 38 };
    
    cout<<hotel(v1,v2,16);
}
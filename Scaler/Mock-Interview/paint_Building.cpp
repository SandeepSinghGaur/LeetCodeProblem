/*
Find the highest number that can be made from the given number 513 -> 531 
  1020 ->  2100

  1 4 3 2 3 1
  00000 3 2 1 2 0 00000

*/
#include<bits/stdc++.h>
using namespace std;

int Paint_Building(vector<int>&building_height){
     int count=0;
     int i=0;
     while(i<building_height.size() && building_height[i]!=0){
          for(int i=0;i<building_height.size();i++){
            if(i!=0 && building_height[i]==0){
                count++;
            }
               building_height[i]=building_height[i]-1;
               
           }
           count++;
     }
     return count;
     

}

int main(){
    vector<int>v={1, 4, 3, 2, 3, 1};
    cout<<Paint_Building(v);
}
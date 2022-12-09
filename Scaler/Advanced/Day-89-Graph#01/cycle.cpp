#include<bits/stdc++.h>
using namespace std;

int solve(int A, vector<vector<int> > &B) {
    //create adjancy list
    vector<int>adj_list[A+1];
    for(int i=0;i<A;i++){
        adj_list[B[i][0]].push_back(B[i][1]);
        adj_list[B[i][1]].push_back(B[i][0]);
    }
    vector<bool>isVisited(A+1,false);
    queue<pair<int,int>>q;
    q.push({1,1});
    while(!q.empty()){
        pair<int,int> ele=q.front();
        q.pop();
        isVisited[ele.first]=true;
        for(auto it:adj_list[ele.first]){
            if(isVisited[it]==false){
               q.push({it,ele.first});
            }else if(isVisited[it]==true && it==ele.second){
                    continue;
            }else{
               cout<<it<<" "<<ele.first<<" "<<ele.second;
                return 1;
            }    
        }
    }
    return 0;


}
int main(){
   vector<vector<int>>v={{1, 2},{2, 3},{3,4}};
   int A=4;
   cout<<solve(A,v);
}
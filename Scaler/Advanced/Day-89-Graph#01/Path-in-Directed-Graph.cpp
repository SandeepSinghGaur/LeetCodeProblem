#include<bits/stdc++.h>
using namespace std;


void add_edge(vector<int> adj_list[], int u, int v){
    adj_list[u].push_back(v);
}
int solve(int A, vector<vector<int> > &B) {
    vector<int>adj_list[A+1];
     for(int i=0;i<B.size();i++){
         add_edge(adj_list, B[i][0], B[i][1]);
     }
     for(int i=0;i<A+1;i++){
        vector<int>v=adj_list[i];
        for(auto it:v){
            cout<<it<<" ";
        }
        cout<<endl;

     }
     vector<bool>isVisited(A+1,false);
     queue<int>q;
     q.push(1);
     while(!q.empty()){
         int ele=q.front();
         q.pop();
         isVisited[ele]=true;
         vector<int>v=adj_list[ele];
         for(int i=0;i<v.size();i++){
             q.push(v[i]);
         }
     }
     if(isVisited[A]==true) return 1;
     return 0;
}
int main(){
   vector<vector<int>>v={{1, 2},{4, 1},{2, 4},{3, 4},{5, 2},{1, 3}};
   int A=5;
   cout<<solve(A,v);
}
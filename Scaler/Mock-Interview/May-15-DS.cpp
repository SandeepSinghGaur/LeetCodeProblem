/*

Given a grid and a word, write a function that returns the location of the word in the grid as a list of coordinates. If there are multiple matches, return any one.

vector<vector<char>> grid1 = {
  {'c', 'c', 't', 'n', 'a', 'x'},
  {'c', 'c', 'a', 't', 'n', 't'},
  {'a', 'c', 'n', 'n', 't', 't'},
  {'t', 'n', 'i', 'i', 'p', 'p'},
  {'a', 'o', 'o', 'o', 'a', 'a'},
  {'s', 'a', 'a', 'a', 'o', 'o'},
  {'k', 'a', 'i', 'o', 'k', 'i'},
};
string word1 = "catnip";
string word2 = "cccc";
string word3 = "s";
string word4 = "ant";
string word5 = "aoi";
string word6 = "ki";
string word7 = "aaoo";
string word8 = "ooo"; 

Output

find_word_location(grid1, word1) => [ (1, 1), (1, 2), (1, 3), (2, 3), (3, 3), (3, 4) ]
*/
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>find_word_in_grid(vector<vector<char>> &grid,string word){
    vector<pair<int,int>>ans;
    int word_length=word.length();
    int p1=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==word[p1]){
                ans.push_back(make_pair(i,j));
                p1++;
                j++;
                while(j<grid[i].size() && p1<word_length){
                    if(grid[i][j]==word[p1]){
                         ans.push_back(make_pair(i,j));
                          p1++;
                          j++;
                    }else if(grid[i++][j]==word[p1]){
                          ans.push_back(make_pair(i,j));
                          p1++;
                          j++;
                        }
                        else{
                          break;
                    }
                }
            }else{

            }
        }
    }
    return ans;

}

int main(){
    vector<vector<char>> grid1 = {
  {'c', 'c', 't', 'n', 'a', 'x'},
  {'c', 'c', 'a', 't', 'n', 't'},
  {'a', 'c', 'n', 'n', 't', 't'},
  {'t', 'n', 'i', 'i', 'p', 'p'},
  {'a', 'o', 'o', 'o', 'a', 'a'},
  {'s', 'a', 'a', 'a', 'o', 'o'},
  {'k', 'a', 'i', 'o', 'k', 'i'},
};
string word1 = "catnip";
vector<pair<int,int>>result;
result=find_word_in_grid(grid1,word1);
for(int i=0;i<result.size();i++){
    cout<<"("<<result[i].first<<","<<result[i].second<<")"<<" ";
}

}
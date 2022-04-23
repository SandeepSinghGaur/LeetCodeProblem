// write your code here...
// Your task is to write a function that, given a list of words and a string, finds and returns the word in the list that is scrambled up inside the string, if any exists. There will be at most one matching word. The letters don't need to be in order or next to each other. The letters cannot be reused.

// Example:
// words = ['cat', 'baby', 'dog', 'bird', 'car', 'ax']
// string1 = 'tcabnihjs'
// find_embedded_word(words, string1) -> cat (the letters do not have to be in order)

// string2 = 'tbcanihjs'
// find_embedded_word(words, string2) -> cat (the letters do not have to be together)

// string3 = 'baykkjl'
// find_embedded_word(words, string3) -> None / null (the letters cannot be reused)

// string4 = 'bbabylkkj'
// find_embedded_word(words, string4) -> baby

// string5 = 'ccc'
// find_embedded_word(words, string5) -> None / null

// string6 = 'breadmaking'
// find_embedded_word(words, string6) -> bird

// Complexity analysis variables:

// W = number of words in `words`
// S = maximal length of each word or string

// String[] words = new String[] { "cat", "baby", "dog", "bird", "car", "ax"};
// String string1 = "tcabnihjs";
// String string2 = "tbcanihjs";
// String string3 = "baykkjl";
// String string4 = "bbabylkkj";
// String string5 = "ccc";
// String string6 = 'breadmaking'

#include<bits/stdc++.h>
using namespace std;

vector<string>find_string(vector<string>&A,string s){
    unordered_map<char,int>um;
    vector<string>ans;
    for(int i=0;i<s.length();i++){
        um[s[i]]++;
    }

    for(int i=0;i<A.size();i++){
        unordered_map<char,int>temp;
        bool check=true;
        for(int j=0;j<A[i].length();j++){
            if(um.find(A[i][j])!=um.end() && um[A[i][j]]>0){
                temp[A[i][j]]++;
                um[A[i][j]]--;
            }else{
                check=false;
                break;
            }
        }
        if(!check){
            if(temp.size()>0){
                 for(auto it:temp){
                int prev_val=um[it.first];
                prev_val+=temp[it.first];
                um[it.first]=prev_val;
               }
            }
           
        }else{
            ans.push_back(A[i]);
        }
        
    }
    if(ans.size()==0){
        ans.push_back("NULL/None");
    }
    return ans;
}
int main(){
    vector<string>str={"cat", "baby", "dog", "bird", "car", "ax"};
    string s="bbabylkkj";
    vector<string>result;
    result=find_string(str,s);
    for(auto it:result){
        cout<<it<<" ";
    }
}
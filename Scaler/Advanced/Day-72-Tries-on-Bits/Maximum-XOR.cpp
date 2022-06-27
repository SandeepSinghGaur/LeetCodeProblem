/*
Problem Description
Given an array of integers A, find and return the maximum result of A[i] XOR A[j], where i, j are the indexes of the array.

Problem Constraints
1 <= length of the array <= 100000
0 <= A[i] <= 10^9


Input
 A = [1, 2, 3, 4, 5]
Output
7
*/


#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    unordered_map<char,TrieNode*>child;
    bool isFind;
    int count;
    TrieNode() : isFind(false),count(0),child(NULL) {}
};
void insert_into_trie(TrieNode *root,string s){
    TrieNode *curr=root;
    for(int i=0;i<s.length();i++){
        if(curr->child.find(s[i])==curr->child.end()){
             curr->child[s[i]]=new TrieNode();
        }
        curr=curr->child[s[i]];
    }
    curr->isFind=true;
}

string convert_number_into_bits(int A){
    string res="";
    while(A>0){
        if(A&1==1){
            res.push_back('1');
        }else{
            res.push_back('0');
        }
        A=A>>1;
    }
    reverse(res.begin(),res.end());
    return res;
}

int convert_bit_to_number(string s){
    int num=0;
    int k=0;
    for(int i=s.length()-1;i>=0;i--){
       num+=(s[i]<<k);
       k++;
    }
    return num;

}
   int find_word(TrieNode *root,string s){
    TrieNode *curr=root;
    string res="";
    for(int i=0;i<s.length();i++){
       if(s[i]=='1'){
           if(curr->child.find('0')!=curr->child.end()){
               curr=curr->child['0'];
               res.push_back('0');
           }else{
               curr=curr->child['1'];
                res.push_back('1');
           }
       }else{
            if(curr->child.find('1')!=curr->child.end()){
               curr=curr->child['1'];
                res.push_back('1');               

           }else{
               curr=curr->child['0'];
                res.push_back('1');
           }
       }
    }
    cout<<"A"<<" "<<res<<endl;
    cout<<"B"<<" "<<s<<endl;
   int a=convert_bit_to_number(res);
   cout<<"a"<<" "<<a<<endl;
   
   int b=convert_bit_to_number(s);
   cout<<"b"<<" "<<b<<endl;
   cout<<(a^b)<<endl;
       return (a^b);
}


int solve(vector<int> &A) {
    TrieNode *dummy=new TrieNode();
    int max_length=INT_MIN;
    for(int i=0;i<A.size();i++){
        string str=convert_number_into_bits(A[i]);
        int k=str.length();
        max_length=max(max_length,k);
    }
    for(int i=0;i<A.size();i++){
        string str=convert_number_into_bits(A[i]);
       
        int k;
        bool check=true;
        if(str.length()<max_length){
            k=max_length-str.length();
            check=false;
        }
        string p="";
        for(int i=1;i<=k;i++){
            p.push_back('0');
        }
        if(!check)
        str=p+str;
         cout<<"str"<<" "<<str<<endl;
        insert_into_trie(dummy,str);
    }
    int result=INT_MIN;
      for(int i=0;i<A.size();i++){
        string str=convert_number_into_bits(A[i]);
        int k=str.length();
        max_length=max(max_length,k);
    }
    for(int i=0;i<A.size();i++){

         string str=convert_number_into_bits(A[i]);
       
        int k;
        bool check=true;
        if(str.length()<max_length){
            k=max_length-str.length();
            check=false;
        }
        string p="";
        for(int i=1;i<=k;i++){
            p.push_back('0');
        }
        if(!check)
        str=p+str;
        cout<<"find"<<" "<<str<<endl;
         result=max(result,find_word(dummy,str));
    }
    return result;
}

 int main(){
    vector<int>v={1, 2, 3, 4, 5};
   
    //call the helper function
    cout<<solve(v);
    

 }

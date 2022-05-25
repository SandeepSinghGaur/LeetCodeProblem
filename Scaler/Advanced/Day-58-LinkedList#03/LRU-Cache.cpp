/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
The LRUCache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of "least recently used" : An access to an item is defined as a get or a set operation of the item. "Least recently used" item is the one with the oldest access time.

NOTE: If you are using any global variables, make sure to clear them in the constructor.

Example :

Input : 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 
*/

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    int k_val;
    Node *prev;
    Node *next;
    Node(int k,int x) : k_val(k),val(x),next(NULL),prev(NULL) {}
};
Node *head=NULL;
Node *tail=NULL;
unordered_map<int,Node*>um;
int lru_Size=2;
int curr_capacity=0;
void delete_Node(Node *del){
    if(del==head && lru_Size==1){
        head=NULL;
        tail=NULL;
        curr_capacity--;
    }
    if(del==head && lru_Size>1){
        head=head->next;
    }
    if(del->prev!=NULL){
        del->prev->next=del->next;
    }
    // if(del->next!=NULL){
    //     del->next->prev=del->prev;
    // }
    free(del);
}
void insert_into_tail(Node *tail,Node *newNode){
      if(tail!=NULL){
          tail->next=newNode;
          tail=tail->next;
      }
}
void Set(int key,int value){
    Node *newNode=new Node(key,value);
    if(head==NULL && tail==NULL){
        head=newNode;
        tail=newNode;
        curr_capacity++;
        um.insert({key,newNode});
    }else{
        if(um.find(key)!=um.end()){
            delete_Node(um[key]);
            if(head==NULL && tail==NULL){
                 head=newNode;
                 tail=newNode;
                 curr_capacity++;
                 um.insert({key,newNode});
            }else{
                 insert_into_tail(tail,newNode);
                 um[key]=newNode;
            }
            
        }else{
            if(lru_Size>curr_capacity){
                insert_into_tail(tail,newNode);
                um.insert({key,newNode});
                curr_capacity++; 
            }else{
            um.erase(head->k_val);
            delete_Node(head);
            insert_into_tail(tail,newNode);
            um.insert({key,newNode});
            }
        }
    }

}
int Get(int key){
    if(um.find(key)!=um.end()){
         Node *newNode=new Node(key,um[key]->val);
         delete_Node(um[key]);
            if(head==NULL && tail==NULL){
                 head=newNode;
                 tail=newNode;
                 curr_capacity++;
                 um.insert({key,newNode});
            }else{
                 insert_into_tail(tail,newNode);
                 um[key]=newNode;
            }
            return newNode->val;
    }
    return -1;
}
int main(){
    Set(1,1);
    Set(2,2);
    cout<<Get(1);
    Set(3,3);
    cout<<Get(1);
}
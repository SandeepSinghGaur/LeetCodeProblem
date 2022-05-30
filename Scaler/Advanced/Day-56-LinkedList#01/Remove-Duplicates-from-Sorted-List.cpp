/*
Given a sorted linked list, delete all duplicates such that each element appears only once..

Problem Constraints
0 <= length of linked list <= 10^6

Input 1:

 1->1->2

Output
 1->2
*/
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;
    ListNode(int d):data(d),next(NULL){};
};

ListNode* solve(ListNode* A) {
    ListNode *start=A;
    ListNode *fast=A;
    ListNode *prev=NULL;
    if(fast->next==NULL){
        A=NULL;
        return A;
    }
    if(fast->next->next==NULL){
        A->next=NULL;
        return A;
    }
    while(fast->next!=NULL && fast->next->next!=NULL){
        prev=start;
        start=start->next;
        fast=fast->next->next;
    }
    if(fast->next!=NULL){
        prev=prev->next;
         ListNode *del=prev->next;
         prev->next=prev->next->next;
         free(del);
         return A;
    }
  prev->next=prev->next->next;
  free(start);
  return A;
}

int main(){
    ListNode *res,*head;
    res=solve(head);
}
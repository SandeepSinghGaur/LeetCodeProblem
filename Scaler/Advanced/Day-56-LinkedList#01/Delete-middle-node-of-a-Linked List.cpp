/*
Given a singly linked list, delete middle of the linked list.

For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5

If there are even nodes, then there would be two middle nodes, we need to delete the second middle element.

For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.

Return the head of the linked list after removing the middle node.

If the input linked list has 1 node, then this node should be deleted and a null node should be returned.
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
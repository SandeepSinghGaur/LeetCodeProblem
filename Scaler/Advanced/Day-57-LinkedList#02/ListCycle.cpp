/*
Problem Description

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Input: 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3.
*/
#include<bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  ListNode* detectCycle(ListNode* A) {
  ListNode *temp=A;
  ListNode *slow=A;
  ListNode *fast=A;
  bool check=true;
  while(fast->next!=NULL && fast->next->next!=NULL){
      slow=slow->next;
      fast=fast->next->next;
      if(slow==fast){
          check=false;
          break;
      }
  }
  if(check){
      return NULL;
  }
  while(temp!=slow){
      temp=temp->next;
      slow=slow->next;
  }
  return slow;
}

int main(){
ListNode *head;
ListNode *result;
result=detectCycle(head);
}
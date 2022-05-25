/*
Given a linked list A, remove the B-th node from the end of the list and return its head.

For example, Given linked list: 1->2->3->4->5, and B = 2. After removing the second node from the end, the linked list becomes 1->2->3->5.

NOTE: If B is greater than the size of the list, remove the first node of the list.

NOTE: Try doing it using constant additional space.

Problem Constraints
1 <= |A| <= 10^6

Input
A = [1, 2, 3, 4, 5]
B = 2
Output
[1, 2, 3, 5]
*/


#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;
    ListNode(int d):data(d),next(NULL){};
};

 ListNode* revershList(ListNode *A){
      ListNode *prev=NULL;
      ListNode *curr=A;
    while(curr!=NULL){
        ListNode *nextPtr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextPtr;
    }
    return prev;
 }

ListNode* removeNthFromEnd(ListNode* A, int B) {
    ListNode *temp=A;
    int n=0;
    while(temp!=NULL){
        n++;
        temp=temp->next;
    }
    if(n==1 && n==B){
       A=NULL;
       return A;
    }
    if(B>n){
        A=A->next;
        return A;
    }
    ListNode *head=revershList(A);
    ListNode *del=head;
    if(B==1){
        ListNode *freeNode=head;
        head=head->next;
        free(freeNode);
         return revershList(head);
    }
    int count=1;
    while(count+1!=B){
        count++;
        del=del->next;
    }
    ListNode *freeNode=del->next;
    del->next=del->next->next;
    free(freeNode);
    return revershList(head);
   
}

int main(){
    ListNode *res,*head;
    res=removeNthFromEnd(head,2);
}

#include <bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  ListNode *head=NULL;
  int size_of_ll=0;

void insert_node(int value) {
      ListNode *newListNode=new ListNode(value);
       if(head==NULL){
           head=newListNode;
       }else{
            newListNode->next=head;
            head=newListNode;
        }
        size_of_ll++;
 }
void append_in_last(int value) {
      ListNode *newListNode=new ListNode(value);
       if(head==NULL){
           head=newListNode;
       }else{
            ListNode *temp=head;
             while(temp->next!=NULL){
                 temp=temp->next;
             }
            temp->next=newListNode;
        }
        size_of_ll++;
 }
void insert_at_position(int value,int position) {
     if(position>=0 && position<=size_of_ll){
        ListNode *newListNode=new ListNode(value);
        if(position==0){
           newListNode->next=head;
           head=newListNode;
         }else{
               int count=1;
          ListNode *temp=head;
          while(count<position-1){
               temp=temp->next;
               count++;
          }
          newListNode->next=temp->next;
          temp->next=newListNode;
         }
         size_of_ll++;
          
     }
    
 }
void delete_ListNode(int position){
    if(head==NULL)
    return;
 if(position>=0 && position<size_of_ll){
    if(position==0){
        head=head->next;
        size_of_ll--;
        return;
    }
    int count=1;
    ListNode *temp=head->next;
    ListNode *prev=head;
    while(temp->next!=NULL){
        if(count==position){
            prev->next=temp->next;
            size_of_ll--;
            return;
        }
        temp=temp->next;
        prev=prev->next;
        count++;
    }
    prev->next=NULL;
    size_of_ll--;
 }
}
ListNode* solve(vector<vector<int> > &A) {
     int n=A.size();
    for(int i=0;i<n;i++){
            int operation=A[i][0];
            switch(operation){
                case 0:
                insert_node(A[i][1]);
                break;
                case 1:
                append_in_last(A[i][1]);
                 break;
                case 2:
                insert_at_position(A[i][1],A[i][2]);
                 break;
                default:
                delete_ListNode(A[i][1]);
                 break;  
            }
    }
    return head;
}
int main(){
    ListNode *temp;
    head=NULL;
    size_of_ll=0;
    // vector<vector<int>>v={{2, 18, 0},{2, 5, 1},{2, 8, 0},{1, 7, -1},{1, 5, -1}};
    // vector<vector<int>>v={{0, 1, -1},{1, 2, -1},{2, 3, 1},{0, 4, -1},{3, 1, -1},{3, 2, -1}};
    vector<vector<int>>v={{2, 6, 0},{1, 17, -1},{1, 19, -1},{2, 16, 1},{1, 13, -1},{3, 3, -1},{1,19,-1}};
    temp=solve(v);
    while(temp!=NULL){
        cout<<temp->val;
        temp=temp->next;
        if(temp!=NULL){
             cout<<"->";
        }
    }
}

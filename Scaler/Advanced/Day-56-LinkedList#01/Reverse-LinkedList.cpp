/*
Problem Description
You are given a singly linked list having head node A. You have to reverse the linked list and return the head node of that reversed list.

NOTE: You have to do it in-place and in one-pass.

Problem Constraints
1 <= Length of linked list <= 10^5

Value of each node is within the range of a 32-bit integer.

Input
A = 1 -> 2 -> 3 -> 4 -> 5 -> NULL 
Output
5 -> 4 -> 3 -> 2 -> 1 -> NULL 
*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
Node *head=NULL;
int size_of_ll=0;
void Insert_Node_LL(){
    //insert 5 Node in LL
    int k;
    cin>>k;
    if(head==NULL){
         int x;
        cin>>x;
        Node *newNode=new Node(x);
        head=newNode;
    }
    Node *temp=head;
    while(k!=0){
        int x;
        cin>>x;
        Node *newNode=new Node(x);
        temp->next=newNode;
        temp=temp->next;
        size_of_ll++;
        k--;
    }

}
void print(){
    if(head==NULL){
        cout<<"List is Empty";
    }
    else{
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

Node* reverse_LL(Node* A){
     if(A==NULL)
    return NULL;
    Node *prev=NULL;
    Node *curr=A;
    while(curr!=NULL){
        Node *nextPTR=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextPTR;
    }
    A=prev;
    return A;
}

void print_reverse(Node *start){
    if(start==NULL){
        cout<<"List is Empty";
    }
    else{
        Node *temp=start;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
         cout<<endl;
    }
}
int printMiddleElement(Node *A){
   int size_of_ll=0;
  Node *temp=A;
  while(temp!=NULL){
     size_of_ll++;
     temp=temp->next;
  }
  cout<<"size of ll:"<<size_of_ll<<endl;
    int midLength;
    if(size_of_ll%2==0){
       midLength=(size_of_ll/2);
    }else{
        midLength=floor(size_of_ll/2);
    }
    int k=0;
    Node *temp2=A;
    while(k!=midLength){
      temp2=temp2->next;
      k++;
    }
    return temp2->data;
}


int main(){
    Insert_Node_LL();
    cout<<"Linked List"<<endl;
    print();
    cout<<"Middle Element:"<<printMiddleElement(head)<<endl;
    Node * res=reverse_LL(head);
    cout<<"reverse LL"<<endl;
    print_reverse(res);
}
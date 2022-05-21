/*
Problem Description
Given a singly linked list A and an integer B, reverse the nodes of the list B at a time and return the modified linked list.

Problem Constraints
1 <= |A| <= 10^3

B always divides A

Input
 A = [1, 2, 3, 4, 5, 6]
 B = 2

output
[2, 1, 4, 3, 6, 5]
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

Node* print_k_reverse(Node* A){
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
Node * reverse_k_LL(Node *A,int B){
   if(B<=1){
        return A;
    }
    Node *temp=A;
    int size_of_ll=0;
    if(temp!=NULL){
        size_of_ll++;
        temp=temp->next;
    }
    if(B>=size_of_ll){
        if(A==NULL)
        return NULL;
        Node *prev=NULL;
        Node *curr=head;
        while(curr!=NULL){
            Node *nextPTR=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextPTR;
        }
        head=prev;
        return head;
    }else{
        Node *prev=NULL;
        Node *curr=head;
        for(int i=0;i<size_of_ll;i++){
            int x=0;
            while(x!=B){
                Node *nextPTR=curr->next;
                nextPTR->next=curr->next;
            }
        }
        return head;
    }
}





int main(){
    Insert_Node_LL();
    Node * res=reverse_k_LL(head,1);
    cout<<"reverse LL"<<endl;
    print_k_reverse(res);
}
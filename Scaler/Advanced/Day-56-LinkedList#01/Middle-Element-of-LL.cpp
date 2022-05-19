/*
Problem Description
Given a linked list of integers, find and return the middle element of the linked list.

NOTE: If there are N nodes in the linked list and N is even then return the (N/2 + 1)th element.

Problem Constraints
1 <= length of the linked list <= 100000

1 <= Node value <= 10^9

Input
1 -> 2 -> 3 -> 4 -> 5
Output
3
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

int printMiddleElement(Node *A){

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
    cout<<"Middle Element:"<<printMiddleElement(head)<<endl;
}
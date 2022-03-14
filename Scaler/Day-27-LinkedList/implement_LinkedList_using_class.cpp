/* This is a comment */
#include <bits/stdc++.h>

using namespace std;

class LinkedList {
  struct Node {
    int data;
    Node * next;
    Node(int d ) {
      data = d;
      next = NULL;
    }
  };
  Node * head;
  int size_of_ll=0;
  public:
    LinkedList() {
      head = NULL;
    }
//     public:
//     void insert_node(int value) {
//         Node *newNode=new Node(value);
//         if(head==NULL){
//             head=newNode;
//         }else{
//             Node *temp=head;
//             while(temp->next!=NULL){
//                 temp=temp->next;
//             }
//             temp->next=newNode;
//         }

// }
    public:
    void insert_node_at_position(int position,int value) {
       if(position>=1 && position<=size_of_ll+1){
         Node *newNode=new Node(value);
         if(position==1){
           newNode->next=head;
           head=newNode;
         }else{
           int count=1;
           Node *temp=head;
           while(count<position-1){
                 temp=temp->next;
                 count++;
           }
           newNode->next=temp->next;
           temp->next=newNode;
         }
       }
       size_of_ll++;
}
public:
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
        cout<<"All Element printed";
        cout<<endl;
    }
}

public:
void delete_node(int position){
  if(head==NULL){
    return;
  }
  if(head->next==NULL && position==1){
    head==NULL;
  }else if(head->next!=NULL && position==1){
    head=head->next;
  }
  else{
    int count=1;
     Node *temp=head->next;
     Node *prev=head;
     while (temp->next!=NULL)
     {
       count++;
       if(count==position){
         temp=temp->next;
         prev->next=temp;
         return;
       }
       temp=temp->next;
       prev=prev->next;
     }
     prev->next=NULL;
  }
}
  


};

int main() {
  int a, b,c,position;
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> position;
  LinkedList ll = LinkedList();
  ll.insert_node_at_position(position,a);
  // ll.insert_node_at_position(2,b);
  // ll.insert_node_at_position(3,c);
  ll.print();
  ll.delete_node(2);
  ll.print();
  return 0;
}
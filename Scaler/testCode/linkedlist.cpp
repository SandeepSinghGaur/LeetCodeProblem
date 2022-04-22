#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

// class LinkedList{
//     Node *head;
//     LinkedList(){head=nullptr;}
    
//     void insert_node(int position, int value);
//     void delete_node(int position);
//     void print_ll();
// };

// LinkedList *start = new LinkedList;

Node *head = nullptr;

void insert_node(int position, int value) {
    // @params position, integer
    // @params value, integer
    Node *newNode = new Node(value);
    Node *temp = head;
    // if position is 1, position of head needs to change
    if (position == 1 || head==nullptr)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    // else head does not change
    while (--position && temp->next != nullptr)
        // corner case: if position is greater than size of list - append at end!
        temp = temp->next;

    // exits when temp==null, if position>length of linked list
    newNode->next = temp->next;
    temp->next = newNode;

    return;
}

void delete_node(int position) {
    // @params position, integer
    if (head == nullptr)
        return;

    Node *temp = head;
    // position is 0 - head changes
    if (position == 1)
    {
        head = head->next;
        free(temp);
        return;
    }
    // else head does not change
    else
    {
        int next_position=1;
        while (++next_position<position){
            temp = temp->next;
            if(temp->next==nullptr) return; 
        }
        // problem: will stop at temp->next == nullptr - temp->next->next is undefined! (in case of position>length of list)
        Node *removed = temp->next;
        temp->next = temp->next->next;
        free(removed);
        return ;
    }
}

void print_ll() {
    // Output each element followed by a space
    Node* temp=head;
    while(temp){
        cout<<temp->data;
        if(temp->next==nullptr) break;
        cout<<" ";
        temp=temp->next;
    }
}


// problems of inheritance and design
// problem of global variable, without inheritance
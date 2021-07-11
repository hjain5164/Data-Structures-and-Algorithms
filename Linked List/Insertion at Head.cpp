// Linked List - Insertion at the Head

#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node * next;
        node(int data){
            this->data = data;
            this->next = NULL;
        }
};

node* insertAtHead(node* head, int data){
    if(head == NULL){
        return new node(data);
    }
    node *temp = new node(data);
    temp->next = head;
    
    return temp;
}

void printLinkedList(node *head){
    while(head!= NULL){
        cout << head -> data << "\n";
        head = head->next;
    }
}

int main() {
    node* head = NULL;
    head = insertAtHead(head, 1);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 5);
    printLinkedList(head);
    
}

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

node* insertAtEnd(node* head, int data){
    if(head == NULL){
        return new node(data);
    }
    node *n = new node(data);
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    return head;
}

void printLinkedList(node *head){
    while(head!= NULL){
        cout << head -> data << "\n";
        head = head->next;
    }
}

int main() {
    node* head = NULL;
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);
    printLinkedList(head);
    
}
